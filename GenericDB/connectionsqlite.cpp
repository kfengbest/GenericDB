#include "connectionsqlite.h"

#include "sqlite3.h"
#include "dbrecordbuffer.h"
#include "dbfield.h"

ConnectionSqlite::ConnectionSqlite()
{
    QString path("/Users/fengka/Src/GenericDB/DBScript/Compass.db");
    ConnectToDatabase(path);
}

ConnectionSqlite::~ConnectionSqlite()
{
    CloseDatabase();
}

 ConnectionSqlite* ConnectionSqlite::get()
 {
    static ConnectionSqlite theOnlyOne;
    return &theOnlyOne;
 }


bool ConnectionSqlite::ConnectToDatabase(const QString& path)
{
    int result = sqlite3_open(path.toAscii().constData(), &mpDatabase);
    if (result == SQLITE_OK)
        return true;

    sqlite3_close(mpDatabase);
    mpDatabase = NULL;
    return false;
}

void ConnectionSqlite::CloseDatabase()
{
    if (mpDatabase != NULL)
    {
        sqlite3_close(mpDatabase);
        mpDatabase = NULL;
    }
}

bool ConnectionSqlite::ExecuteSql(const QString& sql, DatabaseQueryExecutor* executor)
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


ConfigurationDatabaseQueryExecutor::ConfigurationDatabaseQueryExecutor()
{
    mpResult = new QList<DbRecordBuffer*>();
}

ConfigurationDatabaseQueryExecutor::~ConfigurationDatabaseQueryExecutor()
{
    if (mpResult != NULL)
    {
        delete (QList<DbRecordBuffer*>*)mpResult;
        mpResult = NULL;
    }
}

void ConfigurationDatabaseQueryExecutor::BuildResult(sqlite3_stmt* pStmt)
{
    if (pStmt == NULL)
        return;

    int count = sqlite3_column_count(pStmt);
    {
        DbRecordBuffer* pRecord = new DbRecordBuffer();

        QString str0 = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 0));
        pRecord->setKey(str0.toInt());

        DbField* dbf0 = new DbField();
        dbf0->name("AIMKEY");
        dbf0->value(str0);
        pRecord->addField(dbf0);

        QString str1 = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 1));
        DbField* dbf1 = new DbField();
        dbf1->name("Layer");
        dbf1->value(str1);
        pRecord->addField(dbf1);

        QString str2 = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 2));
        DbField* dbf2 = new DbField();
        dbf2->name("Type");
        dbf2->value(str2);
        pRecord->addField(dbf2);

        QString str3 = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 3));
        DbField* dbf3 = new DbField();
        dbf3->name("Name");
        dbf3->value(str3);
        pRecord->addField(dbf3);


        QString str4 = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 4));
        DbField* dbf4 = new DbField();
        dbf4->name("Value");
        dbf4->value(str4);
        pRecord->addField(dbf4);

        QString str5 = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, 5));
        DbField* dbf5 = new DbField();
        dbf5->name("Parent");
        dbf5->value(str5);
        pRecord->addField(dbf5);

        qDebug() << str0 << " " << str1 << " " << str2 << "  " << str3 << " " << str4 << " " << str5;

        ((QList<DbRecordBuffer*>*)mpResult)->append(pRecord);
    }
}

