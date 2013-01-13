#include "nuviewbase.h"
#include "dbrecordbuffer.h"
#include "connectionsqlite.h"

NuViewBase::NuViewBase(NuViewBase* parentView, DbRecordBuffer* pConfigRecord)
    : m_pParentView(parentView),
      m_pConfigRecord(pConfigRecord),
      m_dmFolder(NULL)
{
    if(pConfigRecord != NULL && pConfigRecord->count() > 0)
    {
        int aimKey = pConfigRecord->getKey();

        QString strFolderName;
        QString strViewName;
        QString sql1 = QString("select * from Configurations C1 where C1.parent = %1 AND C1.Name = 'FolderName' ").arg(aimKey);
        std::vector<DbRecordBuffer*> queryFolder;
        ConnectionSqlite::get()->ExecuteSql(sql1, queryFolder);
        if(queryFolder.size() == 1)
        {
            DbRecordBuffer* folderRec = queryFolder.at(0);
            strFolderName = folderRec->getField(4)->value();
            QString sql2 = QString("select * from Configurations C3 where C3.Type = 0 AND C3.Name = 'DBVIEW' AND C3.Parent IN (select AIMKEY from Configurations C2 where C2.Name = \"%1\")").arg(strFolderName);

            qDebug() << sql2;

            std::vector<DbRecordBuffer*> queryView;
            ConnectionSqlite::get()->ExecuteSql(sql2, queryView);

            if(queryFolder.size() == 1)
            {
                DbRecordBuffer* viewRec = queryView.at(0);
                strViewName = viewRec->getField(4)->value();
            }
        }

        qDebug() << "new folder" << strFolderName << "  " << strViewName;

        m_dmFolder = new DmFolder(strFolderName, strViewName);
    }
}
