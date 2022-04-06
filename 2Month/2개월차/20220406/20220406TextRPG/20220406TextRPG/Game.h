#pragma once
#include "Player.h"
#include "Field.h"
class Game
{
private:
	Field* m_fp;
public:
	static Player* m_pp;	
	void exe();
	Game();
	~Game();
};

