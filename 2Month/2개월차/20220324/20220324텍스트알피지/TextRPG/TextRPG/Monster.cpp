#include "stdafx.h"
#include "Monster.h"

int Monster::Input()
{
	if (m_pm == NULL)
	{
		m_pm = new MInfo;
	}
	else
	{
		SAVE_DELETE(m_pm);
		m_pm = new MInfo;
	}

	int Input = 0;

	while (true)
	{
		cout << "1. �ʱ�, 2. �߱�, 3. ���, 4. ���ܰ� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_pm->name = "���ѳ�";
			m_pm->m_MaxHp = 50;
			m_pm->m_NowHp = m_pm->m_MaxHp;
			m_pm->m_Level = 1;
			m_pm->m_Damage = 5;
			m_pm->m_Exp = 5;
			return 0;

		case 2:
			m_pm->name = "�ָ��ѳ�";
			m_pm->m_MaxHp = 100;
			m_pm->m_NowHp = m_pm->m_MaxHp;
			m_pm->m_Level = 5;
			m_pm->m_Damage = 10;
			m_pm->m_Exp = 20;
			return 0;

		case 3:
			m_pm->name = "���ѳ�";
			m_pm->m_MaxHp = 200;
			m_pm->m_NowHp = m_pm->m_MaxHp;
			m_pm->m_Level = 10;
			m_pm->m_Damage = 50;
			m_pm->m_Exp = 50;
			return 0;

		case 4:
			SAVE_DELETE(m_pm);
			return 1;
		}
	}
}

void Monster::Output()
{
	cout << "���� : " << m_pm->name << endl;
	cout << "���� : " << m_pm->m_Level << endl;
	cout << "���ݷ� : " << m_pm->m_Damage << endl;
	cout << "ü�� : " << m_pm->m_NowHp << " / " << m_pm->m_MaxHp << endl;
	cout << "����ġ : " << m_pm->m_Exp << endl;
	cout << "========================" << endl;
}

void Monster::Release()
{
	if(m_pm != NULL)
		SAVE_DELETE(m_pm);
}





Monster::Monster()
{
}


Monster::~Monster()
{
}
