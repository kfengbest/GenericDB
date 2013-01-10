#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QtGui>
#include <QtCore>
#include "dbrecordbuffer.h"
#include "dbfield.h"
#include "connectionsqlite.h"
#include "nuspliterview.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    NuViewBase(NULL,NULL),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QTreeWidget* treeWidget1 = new QTreeWidget();
    ui->horizontalLayout->addWidget(treeWidget1);

    QHBoxLayout *layout = new QHBoxLayout();
    ui->horizontalLayout->addLayout(layout);
    QListWidget* w2 = new QListWidget();
    layout->addWidget(w2);

    QVBoxLayout* mainframe1 = new QVBoxLayout();
    layout->addLayout(mainframe1);

    QTabWidget* tab1 = new QTabWidget();
    mainframe1->addWidget(tab1);
    QWidget* t11 = new QWidget();
    QWidget* t12 = new QWidget();

    tab1->addTab(t11, "Tab1");
    tab1->addTab(t12, "Tab2");


    QTabWidget* tab2 = new QTabWidget();
    mainframe1->addWidget(tab2);

    */




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

    QTreeWidgetItem* pItem0 = new QTreeWidgetItem(QStringList() << "root");
    ui->treeWidget->addTopLevelItem(pItem0);

    build(1,pItem0);



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

void MainWindow::build(int key, QTreeWidgetItem* p)
{

    QString sqlQuery = QString("select * from Configurations where parent=%1").arg(key);

//    qDebug() << sqlQuery;

    ConfigurationDatabaseQueryExecutor querier;
    ConnectionSqlite::get()->ExecuteSql(sqlQuery,&querier);

    QList<DbRecordBuffer*>* pRecords = NULL;
    pRecords = (QList<DbRecordBuffer*>*)querier.GetResult();
    if(pRecords != NULL)
    {
        int count = pRecords->size();
        for(int i = 0; i < count; i++)
        {
            DbRecordBuffer* pRecordBuffer = pRecords->at(i);

            DbField* pField = pRecordBuffer->getField(3);
            QString cap = pField->value();
            QTreeWidgetItem* pItem0 = new QTreeWidgetItem(QStringList() << cap);
            p->addChild(pItem0);

            build(pRecordBuffer->getKey(), pItem0);
        }
    }
}

