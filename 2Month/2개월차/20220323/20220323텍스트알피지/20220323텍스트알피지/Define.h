#pragma once
#include "stdafx.h"

#define SAVE_DELETE(p) if(p) {delete p; p = nullptr;}

enum Character {전사 = 1, 마법사 = 2, 도적 = 3, 불러오기 = 4, 종료 = 5};
enum Place {캐릭터생성 = 1, 마을 = 2, 던전입구 = 3, 던전 = 4};
enum Contury {사냥터 = 1, 저장 = 2};
enum DungeonEntry {초급 = 1, 중급 = 2, 고급 = 3, 전단계 = 4};
enum Dungeon {공격 = 1, Hp회복 = 2, Mp회복 = 3, 도망가기 = 4};



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

