#include "nutabview.h"

NuTabView::NuTabView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_widge = new QTabWidget;

}

void NuTabView::onLoadView()
{
    QWidget* tab1 = new QWidget;
    m_widge->addTab(tab1, "tab1");

    QWidget* tab2 = new QWidget;
    m_widge->addTab(tab2, "tab2");

    QWidget* tab3 = new QWidget;
    m_widge->addTab(tab3, "tab3");
}
