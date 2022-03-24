#pragma once
#include "stdafx.h"

#define SAVE_DELETE(p) if (p) { delete p; p = nullptr; }


typedef struct PlayerInfo
{
	string name;
	int m_Level;
	int m_Damage;
	int m_MaxHp;
	int m_NowHp;
	int m_MaxExp;
	int m_NowExp;

}PInfo, *PPInfo;

typedef struct MonsterInfo
{
	string name;
	int m_Level;
	int m_Damage;
	int m_MaxHp;
	int m_NowHp;
	int m_Exp;
}MInfo, *MMInfo;