#include "nulistview.h"


NuListView::NuListView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_widget = new QTableWidget;
    m_widget->verticalHeader()->setVisible(false);

}

void NuListView::onLoadView()
{

}
