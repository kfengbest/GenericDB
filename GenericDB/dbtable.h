#ifndef DBTABLE_H
#define DBTABLE_H

class RecordBuffer;

class DbTable
{
public:
    DbTable();


    bool Insert(RecordBuffer* pRecord);
    bool Delete(RecordBuffer* pRecord);
    bool Update(RecordBuffer* pRecord);


};

#endif // DBTABLE_H
