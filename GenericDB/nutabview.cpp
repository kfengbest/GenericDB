#include "nutabview.h"
#include "nulistview.h"

NuTabView::NuTabView(NuViewBase* parentView, DmFolder* pData)
    : NuViewBase(parentView, pData)
{
    m_widge = new QTabWidget;

}

void NuTabView::onLoadView()
{
    DmFolder* pFolder = new DmFolder("Folder_XRef_Parent_Doc", "View_XRef_Parent_Project");
    NuListView* list = new NuListView(this, pFolder);
    list->onLoadView();
    m_widge->addTab(list->view(), "tab1");
}
