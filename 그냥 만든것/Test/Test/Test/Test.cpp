// Test.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//class CA
//{
//public:
//	virtual void Render() { cout << "�θ�" << endl; }
//};
//
//class CB : public CA
//{
//public:
//	void Render() { cout << "�ڽ�" << endl; }
//	void RenderCB() { cout << "CB����" << endl; }
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


