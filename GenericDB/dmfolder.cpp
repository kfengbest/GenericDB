#include "dmfolder.h"
#include "dbview.h"
#include "dbrecordbuffer.h"
#include <algorithm>
#include "connectionsqlite.h"

DmFolder::DmFolder(const QString &folderName, const QString &dbViewName)
    : m_folderName(folderName),
      m_dbViewName(dbViewName),
      m_pColumnType(NULL),
      m_dbView(NULL)
{
}

void DmFolder::init()
{
    if(m_pColumnType == NULL)
    {
        m_pColumnType = new DbRecordBuffer();
        QString sql = QString("select * from %1 where 1=0").arg(m_dbViewName);
        ConnectionSqlite::get()->buildRecordBufferTypes(sql, m_pColumnType);
    }

    if(m_dbView == NULL)
        m_dbView = new DbView();


}

DbRecordBuffer* DmFolder::getRecordByKey(int aimKey)
{
//    RecordsMap::iterator it = std::find(m_recordsMap.begin(), m_recordsMap::end(), aimKey);
//    if(it == m_recordsMap.end())
//    {

//    }
}
