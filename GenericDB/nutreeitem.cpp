#include "nutreeitem.h"

NuTreeItem::NuTreeItem(int aimKey, QWidget *parent)
    : m_aimKey(aimKey)
{
    m_pItem = new QTreeWidgetItem();

    m_pItem->setText(0,"AAA");

}


