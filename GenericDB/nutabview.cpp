#include "nutabview.h"
#include "nulistview.h"
#include "nuspliterview.h"
#include "nulistview.h"
#include "nutreeview.h"

NuTabView::NuTabView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_widge = new QTabWidget;
}

void NuTabView::onLoadView()
{

    if(this->configRecord() == NULL)
        return;

    std::vector<DbRecordBuffer*> pRecords;
    QString sqlQuery = QString("select * from Configurations where parent=%1").arg(this->configRecord()->getKey());
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,pRecords);

    if(pRecords.size() > 0)
    {
        int count = pRecords.size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords.at(i);
            DbField* pField = pRecordBuffer->getField(3);
            QString name = pField->value();
            if(name.contains("Tab"))
            {
                DbField* pFieldValue = pRecordBuffer->getField(4);
                QString strValue = pFieldValue->value();

                qDebug() << "pFieldValue " << strValue;

                if(strValue == "Tree")
                {
                    NuViewBase* tree = new NuTreeView(this, pRecordBuffer);
                    tree->onLoadView();
                    m_widge->addTab(tree->view(), "Tab");

                }
                else if(strValue == "Spliter")
                {

                    std::vector<DbRecordBuffer*> childRecs;
                    QString sqlQuery = QString("select * from Configurations where parent=%1").arg(pRecordBuffer->getKey());
                    ConnectionSqlite::get()->ExecuteSql(sqlQuery,childRecs);

                    if(childRecs.size() == 1)
                    {
                        DbRecordBuffer* pSpliterBuf = childRecs.at(0);
                        int id = pSpliterBuf->getKey();
                        NuSpliterView* spliter = new NuSpliterView(this, pSpliterBuf);
                        spliter->onLoadView();
                        m_widge->addTab(spliter->view(), "Tab");

                    }
                }
                else if(strValue == "List")
                {
                    NuListView* list = new NuListView(this, pRecordBuffer);
                    list->onLoadView();
                    m_widge->addTab(list->view(), "Tab");

                }
                else if(strValue == "Tab")
                {
                    NuTabView* tab = new NuTabView(this, pRecordBuffer);
                    tab->onLoadView();
                    m_widge->addTab(tab->view(), "Tab");
                }

            }

        }
    }
}
