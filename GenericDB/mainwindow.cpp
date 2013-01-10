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

    /*
    QHBoxLayout *layout0 = new QHBoxLayout();
    ui->horizontalLayout->addLayout(layout0);

    QTreeWidget* treeWidget1 = new QTreeWidget();
    layout0->addWidget(treeWidget1);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout0->addLayout(layout1);

    QListWidget* w2 = new QListWidget();
    layout1->addWidget(w2);

    QVBoxLayout* mainframe1 = new QVBoxLayout();
    layout1->addLayout(mainframe1);

    QTabWidget* tab1 = new QTabWidget();
    mainframe1->addWidget(tab1);
    QWidget* t11 = new QWidget();
    QWidget* t12 = new QWidget();

    tab1->addTab(t11, "Tab1");
    tab1->addTab(t12, "Tab2");

    QTabWidget* tab2 = new QTabWidget();
    mainframe1->addWidget(tab2);

    QWidget* t21 = new QWidget();
    tab2->addTab(t21, "Tab1");
    */


    QString sqlQuery = QString("select * from Configurations where AIMKEY=101");
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,&m_querier);

    QList<DbRecordBuffer*>* pRecords = NULL;
    pRecords = (QList<DbRecordBuffer*>*)m_querier.GetResult();
    if(pRecords != NULL)
    {
            DbRecordBuffer* pRecordBuffer = pRecords->at(0);
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

