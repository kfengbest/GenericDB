#include "nulistview.h"

#include <connectionsqlite.h>

NuListView::NuListView(NuViewBase* parentView, DmFolder* pData)
    : NuViewBase(parentView, pData)
{
    m_widget = new QTableWidget;
    m_widget->verticalHeader()->setVisible(false);

    DbRecordBuffer* pColumnType = this->dmFolder()->getColumnType();
    m_widget->setColumnCount(pColumnType->count());
    QStringList headers;
    for(int i = 0; i < pColumnType->count(); i++)
    {
        headers << pColumnType->getField(i)->name();
    }
    m_widget->setHorizontalHeaderLabels(headers);

}

void NuListView::onLoadView()
{
    int n = this->dmFolder()->recordsCount();
    m_widget->setRowCount(n);
    for(int r = 0; r < n; r++)
    {

        DbRecordBuffer* pRow = this->dmFolder()->getRecordAt(r);
        for(int c = 0; c < pRow->count(); c++)
        {
           QString strValue = pRow->getField(c)->value();
           QTableWidgetItem* item = new QTableWidgetItem(strValue);
           m_widget->setItem(r,c,item);
        }
    }
}
