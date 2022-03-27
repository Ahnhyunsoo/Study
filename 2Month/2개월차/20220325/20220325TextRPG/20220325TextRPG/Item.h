#pragma once
class Item
{
private:
	string m_sName;
	int m_iPrice;
	int m_iStats;
	
public:
	void Weapon();
	void Armor();
	void Utility();
	void PrintItem();


	Item();
	~Item();
};

