#pragma once
class Monster
{
private:
	PMInfo m_pmp;
public:

	int GetExp() { return m_pmp->m_Exp; }
	int GetGold() { return m_pmp->m_iGold; }
	int GetDamage() { return m_pmp->m_iDamage; }
	void CreateMonster(string dg);
	void DeleteMonster();
	void PrintMonster();
	void Tau();
	void Tauking();
	void Zombie();
	void Sindo();
	void Tentacle();
	void Lotus();
	void Spider();
	void Ghost();
	void Knight();
	int Hp(int _Damage);

	Monster();
	~Monster();
};

