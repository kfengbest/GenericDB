#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class QTreeWidgetItem;
class ConnectionSqlite;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ConnectionSqlite* m_dbConnection;

    void build(int key, QTreeWidgetItem *p);


};



#endif // MAINWINDOW_H
