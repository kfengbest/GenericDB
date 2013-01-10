#ifndef NUVIEWBASE_H
#define NUVIEWBASE_H

class RecordBuffer;

class NuViewBase
{
public:
    NuViewBase(NuViewBase* parentView, RecordBuffer* pData);

    void loadView() { onLoadView();}

protected:
    virtual void onLoadView() {}

private:
    NuViewBase* m_pParentView;
    RecordBuffer* m_pRecord;
};

#endif // NUVIEWBASE_H
