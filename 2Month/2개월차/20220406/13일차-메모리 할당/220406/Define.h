#pragma once

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

class CDeleteObj
{


public:
	template<typename T> //���� �����ε����ִµ�
	void operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};




typedef struct tagInfo
{
	string		strName;
	int			iKor;
	int			iEng;
	int			iMath;
	int			iTotal;
	float		fAver;

}INFO;