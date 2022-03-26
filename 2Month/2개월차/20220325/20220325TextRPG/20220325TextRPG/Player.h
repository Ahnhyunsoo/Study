#pragma once

class Player
{
private:
	PPInfo m_pp;
public:
	int CreatePlayer();
	void PrintInfo();
	void Knight();
	void Fighter();
	void Mage();
	int Hp(int _Damage);
	void LevelUp(int _Exp);
	void Die(int _Exp);
	Player();
	~Player();
};

