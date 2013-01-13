#include "nulistview.h"

#include <connectionsqlite.h>

NuListView::NuListView(NuViewBase* parentView, DbRecordBuffer* pData)
    : NuViewBase(parentView, pData)
{
    m_widget = new QTableWidget;
    m_widget->verticalHeader()->setVisible(false);

    QString sql = QString("select * from View_AllProject where 1=0");
    DbRecordBuffer colunmType;
    ConnectionSqlite::get()->buildRecordBufferTypes(sql, &colunmType);

    m_widget->setColumnCount(colunmType.count());
    QStringList headers;
    for(int i = 0; i < colunmType.count(); i++)
    {
        headers << colunmType.getField(i)->name();
    }
    m_widget->setHorizontalHeaderLabels(headers);

}

void NuListView::onLoadView()
{
    QString sql = QString("select * from View_AllProject");
    std::vector<DbRecordBuffer*> records;
    ConnectionSqlite::get()->ExecuteSql(sql, records);

    int n = records.size();
    m_widget->setRowCount(n);
    for(int r = 0; r < n; r++)
    {
        DbRecordBuffer* pRow = records.at(r);
        for(int c = 0; c < pRow->count(); c++)
        {
           QString strValue = pRow->getField(c)->value();
           QTableWidgetItem* item = new QTableWidgetItem(strValue);
           m_widget->setItem(r,c,item);
        }
    }
}
