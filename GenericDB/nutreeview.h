#ifndef NUTREEVIEW_H
#define NUTREEVIEW_H

#include "nuviewbase.h"

#include <QTreeWidget>

class NuTreeView : public NuViewBase
{
public:
    NuTreeView(NuViewBase* parentView, DbRecordBuffer *pData);

    virtual QWidget* view() const {return m_tree;}
    virtual void onLoadView();

protected:

private:
    QTreeWidget* m_tree;
};

#endif // NUTREEVIEW_H
