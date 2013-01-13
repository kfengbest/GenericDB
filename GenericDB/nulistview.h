#ifndef NULISTVIEW_H
#define NULISTVIEW_H

#include "nuviewbase.h"

#include <QTableWidget>

class NuListView : public NuViewBase
{
public:
    NuListView(NuViewBase* parentView, DmFolder* pData);

    virtual QWidget* view() const {return m_widget;}
    virtual void onLoadView();

private:
    QTableWidget* m_widget;
};

#endif // NULISTVIEW_H
