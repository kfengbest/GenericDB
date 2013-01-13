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

// insert, delete, update.
bool ConnectionSqlite::ExecuteSql(const QString& sql)
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
//    Q_ASSERT(rc == SQLITE_OK);
    if (rc == SQLITE_OK)
    {
        rc = sqlite3_step(pStmt);
        Q_ASSERT(rc == SQLITE_DONE || rc == SQLITE_ROW);
        if (rc == SQLITE_DONE)
            bRet = true;
        else
            bRet = false;
    }
    else
        bRet = false;

    sqlite3_finalize(pStmt);
    delete []sSql;

    return bRet;
}

bool ConnectionSqlite::ExecuteSql(const QString& sql, std::vector<DbRecordBuffer*>& results)
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
//    Q_ASSERT(rc == SQLITE_OK);
    if (rc == SQLITE_OK)
    {

        rc = sqlite3_step(pStmt);
        Q_ASSERT(rc == SQLITE_DONE || rc == SQLITE_ROW);
        if (rc == SQLITE_DONE)
            bRet = true;

        while (rc == SQLITE_ROW)
        {
            DbRecordBuffer* pRecordBuffer = new DbRecordBuffer;
            results.push_back(pRecordBuffer);
            buildRowRecord(pStmt, pRecordBuffer);

            rc = sqlite3_step(pStmt);
        }
    }
    else
        bRet = false;

    sqlite3_finalize(pStmt);
    delete []sSql;

    return bRet;
}

// select * from xxx where 1=0;
bool ConnectionSqlite::buildRecordBufferTypes(const QString& sql, DbRecordBuffer* pRecordBuffer)
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
    //Q_ASSERT(rc == SQLITE_OK);
    if (rc == SQLITE_OK)
    {
        rc = sqlite3_step(pStmt);
        Q_ASSERT(rc == SQLITE_DONE || rc == SQLITE_ROW);
        bRet = true;

        buildRowRecord(pStmt, pRecordBuffer);

        bRet = true;
    }
    else
        bRet = false;

    sqlite3_finalize(pStmt);
    delete []sSql;

    return bRet;
}

void ConnectionSqlite::buildRowRecord(sqlite3_stmt* pStmt, DbRecordBuffer* pRecordBuffer)
{
    int count = sqlite3_column_count(pStmt);
    for(int i = 0; i < count; i++)
    {
        QString colName = QString::fromUtf8(sqlite3_column_name(pStmt, i));
        QString colType = QString::fromUtf8(sqlite3_column_decltype(pStmt, i));
        QString colValue = QString::fromUtf8((char*)sqlite3_column_blob(pStmt, i));

        //qDebug() << "Column Num:" << count << " Name: " << colName << " Type " << colType << " value: " << colValue;

        DbField* dbf = new DbField();
        dbf->name(colName);
        dbf->type(colType);
        dbf->value(colValue);
        pRecordBuffer->addField(dbf);

        // TODO: this is hard coded.
        if(colName == "AIMKEY" && i == 0)
            pRecordBuffer->setKey(colValue.toInt());

    }
}
