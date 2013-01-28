#include "dmfolder.h"
#include "dbview.h"
#include "dbrecordbuffer.h"
#include <algorithm>
#include "connectionsqlite.h"

DmFolder::DmFolder(const std::string& folderName, const std::string& dbViewName)
    : m_folderName(folderName),
      m_dbViewName(dbViewName),
      m_pColumnType(NULL),
      m_dbView(NULL)
{
    init();
}

void DmFolder::init()
{
    if(m_pColumnType == NULL)
    {
        m_pColumnType = new DbRecordBuffer();
        std::string sql = "select * from " + m_dbViewName  + "where 1=0";
        ConnectionSqlite::get()->buildRecordBufferTypes(sql.c_str(), m_pColumnType);
    }

    if(m_dbView == NULL)
        m_dbView = new DbView();

    std::string sql = "select * from " + m_dbViewName;
    ConnectionSqlite::get()->ExecuteSql(sql.c_str(), m_records);

}

DbRecordBuffer* DmFolder::getRecordAt(int index)
{
    DbRecordBuffer* pRec = m_records.at(index);
    return pRec;
}


int DmFolder::recordsCount() const
{
    return m_records.size();
}


