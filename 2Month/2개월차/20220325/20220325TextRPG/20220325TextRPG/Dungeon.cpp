#include "stdafx.h"
#include "Dungeon.h"

void Dungeon::CreateDungeon(int _Num)
{
	if (_Num == 1)
	{
		DG1();
	}
	else if (_Num == 2)
	{
		DG2();
	}
	else
		DG3();
}

void Dungeon::PringDungeon()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << m_sDG1 << " ���巹�� = " << m_iDG1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "\t" << m_sDG2 << " ���巹�� = " << m_iDG2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\t" << m_sDG3 << " ���巹�� = " << m_iDG3 << endl;
	cout << "������ ���� : ";
}

void Dungeon::DG1()
{
	m_sDG1 = "��ũ���";
	m_sDG2 = "�׶�ī��";
	m_sDG3 = "����Ǽ�������";
	m_iDG1 = 1;
	m_iDG1 = 3;
	m_iDG1 = 5;
}

void Dungeon::DG2()
{
	m_sDG1 = "�����ܰ�";
	m_sDG2 = "���";
	m_sDG3 = "����";
	m_iDG1 = 10;
	m_iDG1 = 15;
	m_iDG1 = 20;
}

void Dungeon::DG3()
{
	m_sDG1 = "�Ź̼ұ�";
	m_sDG2 = "��ϱ�";
	m_sDG3 = "���ǲ�Ա�";
	m_iDG1 = 25;
	m_iDG1 = 30;
	m_iDG1 = 40;
}

Dungeon::Dungeon()
{
}


Dungeon::~Dungeon()
{
}
