#pragma once
class CBase abstract
{
protected:
	CBase();
	virtual ~CBase() = default;

public:
	unsigned long Add_Ref(void);
	unsigned long Release(void);

	virtual void Free() = 0;
private:
	unsigned long dwRefCnt;
};

