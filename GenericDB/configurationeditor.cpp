#include "configurationeditor.h"

#include <QHBoxLayout>

#include "dbrecordbuffer.h"
#include "dbfield.h"
#include "connectionsqlite.h"
#include <QtGui>
#include "Global.h"


ConfigurationEditor::ConfigurationEditor(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout;
    this->setLayout(layout);

    m_tree = new QTreeWidget(this);
    m_tree->setMaximumWidth(400);
    layout->addWidget(m_tree);

    QObject::connect(m_tree,SIGNAL(itemPressed(QTreeWidgetItem *, int)),this,SLOT(SlotItemClicked(
    QTreeWidgetItem *, int)));

    m_list = new QTableWidget(this);
    layout->addWidget(m_list);
    m_list->verticalHeader()->setVisible(false);
    m_list->setColumnCount(6);
    m_list->setRowCount(8);
    QStringList headers;
    headers << "AIMKEY" << "Layer" << "Type" << "Name" << "Value" << "Parent";
    m_list->setHorizontalHeaderLabels(headers);
    QObject::connect(m_list,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(itemChanged(QTableWidgetItem*)));


    this->setGeometry(100,100,400,400);


    QTreeWidgetItem* pItem0 = new QTreeWidgetItem(QStringList() << "root");
    pItem0->setData(0,Qt::UserRole,QVariant(int(1)));
    m_tree->addTopLevelItem(pItem0);

    build(1,pItem0);

}

void ConfigurationEditor::build(int key, QTreeWidgetItem* p)
{

    std::string sqlQuery = "select * from Configurations where parent=" + ConvertToString<int>(key);
    std::vector<DbRecordBuffer*> pRecords;
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,pRecords);

    if(pRecords.size() > 0)
    {
        int count = pRecords.size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords.at(i);

            DbField* pField = pRecordBuffer->getField(3);
            QString cap = QString::fromStdString(pField->value());
            QTreeWidgetItem* pItem0 = new QTreeWidgetItem(QStringList() << cap);
            pItem0->setData(0,Qt::UserRole,QVariant(int(pRecordBuffer->getKey())));

            p->addChild(pItem0);

            build(pRecordBuffer->getKey(), pItem0);
        }
    }
}

void ConfigurationEditor::SlotItemClicked(QTreeWidgetItem *item, int column)
{
     m_currentItem = item;

     if (qApp->mouseButtons() == Qt::LeftButton)
     {
        int aimKey = m_currentItem->data(0,Qt::UserRole).toInt();
        qDebug() << aimKey;

        DislayInList(aimKey);
     }
     else if (qApp->mouseButtons() == Qt::RightButton)
     {

         QMenu *cmenu = new QMenu(m_tree);

         QAction *addAction = cmenu->addAction("Add");
         connect(addAction, SIGNAL(triggered(bool)), this, SLOT(onAdd()));

         QAction *deleteAction = cmenu->addAction("Delete");
         connect(deleteAction, SIGNAL(triggered(bool)), this, SLOT(onDelete()));

         cmenu->exec(QCursor::pos());
     }
}

void ConfigurationEditor::onAdd()
{

    QTreeWidgetItem* childItem = new QTreeWidgetItem(QStringList() << "Item");
    m_currentItem->addChild(childItem);

}

void ConfigurationEditor::onDelete()
{

    if(m_currentItem->parent() == 0)
    {
        int i = m_tree->indexOfTopLevelItem(m_currentItem);
        m_currentItem->takeChildren();
        m_tree->takeTopLevelItem(i);
    }
    else
    {
        m_currentItem->parent()->removeChild(m_currentItem);
    }

}

void ConfigurationEditor::DislayInList(int aimkey)
{
    m_list->clear();

    std::string sqlQuery = "select * from Configurations where aimkey=" + ConvertToString<int>(aimkey);
    std::vector<DbRecordBuffer*> pRecords;
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,pRecords);

    if(pRecords.size() > 0)
    {
        int count = pRecords.size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords.at(i);

            int fieldCounts = pRecordBuffer->count();
            for(int j = 0; j < fieldCounts; j++)
            {
                DbField* pField = pRecordBuffer->getField(j);
                QString strValue = QString::fromStdString(pField->value());
                qDebug() << strValue;

                QTableWidgetItem* item = new QTableWidgetItem(strValue);

                m_list->setItem(i,j, item);
            }

        }
    }
}

void ConfigurationEditor::itemChanged(QTableWidgetItem *item)
{
    QString newValue = item->text();
    qDebug() << newValue;

   // QString sql = QString("update Configurations set Name = \"%1\"").arg(newValue);
    //ConnectionSqlite::get()->ExecuteSql(sql);
}
