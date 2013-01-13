#include "dmfolder.h"
#include "dbview.h"
#include "dbrecordbuffer.h"
#include <algorithm>

DmFolder::DmFolder(const QString &folderName, const QString &dbViewName)
    : m_folderName(folderName),
      m_dbViewName(dbViewName),
      m_pRecordBuffer(NULL),
      m_dbView(NULL)
{
}

void DmFolder::init()
{

}

DbRecordBuffer* DmFolder::getRecordByKey(int aimKey)
{
//    RecordsMap::iterator it = std::find(m_recordsMap.begin(), m_recordsMap::end(), aimKey);
//    if(it == m_recordsMap.end())
//    {

//    }
}
