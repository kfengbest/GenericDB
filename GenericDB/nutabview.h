#ifndef NUTABVIEW_H
#define NUTABVIEW_H

#include "nuviewbase.h"
#include <QTabWidget>

class NuTabView : public NuViewBase
{
public:
    NuTabView(NuViewBase* parentView, DmFolder* pData);

    virtual QWidget* view() const {return m_widge;}
    virtual void onLoadView();

private:
    QTabWidget* m_widge;
};

#endif // NUTABVIEW_H
