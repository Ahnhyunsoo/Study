#include "stdafx.h"


class Role
{
public:
	virtual bool operator() (int iTemp, int iSour) = 0;
	
};

class ASC final : public Role
{
public:
	bool operator() (int iTemp, int iSour)
	{
		if (iTemp < iSour)
			return true;

		return false;
	}
};

class DESC final : public Role
{
	bool operator() (int iTemp, int iSour)
	{
		if (iTemp > iSour)
			return true;

		return false;
	}
};

void Bubble(int* Array, int size, Role& funtor)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (funtor(Array[j], Array[j+1]))
			{
				int	iTemp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = iTemp;
			}
		}
	}
}


void main(void)
{
	int Array[5] = { 3,4,2,1,5 };

	ASC a;
	DESC d;

	Bubble(Array, 5, d);

	for (int i = 0; i < 5; ++i)
	{
		cout << Array[i] << endl;
	}
}