#ifndef CONFIGURATIONEDITOR_H
#define CONFIGURATIONEDITOR_H

#include <QWidget>
#include <QTreeWidget>
#include <QListWidget>

class QTreeWidgetItem;

class ConfigurationEditor : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigurationEditor(QWidget *parent = 0);
    
    void build(int key, QTreeWidgetItem* p);

signals:
    
public slots:
    
private:

    QTreeWidget* m_tree;
    QListWidget* m_list;
};

#endif // CONFIGURATIONEDITOR_H
