// Test.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"




class CObj
{
private:
	char		m_pStr[256];

public:
	CObj()
	{

	}

	CObj(int a)
	{
		cout << a << " �ӽû�����" << endl;
	}

	/*CObj(char* pStr)
	{
		strcpy_s(m_pStr, sizeof(m_pStr), pStr);
		cout << m_pStr << "������" << endl;
	}*/
	~CObj()
	{
		cout << "�Ҹ���" << endl;
	}
};


void main(void)
{
	//int iA = 3 + 4;

	//CObj		Obj("�Ϲ�");
	//cout << "===============�ӽ� ��ü ����================" << endl;

	//CObj("�ӽ� ��ü");		// �ӽ� ��ü�� �ش� �ڵ������ ����� ��� �Ҹ�ȴ�.

	//cout << "===============�ӽ� ��ü �Ҹ�================" << endl;

	CObj(1);

}

