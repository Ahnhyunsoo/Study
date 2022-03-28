#pragma once
class Item
{
private:
	string m_sName;
	int m_iPrice;
	int m_iStats;
	
public:
	void Buy();
	void Sell();
	void Weapon();
	void Armor();
	void Utility();
	int PrintItem();


	Item();
	~Item();
};

