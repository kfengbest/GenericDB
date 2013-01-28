#include "nuspliterview.h"

#include "dbrecordbuffer.h"
#include "nutreeview.h"
#include "nulistview.h"
#include "nutabview.h"


NuSpliterView::NuSpliterView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    if(pData != NULL)
    {
        DbField* pFieldValue = pData->getField(4);
        QString strValue = QString::fromLocal8Bit(pFieldValue->value().c_str());
        if(strValue == "H")
            m_pLayout = new QHBoxLayout;
        else if(strValue == "V")
            m_pLayout = new QVBoxLayout;
    }
}

NuSpliterView::NuSpliterView(QBoxLayout* layout, DbRecordBuffer* pData)
    : NuViewBase(NULL, pData)
{
    m_pLayout = layout;
}

void NuSpliterView::onLoadView()
{
    if(this->configRecord() == NULL)
        return;

    std::vector<DbRecordBuffer*> pRecords;
    std::string sqlQuery = "select * from Configurations where parent=" + this->configRecord()->getKey();
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,pRecords);

    if(pRecords.size() > 0)
    {
        int count = pRecords.size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords.at(i);
            DbField* pField = pRecordBuffer->getField(3);
            QString name = QString::fromLocal8Bit(pField->value().c_str());
            if(name == "Win1" || name == "Win2")
            {
                DbField* pFieldValue = pRecordBuffer->getField(4);
                QString strValue = QString::fromLocal8Bit(pFieldValue->value().c_str());

                //qDebug() << "pFieldValue " << strValue;

                if(strValue == "Tree")
                {
                    NuViewBase* tree = new NuTreeView(this, pRecordBuffer);
                    m_pLayout->addWidget(tree->view());
                    tree->onLoadView();
                }
                else if(strValue == "Spliter")
                {

                    std::vector<DbRecordBuffer*> childRecs;
                    std::string sqlQuery = "select * from Configurations where parent=" + pRecordBuffer->getKey();
                    ConnectionSqlite::get()->ExecuteSql(sqlQuery,childRecs);

                    if(childRecs.size() == 1)
                    {
                        DbRecordBuffer* pSpliterBuf = childRecs.at(0);
                        int id = pSpliterBuf->getKey();
                        NuSpliterView* spliter = new NuSpliterView(this, pSpliterBuf);
                        m_pLayout->addLayout(spliter->layout());
                        spliter->onLoadView();
                    }
                }
                else if(strValue == "List")
                {
                    NuListView* list = new NuListView(this, pRecordBuffer);
                    m_pLayout->addWidget(list->view());
                    list->onLoadView();
                }
                else if(strValue == "Tab")
                {
                    NuTabView* tab = new NuTabView(this, pRecordBuffer);
                    m_pLayout->addWidget(tab->view());
                    tab->onLoadView();
                }

            }

        }
    }
}
