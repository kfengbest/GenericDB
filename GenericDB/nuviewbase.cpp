#include "nuviewbase.h"
#include "dbrecordbuffer.h"

NuViewBase::NuViewBase(NuViewBase* parentView, DbRecordBuffer* pData)
    : m_pParentView(parentView),
      m_pRecord(pData)
{
}
