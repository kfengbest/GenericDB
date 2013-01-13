#include "nutreeview.h"

#include <QTreeWidget>
#include <nutreeitem.h>

NuTreeView::NuTreeView(NuViewBase* parentView, DmFolder* pData)
    : NuViewBase(parentView, pData)
{
    m_tree = new QTreeWidget;
    m_tree->setMaximumWidth(250);
}

void NuTreeView::onLoadView()
{

}
