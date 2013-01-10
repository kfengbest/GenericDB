#include "configurationeditor.h"

#include <QHBoxLayout>

#include "dbrecordbuffer.h"
#include "dbfield.h"
#include "connectionsqlite.h"

ConfigurationEditor::ConfigurationEditor(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout;
    this->setLayout(layout);

    m_tree = new QTreeWidget();
    layout->addWidget(m_tree);

    QObject::connect(m_tree,SIGNAL(itemPressed(QTreeWidgetItem *, int)),this,SLOT(SlotItemClicked(
    QTreeWidgetItem *, int)));

    m_list = new QListWidget();
    layout->addWidget(m_list);

    this->setGeometry(100,100,400,400);


    QTreeWidgetItem* pItem0 = new QTreeWidgetItem(QStringList() << "root");
    pItem0->setData(0,Qt::UserRole,QVariant(int(1)));
    m_tree->addTopLevelItem(pItem0);

    build(1,pItem0);

}

void ConfigurationEditor::build(int key, QTreeWidgetItem* p)
{

    QString sqlQuery = QString("select * from Configurations where parent=%1").arg(key);

//    qDebug() << sqlQuery;

    ConfigurationDatabaseQueryExecutor querier;
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,&querier);

    QList<DbRecordBuffer*>* pRecords = NULL;
    pRecords = (QList<DbRecordBuffer*>*)querier.GetResult();
    if(pRecords != NULL)
    {
        int count = pRecords->size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords->at(i);

            DbField* pField = pRecordBuffer->getField(3);
            QString cap = pField->value();
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

    QString sqlQuery = QString("select * from Configurations where aimkey=%1").arg(aimkey);

    ConfigurationDatabaseQueryExecutor querier;
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,&querier);

    QList<DbRecordBuffer*>* pRecords = NULL;
    pRecords = (QList<DbRecordBuffer*>*)querier.GetResult();
    if(pRecords != NULL)
    {
        int count = pRecords->size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords->at(i);

            int fieldCounts = pRecordBuffer->count();
            for(int j = 0; j < fieldCounts; j++)
            {
                DbField* pField = pRecordBuffer->getField(j);
                QString strValue = pField->value();

                QListWidgetItem* item = new QListWidgetItem(m_list);
                item->setText(strValue);

                m_list->addItem(item);
            }

        }
    }
}

