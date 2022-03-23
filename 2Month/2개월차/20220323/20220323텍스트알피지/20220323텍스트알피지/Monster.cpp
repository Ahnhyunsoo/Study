#include "stdafx.h"
#include "Monster.h"
#include "Field.h"

void Monster::Easy(MMInfo _mp)
{
	_mp->m_sName = "���ѳ�";
	_mp->m_iLevel = 1;
	_mp->m_iMaxHp = 50;
	_mp->m_iNowHp = _mp->m_iMaxHp;
	_mp->m_iExp = 10;
	_mp->m_iDamage = 5;
	_mp->m_iMaxMp = 20;
	_mp->m_iNowMp = _mp->m_iMaxMp;
}

void Monster::Nomal(MMInfo _mp)
{
	_mp->m_sName = "�ָ��ѳ�";
	_mp->m_iLevel = 5;
	_mp->m_iMaxHp = 100;
	_mp->m_iNowHp = _mp->m_iMaxHp;
	_mp->m_iExp = 20;
	_mp->m_iDamage = 20;
	_mp->m_iMaxMp = 50;
	_mp->m_iNowMp = _mp->m_iMaxMp;
}

void Monster::Hard(MMInfo _mp)
{
	_mp->m_sName = "���ѳ�";
	_mp->m_iLevel = 10;
	_mp->m_iMaxHp = 250;
	_mp->m_iNowHp = _mp->m_iMaxHp;
	_mp->m_iExp = 100;
	_mp->m_iDamage = 50;
	_mp->m_iMaxMp = 200;
	_mp->m_iNowMp = _mp->m_iMaxMp;
}


void Monster::Create(Field* _fp)
{
	m_mp = new MInfo;
	int place = _fp->GetPlace();
	while (true)
	{
		switch (_fp->PrintMenu(place))
		{
		case �ʱ� :
			Easy(m_mp);
			_fp->SetPlace(����);
			return;

		case �߱� :
			Nomal(m_mp);
			_fp->SetPlace(����);
			return;

		case ��� :
			Hard(m_mp);
			_fp->SetPlace(����);
			return;

		case ���ܰ� :
			_fp->SetPlace(����);
			SAVE_DELETE(m_mp);
			return;

		default :
			continue;
		}
	}
}

void Monster::Output()
{
	cout << "�̸� : " << m_mp->m_sName << endl;
	cout << "���� : " << m_mp->m_iLevel << endl;
	cout << "ü�� : " << m_mp->m_iNowHp << " / " << m_mp->m_iMaxHp << endl;
	cout << "���� : " << m_mp->m_iNowMp << " / " << m_mp->m_iMaxMp << endl;
	cout << "���ݷ� : " << m_mp->m_iDamage << endl;
	cout << "����ġ : " << m_mp->m_iExp << endl;
	cout << "======================" << endl;
}

MMInfo Monster::GetM()
{
	return m_mp;
}

void Monster::Release()
{
	delete m_mp;
	m_mp = nullptr;
}

Monster::Monster()
{
}


Monster::~Monster()
{
}
