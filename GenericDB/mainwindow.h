#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "nuviewbase.h"


namespace Ui {
class MainWindow;
}


class QTreeWidgetItem;
class ConnectionSqlite;
class NuSpliterView;

class MainWindow : public QMainWindow,
                   public NuViewBase
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    virtual QBoxLayout* layout() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    NuSpliterView* m_pRootView;

    void build(int key, QTreeWidgetItem *p);


};



#endif // MAINWINDOW_H
