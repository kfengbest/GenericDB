#include "nuviewbase.h"
#include "dbrecordbuffer.h"

NuViewBase::NuViewBase(NuViewBase* parentView, DmFolder* pData)
    : m_pParentView(parentView),
      m_dmFolder(pData)
{
}
