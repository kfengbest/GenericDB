#include "nulistview.h"


NuListView::NuListView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_widge = new QListWidget;

    QListWidgetItem* item0 = new QListWidgetItem("item0");
    m_widge->addItem(item0);
}

void NuListView::onLoadView()
{

}
