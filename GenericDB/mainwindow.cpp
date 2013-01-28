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

    m_mainLayout = new QHBoxLayout(ui->centralWidget);
    ui->centralWidget->setLayout(m_mainLayout);

    std::string sqlQuery2 = "select * from Configurations where 1=0";
    DbRecordBuffer* pRB = new DbRecordBuffer();
    ConnectionSqlite::get()->buildRecordBufferTypes(sqlQuery2, pRB);
    delete pRB;

    std::vector<DbRecordBuffer*> pRecords;
    std::string sqlQuery = "select * from Configurations where AIMKEY=101";
    ConnectionSqlite::get()->ExecuteSql(sqlQuery, pRecords);

    if(pRecords.size() > 0)
    {
            DbRecordBuffer* pRecordBuffer = pRecords.at(0);
            m_pRootView = new NuSpliterView(m_mainLayout, pRecordBuffer);
            m_pRootView->onLoadView();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

QBoxLayout* MainWindow::layout() const
{
    return m_mainLayout;
}


void MainWindow::on_actionConfiguration_triggered()
{

}

void MainWindow::on_actionConfiguration_2_triggered()
{
    ConfigurationEditor* pEditor = new ConfigurationEditor();
    pEditor->show();
}
