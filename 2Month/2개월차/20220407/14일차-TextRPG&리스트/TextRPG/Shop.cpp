#include "stdafx.h"
#include "Shop.h"


CShop::CShop()
{
	memset(m_pItem, 0, sizeof(m_pItem));
}

CShop::~CShop()
{
	Release();
}

void CShop::Initialize(void)
{
	// �����
	CItem*		pItem = new CItem("�ʱް�", 20, 0, 1);
	pItem->Initialize(CLASS_BEGINER);
	pItem->Set_Itemtype(ITEM_SWORD);
	m_pItem[ITEM_SWORD][CLASS_BEGINER] = pItem;

	pItem = new CItem("�߱ް�", 40, 0, 1);
	pItem->Initialize(CLASS_ADVANCED);
	pItem->Set_Itemtype(ITEM_SWORD);
	m_pItem[ITEM_SWORD][CLASS_ADVANCED] = pItem;

	pItem = new CItem("��ް�", 90, 0, 1);
	pItem->Initialize(CLASS_LEGEND);
	pItem->Set_Itemtype(ITEM_SWORD);
	m_pItem[ITEM_SWORD][CLASS_LEGEND] = pItem;

	// ��
	pItem = new CItem("�ʱ޿�", 0, 20, 1);
	pItem->Initialize(CLASS_BEGINER);
	pItem->Set_Itemtype(ITEM_ARMOR);
	m_pItem[ITEM_ARMOR][CLASS_BEGINER] = pItem;

	pItem = new CItem("�߱޿�", 0, 40, 1);
	pItem->Initialize(CLASS_ADVANCED);
	pItem->Set_Itemtype(ITEM_ARMOR);
	m_pItem[ITEM_ARMOR][CLASS_ADVANCED] = pItem;

	pItem = new CItem("��޿�", 0, 90, 1);
	pItem->Initialize(CLASS_LEGEND);
	pItem->Set_Itemtype(ITEM_ARMOR);
	m_pItem[ITEM_ARMOR][CLASS_LEGEND] = pItem;

}

void CShop::Update(void)
{

	int	iInput = 0;

	while (true)
	{

		system("cls");
		m_pPlayer->Render();

		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �Ǹ� 5. �� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Render(CLASS_BEGINER);
			break;

		case 2:
			Render(CLASS_ADVANCED);
			break;

		case 3:
			Render(CLASS_LEGEND);
			break;

		case 4:
			Sell_Item();
			break;

		case 5:
			return;

		default:
			break;
		}

	}

}

void CShop::Release(void)
{
	for (int i = 0; i < ITEM_END; ++i)
	{
		for (int j = 0; j < CLASS_END; ++j)
		{
			SAFE_DELETE(m_pItem[i][j]);
		}
	}
}

void CShop::Buy_Item(CObj* pItem)
{
	if ((m_pPlayer->Get_Info().iMoney >= pItem->Get_Info().iMoney) 
		&& m_pInven->Buy_Item(pItem))
	{
		dynamic_cast<CPlayer*>(m_pPlayer)->Set_MinusMoney(pItem->Get_Info().iMoney);
		cout << "���� ����" << endl;
	}
	else
	{
		cout << "�ܾ��� �����մϴ�. ���� ����" << endl;
	}

	system("pause");
}

void CShop::Sell_Item(void)
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pInven->Render();

		cout << "0. ������ : ";
		cin >> iInput;

		--iInput;

		if (0 > iInput)
			return;

		if (5 <= iInput)
			return;
	
		int		iMoney = 0;

		if (m_pInven->Sell_Item(iInput, &iMoney))
		{
			dynamic_cast<CPlayer*>(m_pPlayer)->Set_PlusMoney(iMoney);
			cout << "�Ǹ� ����" << endl;
		}
		else
			cout << "�Ǹ� ����" << endl;


		system("pause");
	}


}

void CShop::Render(CLASS eLevel)
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		m_pItem[ITEM_SWORD][eLevel]->Render();
		m_pItem[ITEM_ARMOR][eLevel]->Render();

		cout << "1. ���� ���� 2. �� ���� 3. �� �ܰ� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Buy_Item(m_pItem[ITEM_SWORD][eLevel]);
			break;

		case 2:
			Buy_Item(m_pItem[ITEM_ARMOR][eLevel]);
			break;

		case 3:
			return;

		default:
			break;
		}

	}

}
