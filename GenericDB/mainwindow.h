#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class sqlite3;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    sqlite3* mpDatabase;
    bool ConnectToDatabase(const QString& path);
    void CloseDatabase();


};


#endif // MAINWINDOW_H
