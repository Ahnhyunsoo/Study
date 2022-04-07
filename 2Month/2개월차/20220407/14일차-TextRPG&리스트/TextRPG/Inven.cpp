#include "stdafx.h"
#include "Inven.h"
#include "Item.h"

CInven::CInven()
	: m_iSize(5), m_pPlayer(nullptr)
{
	m_vecInven.reserve(m_iSize);
}

CInven::~CInven()
{
	Release();
}

bool CInven::Buy_Item(CObj* _pItem)
{
	if (m_vecInven.size() >= m_iSize)
		return false;

	CItem*		pTemp = dynamic_cast<CItem*>(_pItem);
	CObj*		pItem = new CItem(*pTemp);

	m_vecInven.push_back(pItem);
	//m_vecInven.push_back(new CItem(*dynamic_cast<CItem*>(pItem)));
	return true;
}

bool CInven::Sell_Item(int _iIndex, int* pMoney)
{
	vector<CObj*>::iterator		iter = m_vecInven.begin();

	iter += _iIndex;

	*pMoney = (*iter)->Get_Info().iMoney >> 1;

	Safe_Delete<CObj*>(*iter);
	m_vecInven.erase(iter);

	return true;
}

void CInven::Equip_Item(void)
{
	int		iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render();

		cout << "0. 나가기 : ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if(size_t(iInput) >= m_vecInven.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->Equip_Item(m_vecInven[iInput]);
	}

}

void CInven::Unequip_Item(void)
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render(); 

		cout << "0. 나가기 : ";
		cin >> iInput;
		--iInput;

		if (0 > iInput)
			return;

		if(size_t(iInput) >= m_vecInven.size())
			continue;

		dynamic_cast<CPlayer*>(m_pPlayer)->Unequip_Item(m_vecInven[iInput]);
	}

}

void CInven::Initialize(void)
{
}

void CInven::Update(void)
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. 장착 2. 해제 3. 나가기 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Equip_Item();
			break;

		case 2:
			Unequip_Item();
			break;

		case 3:
			return;

		default:
			break;
		}
	}
}

void CInven::Render(void)
{
	system("pause");

	for (size_t i = 0; i < m_vecInven.size(); ++i)
	{
		cout << i + 1 << " : ";
		m_vecInven[i]->Render();
	}
}

void CInven::Release(void)
{
	for_each(m_vecInven.begin(), m_vecInven.end(), Safe_Delete<CObj*>);
	m_vecInven.clear();
}

