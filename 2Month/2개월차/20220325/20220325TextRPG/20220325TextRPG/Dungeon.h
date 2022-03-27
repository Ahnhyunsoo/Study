#pragma once
#include "Monster.h"

class Dungeon
{
private:
	string m_sDG1;
	string m_sDG2;
	string m_sDG3;
	string m_sPlace;
	int m_iDG1;
	int m_iDG2;
	int m_iDG3;
	Monster* m_mp;

public:
	void CreateDungeon(int _Num);
	void DG1();
	void DG2();
	void DG3();
	void Place(int _Place);
	string GetPlace();
	void PrintDungeon();
	void CreateM(string DG);
	void DeleteMonster();
	void PrintInfo();
	int Battle();

	Dungeon();
	~Dungeon();
};

