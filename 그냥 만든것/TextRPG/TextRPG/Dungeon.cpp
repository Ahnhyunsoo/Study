#include "stdafx.h"
#include "Dungeon.h"
#include "Player.h"
#include "Monster.h"
#include "Define.h"

void Dungeon::CreatePlace()
{
	
	m_pp = cp.GetP();
	int Input = 0;
	cout << "직업을 선택해주세요" << endl;
	cout << "1. 귀검사, 2. 격투가, 3. 거너, 4. 마법사 : ";
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
			cout << "게임을 종료합니다" << endl;
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
