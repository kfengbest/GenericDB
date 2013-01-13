#ifndef NUVIEWBASE_H
#define NUVIEWBASE_H

#include "connectionsqlite.h"
#include "dbrecordbuffer.h"
#include <QBoxLayout>
#include "dmfolder.h"

class NuViewBase
{
public:
    NuViewBase(NuViewBase* parentView, DbRecordBuffer* pConfigRecord);

    virtual void onLoadView() {}
    virtual QWidget* view() const {return NULL;}
    virtual QBoxLayout* layout() const {return NULL;}

    DmFolder* dmFolder() {return m_dmFolder;}
    DbRecordBuffer* configRecord() { return m_pConfigRecord;}

protected:

public: // TODO: temp
    NuViewBase* m_pParentView;
    DbRecordBuffer* m_pConfigRecord;
    DmFolder* m_dmFolder;
};

#endif // NUVIEWBASE_H
