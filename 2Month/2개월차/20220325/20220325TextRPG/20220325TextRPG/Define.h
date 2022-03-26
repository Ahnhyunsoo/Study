#pragma once


#define SAVE_DELETE(p) if(p) { delete p;  p = nullptr;}

typedef struct PlayerInfo
{
	string m_sCharacter;
	string m_sName;
	int m_iLevel;
	int m_iDamage;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iMaxMp;
	int m_iNowMp;
	int m_iMaxExp;
	int m_iNowExp;
	int m_iGold;

public:
	PlayerInfo() : m_iGold(0), m_iLevel(1),m_iNowExp(0) {};

}PInfo, *PPInfo;



typedef struct MonsterInfo
{
	const string m_sName;
	int m_iLevel;
	int m_iDamage;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iMaxMp;
	int m_iNowMp;
	int m_Exp;
	int m_iGold;

}MInfo, *PMInfo;

typedef struct InventoryInfo
{
	string m_sArray[10];
	int m_iGold;

}IInfo, *PIInfo;


typedef struct ShopInfo
{
	string m_sName;
}SInfo, PSInfo;


typedef struct ItemInfo
{
	string m_sName;
	string m_sNotice;
	int m_iHp;
	int m_iMp;
	int m_Damage;
	int m_iExp;
	int m_iGold;

}ITInfo, PITInfo;
