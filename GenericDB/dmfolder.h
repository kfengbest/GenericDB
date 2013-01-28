#ifndef DMFOLDER_H
#define DMFOLDER_H

#include <string>
#include <vector>


class DbRecordBuffer;
class DbView;

class DmFolder
{
public:
    DmFolder(const std::string& folderName, const std::string& dbViewName);

    DbRecordBuffer* getColumnType() {return m_pColumnType;}

    int recordsCount() const;
    DbRecordBuffer* getRecordAt(int index);

    std::string dbViewName() const {return m_dbViewName;}
    DbView* dbView() const {return m_dbView;}


private:
    void init();

private:

    std::string m_folderName;
    std::string m_dbViewName;

    DbRecordBuffer* m_pColumnType;
    DbView* m_dbView;

    std::vector<DbRecordBuffer*> m_records;

};

#endif // DMFOLDER_H
