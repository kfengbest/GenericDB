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
class QHBoxLayout;

class MainWindow : public QMainWindow,
                   public NuViewBase
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    virtual QBoxLayout* layout() const;

private slots:

    void on_actionConfiguration_triggered();

    void on_actionConfiguration_2_triggered();

private:
    Ui::MainWindow *ui;
    NuSpliterView* m_pRootView;

    QHBoxLayout* m_mainLayout;

};



#endif // MAINWINDOW_H
