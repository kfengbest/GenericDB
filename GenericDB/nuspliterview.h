#ifndef NUSPLITERVIEW_H
#define NUSPLITERVIEW_H

#include "nuviewbase.h"
#include <qboxlayout.h>

class DbRecordBuffer;
class NuSpliterView : public NuViewBase
{
public:
    NuSpliterView(NuViewBase* parentView, DbRecordBuffer* pData);
    NuSpliterView(QBoxLayout* pLayout, DbRecordBuffer* pData);

    virtual QBoxLayout* layout() const {return m_pLayout;}
    virtual void onLoadView();

protected:

private:
    QBoxLayout* m_pLayout;
};

#endif // NUSPLITERVIEW_H
