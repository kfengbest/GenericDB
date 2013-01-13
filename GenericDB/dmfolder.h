#ifndef DMFOLDER_H
#define DMFOLDER_H

#include <QString>
#include <map>


class DbRecordBuffer;
class DbView;

typedef std::map<int,DbRecordBuffer*> RecordsMap;

class DmFolder
{
public:
    DmFolder(const QString& folderName, const QString& dbViewName);

    DbRecordBuffer* getRecordByKey(int aimKey);
    DbRecordBuffer* getRecordAt(int index);

    int recordsCount() const;
    const RecordsMap& records() {return m_recordsMap;}

    static DmFolder* getFolderBy(const QString& folderName, const QString& viewName);
private:
    void init();

private:

    QString m_folderName;
    QString m_dbViewName;

    DbRecordBuffer* m_pColumnType;
    DbView* m_dbView;

    RecordsMap m_recordsMap;

    typedef std::map<QString, DmFolder*> FolderMap;
    static FolderMap m_sFolders;
};

#endif // DMFOLDER_H
