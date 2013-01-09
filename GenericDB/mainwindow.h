#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

struct sqlite3;
struct sqlite3_stmt;
class DatabaseQueryExecutor;


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    sqlite3* mpDatabase;
    bool ConnectToDatabase(const QString& path);
    void CloseDatabase();
    virtual bool ExecuteSql(const QString& sql, DatabaseQueryExecutor* executor = NULL);


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

#endif // MAINWINDOW_H
