#pragma once
#include "stdafx.h"
#define SAVE_DELETE(p) if(p) {delete p; p = nullptr;}
#define SAVE_DELETEARRAY(p) if(p) {delete[] p; p = nullptr;}

typedef struct PlayerInfo
{
		string m_ClassName;
		string m_Name;
		int m_Damage;
		int m_MaxHp;
		int m_NowHp;
		int m_MaxMp;
		int m_NowMp;
		int m_MaxExp;
		int m_NowExp;
		int m_Level;
		string m_Skill[2];
		int m_Gold;

	

}PInfo, *PA;

typedef struct MonsterInfo
{
	string m_Name;
	int m_Damage;
	int m_MaxHp;
	int m_NowHp;
	int m_MaxMp;
	int m_NowMp;
	int m_Exp;
	int m_Level;
	int m_Gold;

}MInfo, *MA;