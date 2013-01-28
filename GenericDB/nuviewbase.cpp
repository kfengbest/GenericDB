#include "nuviewbase.h"
#include "dbrecordbuffer.h"
#include "connectionsqlite.h"
#include "Global.h"

NuViewBase::NuViewBase(NuViewBase* parentView, DbRecordBuffer* pConfigRecord)
    : m_pParentView(parentView),
      m_pConfigRecord(pConfigRecord),
      m_dmFolder(NULL)
{
    if(pConfigRecord != NULL && pConfigRecord->count() > 0)
    {
        int aimKey = pConfigRecord->getKey();

        std::string strFolderName;
        std::string strViewName;
        std::string sql1 = "select * from Configurations C1 where C1.parent = " + ConvertToString<int>(aimKey) + " AND C1.Name = \'FolderName\' ";
        std::vector<DbRecordBuffer*> queryFolder;
        ConnectionSqlite::get()->ExecuteSql(sql1, queryFolder);
        if(queryFolder.size() == 1)
        {
            DbRecordBuffer* folderRec = queryFolder.at(0);
            strFolderName = folderRec->getField(4)->value();
            std::string sql2 = "select * from Configurations C3 where C3.Type = 0 AND C3.Name = 'DBVIEW' AND C3.Parent IN (select AIMKEY from Configurations C2 where C2.Name = \' " + strFolderName + "\')";  //.arg();

            std::vector<DbRecordBuffer*> queryView;
            ConnectionSqlite::get()->ExecuteSql(sql2, queryView);

            if(queryFolder.size() == 1)
            {
                DbRecordBuffer* viewRec = queryView.at(0);
                strViewName = viewRec->getField(4)->value();
            }
        }

      //  qDebug() << "new folder" << strFolderName << "  " << strViewName;

        m_dmFolder = new DmFolder(strFolderName, strViewName);
    }
}
