// 220325.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


#pragma region ���� ������

/*
class CObj
{
private:
	int		m_iA;

public:
	void	Render() { cout << m_iA << endl; }
	void	Print(CObj Test)		// 2. �Լ��� �Ű� ������ ��ü Ÿ���� ��� ���� �����ڸ� ȣ��
	{
		Test.Render();
	}
	CObj	Get_Obj(void)			// 3. �Լ��� ��ȯ Ÿ���� ��ü Ÿ���� ��� ���� �����ڸ� ȣ��
	{
		CObj		Sour(1000);
		return Sour;
	}

public:
	CObj(int _iA) : m_iA(_iA)
	{
		cout << "�Ű� ������ �ִ� ������ ȣ��" << endl;
	}

	CObj(CObj& rObj)		// ������ �ش��ϴ� �����͸� �纻�� �����ͷ� ���縦 ����
	{
		m_iA = rObj.m_iA;

		cout << "���� ������ ȣ��" << endl;
	}

};

// ���� �����ڸ� ����ؾ� �ϴ� ���� 


int main()
{


	
	CObj		Obj(50);

	//CObj		Temp(Obj);	// default ���� ������ ȣ��
	// 1. ���� ���� ���� ��ü�� �纻 ��ü�� ������ �Ű������� �־ ��ü�� �����ϴ� ��� ���� ������ ȣ��

	//Temp.Render();

	//CObj		Temp(10);
	//Temp.Print(Obj);

	Obj.Get_Obj().Render();


	return 0;
}*/




#pragma endregion ���� ������

/*
class CName
{
private:
	char*		m_pName;

public:
	void		Print(CName Name)	{	printf("%s", Name.m_pName);	}

public:
	CName(char* pName)
	{
		int iLength = strlen(pName);

		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, pName);
	}

	CName(CName& rName)			// ���� ����(shallow copy) ������
	{
		//m_pName = rName.m_pName;

		int iLength = strlen(rName.m_pName);	// ���� ����(deep copy) ������

		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, rName.m_pName);
	}

	~CName()
	{
		delete[]m_pName;
	}	
};

void main(void)
{
	CName		Name("neo-peple");
	CName		Test("neo-peple");

	Name.Print(Test);		// ���� ������

}
*/


class Test
{
private:
	int m_a;

public:
	Test()
	{

	}

	Test(int _a) : m_a(_a)
	{
		cout << "�⺻ ������ ȣ��" << endl;
	}

	Test(Test& t)
	{
		m_a = t.m_a;
		cout << "��������� ȣ��" << endl;
	}

	void Print() { cout << m_a << endl;	}
};




void main(void)
{
	Test t;
	t.Print();
}


