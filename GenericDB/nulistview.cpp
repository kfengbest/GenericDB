#include "nulistview.h"

#include <connectionsqlite.h>
#include <QtGui>

NuListView::NuListView(NuViewBase* parentView, DbRecordBuffer *pData)
    : NuViewBase(parentView, pData)
{
    m_widget = new QTableWidget;
    m_widget->verticalHeader()->setVisible(false);

    DbRecordBuffer* pColumnType = this->dmFolder()->getColumnType();
    m_widget->setColumnCount(pColumnType->count());
    QStringList headers;
    for(int i = 0; i < pColumnType->count(); i++)
    {
        headers << QString::fromLocal8Bit(pColumnType->getField(i)->name().c_str()) ;
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

           std::string cstr = pRow->getField(c)->value();
           QString strValue = QString::fromLocal8Bit(cstr.c_str());

           QTableWidgetItem* item = new QTableWidgetItem(strValue);
           m_widget->setItem(r,c,item);
        }
    }
}
