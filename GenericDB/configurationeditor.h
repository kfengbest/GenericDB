#ifndef CONFIGURATIONEDITOR_H
#define CONFIGURATIONEDITOR_H

#include <QWidget>
#include <QTreeWidget>
#include <QTableWidget>

class QTreeWidgetItem;

class ConfigurationEditor : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigurationEditor(QWidget *parent = 0);
    
    void build(int key, QTreeWidgetItem* p);

    void DislayInList(int aimkey);

signals:
    
public slots:
    void SlotItemClicked(QTreeWidgetItem *item, int column);
    void onAdd();
    void onDelete();

    void itemChanged(QTableWidgetItem *item);

private:

    QTreeWidget* m_tree;
    QTableWidget* m_list;

    QTreeWidgetItem* m_currentItem;
};

#endif // CONFIGURATIONEDITOR_H
