#ifndef DMFOLDER_H
#define DMFOLDER_H

#include <QString>
#include <map>

class DbRecordBuffer;
class DbView;

class DmFolder
{
public:
    DmFolder(const QString& folderName, const QString& dbViewName);

    DbRecordBuffer* getRecordByKey(int aimKey);

    void init();

private:
    typedef std::map<int,DbRecordBuffer*> RecordsMap;

    QString m_folderName;
    QString m_dbViewName;

    DbRecordBuffer* m_pColumnType;
    DbView* m_dbView;

    RecordsMap m_recordsMap;
};

#endif // DMFOLDER_H
