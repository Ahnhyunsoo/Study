#pragma once

#define		SAFE_DELETE(p) if(p) { delete p; p = nullptr; }

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}


typedef struct tagInfo
{
	char		szName[32];
	int			iAttack;
	int			iHp;
	int			iMaxHp;
	int			iExp;
	int			iMaxExp;
	int			iLevel;
	int			iMoney;

	tagInfo(void)
		: iHp(0), iAttack(0), iMaxHp(0), iExp(0), iMaxExp(0), iLevel(0), iMoney(0)
	{
		memset(szName, 0, sizeof(char) * 32);
	}
	tagInfo(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1)
		: iAttack(_iAttack), iMaxHp(_iMaxHp), iLevel(_iLevel), iExp(0), iMaxExp(100), iHp(_iMaxHp), iMoney(0)
	{
		strcpy_s(szName, 32, _pName);
	}

}INFO;

enum COMBAT	 { COMBAT_WIN, COMBAT_LOSE, COMBAT_RUN, COMBAT_END };
enum ITEM	 { ITEM_SWORD, ITEM_ARMOR, ITEM_END };
enum CLASS   { CLASS_BEGINER, CLASS_ADVANCED, CLASS_LEGEND, CLASS_END };
enum STATE	 { STATE_EQUIP, STATE_UNEQUIP, STATE_END };