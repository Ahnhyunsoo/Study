// 220328.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Boy.h"

// base Ŭ���� : �����͸� �����ִ� Ŭ����, ���������� �θ� Ŭ������� ǥ���� ���� �Ѵ�.
// derived Ŭ���� : �����͸� �����޴� Ŭ����, �ڽ� Ŭ������� ǥ���� ���� �Ѵ�.

class CObj
{
protected:
	int		m_iA;

public:
	CObj() { cout << "�θ� ������" << endl; }
	CObj(int _iA)
		: m_iA(_iA)
	{

	}
	~CObj() { cout << "�θ� �Ҹ���" << endl; }
};

// #include "Obj.h"

class CPlayer : public CObj
{
/*
private:
	int		m_iA = 200;*/

public:
	void	Render(void) 
	{ 
		cout << m_iA << endl;	// player ��� ����
		cout << CObj::m_iA << endl; // �θ𿡼� ����� ��� ����
	}
public:
	CPlayer() 
	{ 
		cout << "�ڽ� ������" << endl; 
	}
	CPlayer(int _iA)
		: CObj(_iA)
	{

	}

	~CPlayer() { cout << "�ڽ� �Ҹ���" << endl; }
};

class CMonster : public CObj
{
public:
	void	Render(void) { cout << this->m_iA << endl; }
public:
	CMonster() { cout << "���� ������ " << endl; }
};

int main()
{
	
	//CObj		Obj;

	//CPlayer		Player;

	// ����� ����

	// 1. is-a	
	// 2. has-a
	
    return 0;
}

