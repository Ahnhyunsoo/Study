// 220323_1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Player.h"

class CObj
{
private:
	int		m_iA;

public:
	void		Render() { cout << m_iA << endl; }

public:
	explicit CObj()
	{
		cout << "�⺻ ������" << endl;
	}

	explicit CObj(int _iA)		// ������ ����ȯ�� ������ ���� �� ����ϴ� Ű����
	{
		m_iA = _iA;
	}

	~CObj()
	{
		cout << "�Ҹ���" << endl;
	}
};

/*
1. ������ ���� 
2. �����Ⱚ 
3. 10 
4. 10 ��� ���� ��Ÿ�� ����*/

int main()
{
	//CObj		Obj = 10;		// default ���� �����ڸ� ȣ���Ͽ�, int�� ������ �޴� �Ű������� �ִ� �����ڷ� �ڵ� ����ȯ�Ͽ� ��ü ������ �����ϰ� ����� �ִ�.

	//Obj.Render();


	//CObj		Obj[3];

/*
	CObj*		pObj = new CObj[3];

	delete[]pObj;
	pObj = nullptr;*/


	CPlayer		Player; // �޸� �Ҵ�, ������ ȣ��

	Player.Render();
	Player.Draw();


    return 0;
}

