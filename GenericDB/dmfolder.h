#ifndef DMFOLDER_H
#define DMFOLDER_H

#include <QString>
#include <vector>


class DbRecordBuffer;
class DbView;

class DmFolder
{
public:
    DmFolder(const QString& folderName, const QString& dbViewName);

    DbRecordBuffer* getColumnType() {return m_pColumnType;}

    int recordsCount() const;
    DbRecordBuffer* getRecordAt(int index);

    QString dbViewName() const {return m_dbViewName;}
    DbView* dbView() const {return m_dbView;}


private:
    void init();

private:

    QString m_folderName;
    QString m_dbViewName;

    DbRecordBuffer* m_pColumnType;
    DbView* m_dbView;

    std::vector<DbRecordBuffer*> m_records;

};

#endif // DMFOLDER_H
