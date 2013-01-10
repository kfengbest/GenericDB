#ifndef NULISTVIEW_H
#define NULISTVIEW_H

#include "nuviewbase.h"

#include <QListWidget>

class NuListView : public NuViewBase
{
public:
    NuListView(NuViewBase* parentView, DbRecordBuffer* pData);

    virtual QWidget* view() const {return m_widge;}
    virtual void onLoadView();

private:
    QListWidget* m_widge;
};

#endif // NULISTVIEW_H
