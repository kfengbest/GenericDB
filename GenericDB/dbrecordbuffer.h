#ifndef RECORDBUFFER_H
#define RECORDBUFFER_H
#include <QList>

class DbField;

class DbRecordBuffer
{
public:
    DbRecordBuffer();
    ~DbRecordBuffer();

    void setKey(int k) { m_key = k;}
    int getKey() const {return m_key;}

    DbField* getField(int i) const {return m_fields.at(i);}
    void addField(DbField* f) { m_fields.append(f);}
    int count() const {return m_fields.size();}

private:
    QList<DbField*> m_fields;

    int m_key;

};

#endif // RECORDBUFFER_H
