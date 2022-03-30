// Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//class CA
//{
//public:
//	virtual void Render() { cout << "부모" << endl; }
//};
//
//class CB : public CA
//{
//public:
//	void Render() { cout << "자식" << endl; }
//	void RenderCB() { cout << "CB전용" << endl; }
//};


void Render(string* pTemp);

int main()
{
	string		iTemp = "Reinterpret";

	Render(&iTemp);
	return 0;
}

void	Render(string* pTemp)
{
int* pDest = reinterpret_cast<int*>(pTemp);

cout << (*pDest) << endl;
}


