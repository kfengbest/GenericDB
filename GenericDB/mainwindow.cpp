#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlite3.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path("/Users/fengka/Src/GenericDB/DBScript/Compass.db");

    this->ConnectToDatabase(path);


}

MainWindow::~MainWindow()
{
    CloseDatabase();

    delete ui;
}

bool MainWindow::ConnectToDatabase(const QString& path)
{
    int result = sqlite3_open(path.toAscii().constData(), &mpDatabase);
    if (result == SQLITE_OK)
        return true;

    sqlite3_close(mpDatabase);
    mpDatabase = NULL;
    return false;
}

void MainWindow::CloseDatabase()
{
    if (mpDatabase != NULL)
    {
        sqlite3_close(mpDatabase);
        mpDatabase = NULL;
    }
}
