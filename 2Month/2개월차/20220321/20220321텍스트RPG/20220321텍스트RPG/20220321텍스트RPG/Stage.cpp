#include "stdafx.h"
#include "Stage.h"

void CStage::Menu(int Stage)
{
	if (Stage == 전직선택)
	{
		cout << "1. 전사, 2. 마법사, 3. 도적, 4. 불러오기, 5. 종료 :";
	}
	else if(Stage == 마을)
	{
		cout << "1. 사냥터, 2. 저장, 3. 종료 : ";
	}
	else if (Stage == 던전입구)
	{
		cout << "1. 초급, 2. 중급, 3. 고급, 4. 전단계 : ";
	}
	else if (Stage == 던전)
	{
		cout << "1. 전투, 2. 도망, 3. HP회복 : ";
	}
}