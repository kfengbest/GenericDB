#include "nutreeview.h"

#include <QTreeWidget>
#include <nutreeitem.h>

NuTreeView::NuTreeView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_tree = new QTreeWidget;
    m_tree->setMaximumWidth(250);

}

void NuTreeView::onLoadView()
{
    QTreeWidgetItem* rootItem = new QTreeWidgetItem(QStringList() << "MyFolders");
    m_tree->addTopLevelItem(rootItem);

    QTreeWidgetItem* itemProj = new QTreeWidgetItem(QStringList() << "Projects");
    QTreeWidgetItem* itemDocEng = new QTreeWidgetItem(QStringList() << "Engineering Document");
    QTreeWidgetItem* rootDocOff = new QTreeWidgetItem(QStringList() << "Office Document");

    QTreeWidgetItem* itemPerson = new QTreeWidgetItem(QStringList() << "Person");
    QTreeWidgetItem* itemOrg = new QTreeWidgetItem(QStringList() << "Orgnization");

    rootItem->addChild(itemProj);
    rootItem->addChild(itemDocEng);
    rootItem->addChild(rootDocOff);
    rootItem->addChild(itemPerson);
    rootItem->addChild(itemOrg);

    m_tree->expandAll();
}
