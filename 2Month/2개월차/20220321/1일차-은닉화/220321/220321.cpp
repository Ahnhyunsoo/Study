// 220321.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include "Player.h"

// ��ü = Ŭ����(�ڷ���) + �ν��Ͻ�(�޸� ����)

// Ŭ������ 4�� �Ӽ� : ����ȭ, ĸ��ȭ, ��Ӽ�, ������

// ����ȭ : Ŭ���� ���� �����Ϳ� ����� �ܺη� ���� ��ȣ�ϴ�(�����) ������ �ǹ�
// ���� ���� ������ : private, protected, public

// ĸ��ȭ : �����ִ� �����Ϳ� ����� �� Ŭ���� �ȿ� ��� �����ϴ� ����

struct	tagInfo
{
private:
	int			iA;		// ����ü ��� ����
};

class CObj
{
	int			m_iB;		// private ����

public:						// ����, �ܺ� ��� ������ ���,  Ŭ���� ��� ����, public���� ���� ���� ����
	int			m_iD;

private:					// ������ ���� ���ٸ� ����ϴ� ������
	int			m_iC;
	int			m_iA;

public:
	// access method 
	void		Set_A(int _iA)	{	m_iA = _iA;	 }
	int			Get_A(void)		{	return m_iA; }

public:
	void		Render()			// ��� �Լ�
	{
		cout << m_iA << endl;		// ���� ����
	}

};


int main()
{
	//tagInfo		tInfo;
	//tInfo.iA = 100;
	//cout << tInfo.iA << endl;

	//CObj		Obj;
	//Obj.m_iA = 100;		// �ܺ�����
	//Obj.Set_A(100);
	

	//cout << Obj.Get_A() << endl;
	//Obj.Render();
	//cout << Obj.m_iA << endl;*/

	CPlayer		Player;
	Player.Draw();

	/*CPlayer*	pPlayer = new CPlayer[3];

	delete[]pPlayer;
	pPlayer = nullptr;*/

    return 0;
}

// 1. ����ǥ ���α׷��� Ŭ������ ����� ���� �迭�� ��������
// 2. textRpg Ŭ������ �����