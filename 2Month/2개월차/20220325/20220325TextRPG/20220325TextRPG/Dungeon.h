#pragma once
class Dungeon
{
private:
	string m_sDG1;
	string m_sDG2;
	string m_sDG3;
	int m_iDG1;
	int m_iDG2;
	int m_iDG3;

public:
	void CreateDungeon(int _Num);
	void DG1();
	void DG2();
	void DG3();

	void PringDungeon();

	Dungeon();
	~Dungeon();
};

