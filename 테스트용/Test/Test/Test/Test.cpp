// Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct WP
{
	string name = "무기";
	int damage = 10;

	void Print()
	{
		cout << name << endl;
		cout << damage << endl;
	}
};




void main(void)
{
	vector<WP> vec;
	vector<WP>::iterator iter;
	//WP* W = new WP;
	WP w;
	WP w2;
	WP w3;
	vec.push_back(w);
	vec.push_back(w2);
	vec.push_back(w3);
	iter = iter = vec.begin();
	vec.erase(iter);
	
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
		vec[1].Print();
	
	
	
}

