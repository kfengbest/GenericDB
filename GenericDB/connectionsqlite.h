#ifndef CONNECTIONSQLITE_H
#define CONNECTIONSQLITE_H

#include <QtCore>
#include <QtGui>
#include <vector>

struct sqlite3;
struct sqlite3_stmt;
class DatabaseQueryExecutor;
class DbRecordBuffer;

class ConnectionSqlite
{
public:
    ConnectionSqlite();
    ~ConnectionSqlite();

    static ConnectionSqlite* get();

    bool ExecuteSql(const QString& sql);
    bool ExecuteSql(const QString& sql, std::vector<DbRecordBuffer*>& results);

    bool buildRecordBufferTypes(const QString& sql, DbRecordBuffer* pRecordBuffer);

private:
    sqlite3* mpDatabase;
    bool ConnectToDatabase(const QString& path);
    void CloseDatabase();

    void buildRowRecord(sqlite3_stmt* pStmt, DbRecordBuffer* pRecordBuffer);
};


#endif // CONNECTIONSQLITE_H
