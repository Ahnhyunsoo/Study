#pragma once
#include "stdafx.h"


class Field
{
private:
	Field* fp;
	int Place;
public:
	int PrintMenu(int place);
	void SetPlace(int place);
	int GetPlace();
	Field* GetFp();
	Field();
	~Field();
};

