#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QtGui>
#include <QtCore>
#include "dbrecordbuffer.h"
#include "dbfield.h"
#include "connectionsqlite.h"
#include "nuspliterview.h"
#include "configurationeditor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    NuViewBase(NULL,NULL),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString sqlQuery2 = QString("select * from Configurations where 1=0");
    DbRecordBuffer* pRB = new DbRecordBuffer();
    ConnectionSqlite::get()->buildRecordBufferTypes(sqlQuery2, pRB);
    delete pRB;

    std::vector<DbRecordBuffer*> pRecords;
    QString sqlQuery = QString("select * from Configurations where AIMKEY=101");
    ConnectionSqlite::get()->ExecuteSql(sqlQuery, pRecords);

    if(pRecords.size() > 0)
    {
            DbRecordBuffer* pRecordBuffer = pRecords.at(0);
            m_pRootView = new NuSpliterView(ui->horizontalLayout, pRecordBuffer);
            m_pRootView->onLoadView();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

QBoxLayout* MainWindow::layout() const
{
    return ui->horizontalLayout;
}


void MainWindow::on_pushButton_clicked()
{

//    QString sqlInsert = QString("insert into Configurations values(20,0,0,\"Folder\",\"Name\", 1)");
//    ExecuteSql(sqlInsert);


//    QString sqlDelete = QString("delete from Configurations where AIMKEY=20");
//    ExecuteSql(sqlDelete);


    ConfigurationEditor* pEditor = new ConfigurationEditor();
    pEditor->show();




}

