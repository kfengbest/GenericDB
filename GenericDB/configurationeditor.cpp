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

    m_list = new QListWidget();
    layout->addWidget(m_list);

    this->setGeometry(100,100,400,400);


    QTreeWidgetItem* pItem0 = new QTreeWidgetItem(QStringList() << "root");
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
            p->addChild(pItem0);

            build(pRecordBuffer->getKey(), pItem0);
        }
    }
}

