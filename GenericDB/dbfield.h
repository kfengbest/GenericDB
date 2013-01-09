#ifndef RECORDFIELD_H
#define RECORDFIELD_H

#include <QString>

class DbField
{
public:
    DbField();

    QString name() const {return m_Name;}
    void name(const QString& n){ m_Name = n;}

    QString type() const {return m_Type;}
    void type(const QString& n){ m_Type = n;}

    QString value() const {return m_Value;}
    void value(const QString& n){ m_Value = n;}

    QString length() const {return m_Length;}
    void length(const QString& n){ m_Length = n;}


private:
    QString m_Name;
    QString m_Value;
    QString m_Type;
    QString m_Length;
};

#endif // RECORDFIELD_H
