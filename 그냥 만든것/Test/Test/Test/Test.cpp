// Test.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


class CA
{
protected:
	int iA = 10;
public:
	virtual void Print() { cout << iA << endl; }
	CA()
	{

	}
};

class CB : public CA
{

public:
	CB()
	{

	}
	void Print() { cout << iA+10 << endl; }

	void PrintB() { cout << 50 << endl; }
};

void main(void)
{
	CA a;
	CB b;

	CA* pa;
	CB* pb;
	pa = new CB;
	pb = new CB;
	pb = dynamic_cast<CB*>(pb);
	
	//CObj*		pObj = new CObj;
	//CPlayer*	pPlayer = pObj;


	

	pb->PrintB();
}

