#include "stdafx.h"
#include "Field.h"
#include "Define.h"

int Field::PrintMenu(int place)
{
	int Input = 0;
	switch (place)
	{
	case 캐릭터생성:
		cout << "1. 전사, 2. 마법사, 3. 도적, 4. 불러오기, 5. 종료 : ";
		cin >> Input;
		break;

	case 마을:
		cout << "1.사냥터 , 2. 저장, 3. 종료 : ";
		cin >> Input;
		break;

	case 던전입구:
		cout << "1.초급 , 2. 중급, 3. 고급 , 4. 전단계 : ";
		cin >> Input;
		break;

	case 던전:
		cout << "1. 공격, 2.Hp회복 , 3. Mp회복, 4. 도망가기 : ";
		cin >> Input;
		break;
	}
	return Input;
}

void Field::SetPlace(int pl)
{
	Place = pl;
}

int Field::GetPlace()
{
	return Place;
}

Field* Field::GetFp()
{
	return fp;
}

Field::Field()
{
	
}



Field::~Field()
{
}
