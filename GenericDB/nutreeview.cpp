#include "nutreeview.h"

#include <QTreeWidget>
#include <nutreeitem.h>

NuTreeView::NuTreeView(NuViewBase* parentView, DmFolder* pData)
    : NuViewBase(parentView, pData)
{
    m_tree = new QTreeWidget;

//    QTreeWidgetItem* item0 = new QTreeWidgetItem(QStringList() << "Root0");
//    m_tree->addTopLevelItem(item0);

//    NuTreeItem* item0 = new NuTreeItem(1);
//    m_tree->addTopLevelItem(item0->item());
}

void NuTreeView::onLoadView()
{

}
