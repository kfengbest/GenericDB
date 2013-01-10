#include "nutreeview.h"

#include <QTreeWidget>
#include <QTreeWidgetItem>

NuTreeView::NuTreeView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_tree = new QTreeWidget;

    QTreeWidgetItem* item0 = new QTreeWidgetItem(QStringList() << "Root0");
    m_tree->addTopLevelItem(item0);
}

void NuTreeView::onLoadView()
{

}
