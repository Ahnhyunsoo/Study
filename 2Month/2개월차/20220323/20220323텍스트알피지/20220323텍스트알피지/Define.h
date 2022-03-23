#pragma once
#include "stdafx.h"

#define SAVE_DELETE(p) if(p) {delete p; p = nullptr;}

enum Character {���� = 1, ������ = 2, ���� = 3, �ҷ����� = 4, ���� = 5};
enum Place {ĳ���ͻ��� = 1, ���� = 2, �����Ա� = 3, ���� = 4};
enum Contury {����� = 1, ���� = 2};
enum DungeonEntry {�ʱ� = 1, �߱� = 2, ��� = 3, ���ܰ� = 4};
enum Dungeon {���� = 1, Hpȸ�� = 2, Mpȸ�� = 3, �������� = 4};



typedef struct PlayerInfo
{
	string m_sName;
	int m_iDamage;
	int m_iNowHp;
	int m_iMaxHp;
	int m_iNowMp;
	int m_iMaxMp;
	int m_iNowExp;
	int m_iMaxExp;
	int m_iLevel;

}PInfo, *PPInfo;

typedef struct MonsterInfo
{
	string m_sName;
	int m_iDamage;
	int m_iNowHp;
	int m_iMaxHp;
	int m_iNowMp;
	int m_iMaxMp;
	int m_iExp;
	int m_iLevel;

}MInfo , *MMInfo;

