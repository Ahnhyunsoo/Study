#include "stdafx.h"
#include "Player.h"


void Player::Print()
{
}

void Player::Create(string name, int level, int damage, int hp, int exp, int gold)
{
	Obj::Create(name, level, damage, hp, exp, gold);
	
}

Player::Player()
	:m_iNowExp(0),m_sWP("����"),m_sAM("����")
{
}


Player::~Player()
{
}
