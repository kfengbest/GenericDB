#ifndef CONNECTIONSQLITE_H
#define CONNECTIONSQLITE_H

#include <QtCore>
#include <QtGui>

struct sqlite3;
struct sqlite3_stmt;
class DatabaseQueryExecutor;

class ConnectionSqlite
{
public:
    ConnectionSqlite();
    ~ConnectionSqlite();

    static ConnectionSqlite* get();

    virtual bool ExecuteSql(const QString& sql, DatabaseQueryExecutor* executor = NULL);

private:
    sqlite3* mpDatabase;
    bool ConnectToDatabase(const QString& path);
    void CloseDatabase();

};


class DatabaseQueryExecutor
{
public:
    virtual ~DatabaseQueryExecutor(){};
    virtual void BuildResult(sqlite3_stmt* pStmt) = 0;
    void* GetResult() {return mpResult;}

protected:
    void *mpResult;
};

class SingleColumnDatabaseQueryExecutor : public DatabaseQueryExecutor
{
public:
    SingleColumnDatabaseQueryExecutor();
    ~SingleColumnDatabaseQueryExecutor();
    virtual void BuildResult(sqlite3_stmt* pStmt);
    void ClearResult();
};

class ConfigurationDatabaseQueryExecutor : public DatabaseQueryExecutor
{
public:
    ConfigurationDatabaseQueryExecutor();
    ~ConfigurationDatabaseQueryExecutor();
    virtual void BuildResult(sqlite3_stmt* pStmt);
};

#endif // CONNECTIONSQLITE_H
