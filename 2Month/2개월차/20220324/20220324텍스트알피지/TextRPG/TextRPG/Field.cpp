#include "stdafx.h"
#include "Field.h"

int Field::GetPlace()
{
	return place;
}

void Field::SetPlace(int _iA)
{
	place = _iA;
}


Field::Field() : place(1)
{
}


Field::~Field()
{
}
