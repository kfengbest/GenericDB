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

bool MainWindow::ExecuteSql(const QString& sql, DatabaseQueryExecutor* executor)
{
    if (mpDatabase == NULL || sql.isEmpty())
        return false;

    QByteArray sqlByteArray = sql.toUtf8();

    int len = sqlByteArray.length();
    char* sSql = new char[len + 1];
    sSql[len] = 0;

#ifdef AD_OS_WIN
    strcpy_s(sSql, len+1, sqlByteArray.constData());
#else
    strcpy(sSql, sqlByteArray.constData());
#endif

    bool bRet = true;
    sqlite3_stmt* pStmt = NULL;
    const char* pTail = NULL;
    int rc = sqlite3_prepare(mpDatabase, sSql, len, &pStmt, &pTail);
    Q_ASSERT(rc == SQLITE_OK);
    if (rc == SQLITE_OK)
    {
        rc = sqlite3_step(pStmt);
        Q_ASSERT(rc == SQLITE_DONE || rc == SQLITE_ROW);
        if (rc == SQLITE_DONE)
            bRet = true;

        while (rc == SQLITE_ROW)
        {
            if (executor == NULL)
            {
                bRet = false;
                break;
            }

            executor->BuildResult(pStmt);
            rc = sqlite3_step(pStmt);
        }
    }
    else
        bRet = false;

    sqlite3_finalize(pStmt);
    delete []sSql;

    return bRet;
}


SingleColumnDatabaseQueryExecutor::SingleColumnDatabaseQueryExecutor()
{
    mpResult = new QString();
}

SingleColumnDatabaseQueryExecutor::~SingleColumnDatabaseQueryExecutor()
{
    if (mpResult != NULL)
    {
        delete (QString*) mpResult;
        mpResult = NULL;
    }
}

void SingleColumnDatabaseQueryExecutor::BuildResult(sqlite3_stmt* pStmt)
{
    if (pStmt == NULL)
        return;

    int count = sqlite3_column_count(pStmt);
    Q_ASSERT(count == 1);
    if (count == 1)
        *((QString*)mpResult) = ((QString*)mpResult)->append(QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 0)));

}

void SingleColumnDatabaseQueryExecutor::ClearResult()
{
    *((QString*)mpResult) = "";
}

void MainWindow::on_pushButton_clicked()
{

    QString sqlInsert = QString("insert into Configurations values(20,0,0,\"Folder\",\"Name\", 1)");
    ExecuteSql(sqlInsert);


    QString sqlDelete = QString("delete from Configurations where AIMKEY=20");
    ExecuteSql(sqlDelete);
}
