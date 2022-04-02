// 220401.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	CMyString	MyString;
	CMyString	MyString2;


	MyString = "홍길동";
	MyString2 = "이순신";

	cout << MyString << endl;

	//MyString = MyString2;

	//MyString = MyString + "_활빈당";
	//MyString = MyString + MyString2;

	//cout << MyString.Get_String() << endl;

/*
	if (MyString == "홍길동")
		cout << "일치" << endl;

	else 
		cout << "불일치" << endl;*/

	//MyString2 = "홍길동";

	//if (MyString == MyString2)
	//	cout << "일치" << endl;

	//else
	//	cout << "불일치" << endl;

	
    return 0;
}

