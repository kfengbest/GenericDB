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
    init();
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

    QString sql = QString("select * from %1").arg(m_dbViewName);
    ConnectionSqlite::get()->ExecuteSql(sql, m_records);

    qDebug() << "DmFolder::ctor " << sql;

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


