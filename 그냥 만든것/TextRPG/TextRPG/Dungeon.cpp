#include "stdafx.h"
#include "Dungeon.h"
#include "Player.h"
#include "Monster.h"
#include "Define.h"

void Dungeon::CreatePlace()
{
	
	m_pp = cp.GetP();
	int Input = 0;
	cout << "������ �������ּ���" << endl;
	cout << "1. �Ͱ˻�, 2. ������, 3. �ų�, 4. ������ : ";
	cin >> Input;
	while (true)
	{
		switch (Input)
		{
		case 1:
			cp.Knight();
			cp.PrintInfo();
			system("pause");
		case 2:
			cp.Fighter();

		case 3:
			cp.Gunner();

		case 4:
			cp.Mage();

		case 5:
			cout << "������ �����մϴ�" << endl;
			SAVE_DELETE(m_pp);
			exit(0);
		}
	}
}

Dungeon::Dungeon()
{
}


Dungeon::~Dungeon()
{
}
