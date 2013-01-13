#ifndef NUVIEWBASE_H
#define NUVIEWBASE_H

#include "connectionsqlite.h"
#include "dbrecordbuffer.h"
#include <QBoxLayout>
#include "dmfolder.h"

class NuViewBase
{
public:
    NuViewBase(NuViewBase* parentView, DmFolder* pData);

    virtual void onLoadView() {}
    virtual QWidget* view() const {return NULL;}
    virtual QBoxLayout* layout() const {return NULL;}

    DmFolder* dmFolder() {return m_dmFolder;}

protected:

public: // TODO: temp
    NuViewBase* m_pParentView;
 //   DbRecordBuffer* m_pRecord;
    DmFolder* m_dmFolder;
};

#endif // NUVIEWBASE_H
