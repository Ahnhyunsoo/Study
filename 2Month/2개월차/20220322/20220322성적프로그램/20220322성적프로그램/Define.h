#pragma once
#define DELETE_FUNC(p) if(p){delete p; p = nullptr;}
#define DELETE_FUNC_ARRAAY(p) if(p) {delete [] p; p = nullptr;}

typedef struct Stu
{
	string Name;
	int Kor;
	int En;
	int Math;
	int Sum;
	float Avg;

}Info, *PInfo;