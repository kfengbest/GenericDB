#ifndef RECORDBUFFER_H
#define RECORDBUFFER_H
#include <QList>

class DbField;

class DbRecordBuffer
{
public:
    DbRecordBuffer();

    QList<DbField*> m_fields;

};

#endif // RECORDBUFFER_H
