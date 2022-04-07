#include "stdafx.h"
#include "Player.h"
#include "Item.h"

CPlayer::CPlayer()
	: CObj()
{
	memset(m_pItem, 0, sizeof(m_pItem));
}


CPlayer::CPlayer(char* _pName, int _iAttack, int _iMaxHp, int _iLevel /*= 1*/)
	: CObj(_pName, _iAttack, _iMaxHp, _iLevel)
{
	memset(m_pItem, 0, sizeof(m_pItem));
}

CPlayer::~CPlayer()
{
}

void CPlayer::SelectJob(void)
{
	int		iInput = 0;

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 해호 4. 불러오기 5. 종료) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "전사");
		m_tInfo.iMaxHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;

		break;
	
	case 2:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "마법사");
		m_tInfo.iMaxHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;

	case 3:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "해호");
		m_tInfo.iMaxHp = 100;
		m_tInfo.iAttack = 2;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 10000000;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 0;
		break;

	case 4:
		Load_Data();
		break;

	case 5:
		return;

	default:
		break;
	}
}

void CPlayer::Combat_Win(int _iExp, int _iMoney)
{
	m_tInfo.iExp += _iExp;
	m_tInfo.iMoney += _iMoney;

	if (m_tInfo.iExp >= m_tInfo.iMaxExp)
	{
		m_tInfo.iLevel++;

		m_tInfo.iExp -= m_tInfo.iMaxExp;
		m_tInfo.iMaxExp += 100;
		m_tInfo.iAttack += 5;
		m_tInfo.iMaxHp += 50;
		m_tInfo.iHp = m_tInfo.iMaxHp;
	}

}

void CPlayer::Combat_Lose(void)
{
	m_tInfo.iExp >>= 1;
	m_tInfo.iMoney >>= 1;
	m_tInfo.iHp = m_tInfo.iMaxHp;
}

void CPlayer::Combat_Run(void)
{
	m_tInfo.iExp = 0;
	m_tInfo.iMoney = 0;
}

void CPlayer::Equip_Item(CObj * pItem)
{
	ITEM	eType = dynamic_cast<CItem*>(pItem)->Get_Itemtype();

	if (m_pItem[eType])	// 기존에 장착한 아이템이 있다면
	{
		Item_Ability(-m_pItem[eType]->Get_Info().iAttack, -m_pItem[eType]->Get_Info().iHp);
		dynamic_cast<CItem*>(m_pItem[eType])->Set_ItemState(STATE_UNEQUIP);
		m_pItem[eType] = nullptr;
	}

	Item_Ability(pItem->Get_Info().iAttack, pItem->Get_Info().iHp);
	dynamic_cast<CItem*>(pItem)->Set_ItemState(STATE_EQUIP);	
	m_pItem[eType] = pItem;
}

void CPlayer::Unequip_Item(CObj* pItem)
{
	ITEM	eType = dynamic_cast<CItem*>(pItem)->Get_Itemtype();

	if (m_pItem[eType])	// 기존에 장착한 아이템이 있다면
	{
		Item_Ability(-m_pItem[eType]->Get_Info().iAttack, -m_pItem[eType]->Get_Info().iHp);
		dynamic_cast<CItem*>(m_pItem[eType])->Set_ItemState(STATE_UNEQUIP);
		m_pItem[eType] = nullptr;
	}
}

void CPlayer::Item_Ability(int _iAttack, int _iHp)
{
	m_tInfo.iAttack += _iAttack;
	m_tInfo.iHp += _iHp;
}

void CPlayer::Load_Data(void)
{
	FILE*		fp = nullptr;

	errno_t		err = fopen_s(&fp, "../Data/Save.dat", "rb");

	if (0 == err)
	{
		INFO	tTemp = {};

		fread(&tTemp, sizeof(INFO), 1, fp);

		m_tInfo = tTemp;

		cout << "불러오기 성공" << endl;
		fclose(fp);
	}
	else
		cout << "불러오기 실패" << endl;

	system("pause");
}
