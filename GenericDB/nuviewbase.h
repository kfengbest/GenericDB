#ifndef NUVIEWBASE_H
#define NUVIEWBASE_H

#include "connectionsqlite.h"
#include "dbrecordbuffer.h"
#include <QBoxLayout>

class NuViewBase
{
public:
    NuViewBase(NuViewBase* parentView, DbRecordBuffer* pData);

    virtual void onLoadView() {}
    virtual QWidget* view() const {return NULL;}
    virtual QBoxLayout* layout() const {return NULL;}

protected:

public: // TODO: temp
    NuViewBase* m_pParentView;
    DbRecordBuffer* m_pRecord;
    ConfigurationDatabaseQueryExecutor m_querier;

};

#endif // NUVIEWBASE_H
