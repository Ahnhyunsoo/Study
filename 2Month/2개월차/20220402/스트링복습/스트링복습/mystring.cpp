#include "stdafx.h"
#include "mystring.h"

mystring::mystring()
	:m_str(nullptr), Size(0)
{
	
}

mystring::mystring(char* str)
{
	cout << "인자1개생성자호출" << endl;
	Size = strlen(str);
	m_str = new char[Size + 1];
	strcpy_s(m_str, Size + 1, str);
}

//mystring& mystring::operator = (mystring& rstr)
//{
//	cout << "인자1개생성자호출" << endl;
//	Size = strlen(rstr);
//	m_str = new char[Size + 1];
//	strcpy_s(m_str, Size + 1, rstr);
//}

mystring::mystring(mystring& rstr)
{
	Size = strlen(rstr.m_str);
	m_str = new char[Size + 1];
	strcpy_s(m_str, Size + 1, rstr.m_str);
}

void mystring:: operator << (mystring& rstr)
{
	cout << rstr.m_str << endl;
}




mystring::~mystring()
{
}
