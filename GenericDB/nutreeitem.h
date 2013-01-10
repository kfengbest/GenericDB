#ifndef NUTREEITEM_H
#define NUTREEITEM_H

#include <QTreeWidgetItem>

class NuTreeItem : QObject
{
    Q_OBJECT
public:
    explicit NuTreeItem(int aimKey, QWidget *parent = 0);
    
    QTreeWidgetItem* item() { return m_pItem;}

signals:
    
public slots:

private:
    QTreeWidgetItem* m_pItem;
    int m_aimKey;
};

#endif // NUTREEITEM_H
