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
        QString strValue = pFieldValue->value();
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
    if(m_pRecord == NULL)
        return;

    std::vector<DbRecordBuffer*> pRecords;
    QString sqlQuery = QString("select * from Configurations where parent=%1").arg(m_pRecord->getKey());
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,pRecords);

    if(pRecords.size() > 0)
    {
        int count = pRecords.size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords.at(i);
            DbField* pField = pRecordBuffer->getField(3);
            QString name = pField->value();
            if(name == "Win1" || name == "Win2")
            {
                DbField* pFieldValue = pRecordBuffer->getField(4);
                QString strValue = pFieldValue->value();

                qDebug() << "pFieldValue " << strValue;

                if(strValue == "Tree")
                {
                    NuViewBase* tree = new NuTreeView(this, pRecordBuffer);
                    m_pLayout->addWidget(tree->view());
                    tree->onLoadView();
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
