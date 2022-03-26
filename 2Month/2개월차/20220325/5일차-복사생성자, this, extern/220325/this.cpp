#include "stdafx.h"
#include "Define.h"

int  g_iNumber = 200;

#pragma region this 포인터

/*
class CObj
{
private:
	int		m_iA;

public:
	CObj*		Get_This(void)
	{
		return this;
	}

public:
	void	Render()
	{
		cout << this->m_iA << endl;
	}

public:
	CObj() : m_iA(10)
	{

	}
	CObj(int _iA) : m_iA(_iA)
	{

	}
};

void main(void)
{
	// this 포인터 : 생성된 객체 자신의 주소값을 저장하고 있는 상수 포인터

	/ *
	CObj		Obj(10);
	cout << (&Obj) << endl;
	cout << Obj.Get_This() << endl;
	//Obj.Render();


	CObj		Temp(20);
	cout << (&Temp) << endl;
	cout << Temp.Get_This() << endl;* /
	//Temp.Render();


	/ *CObj		Obj[5];

	for (int i = 0; i < 5; ++i)
	{
	cout << Obj[i].Get_This() << endl;
	}	* /

	//CObj*		pObj = new CObj;

	//cout << pObj << endl;
	//cout << pObj->Get_This() << endl;

	CObj*		pObj = new CObj;
	CObj		Temp;

	// *pObj;
	// *this;


}*/
#pragma endregion this 포인터

#pragma region extern

void main(void)
{
	cout << g_iNumber << endl;
}

#pragma endregion extern

