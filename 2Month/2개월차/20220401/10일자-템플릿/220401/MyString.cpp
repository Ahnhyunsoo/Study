#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString()
	:m_pString(nullptr), m_iSize(0)
{
}

CMyString::CMyString(char* pString)
{
	m_iSize = strlen(pString);

	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, pString);
}

CMyString::CMyString(const CMyString& rhs)
	: m_iSize(rhs.m_iSize)
{
	m_pString = new char[m_iSize + 1];
	strcpy_s(m_pString, m_iSize + 1, rhs.m_pString);
}

CMyString::~CMyString()
{
	Release();
}

CMyString& CMyString::operator=(char* pString)
{
	Release();

	m_iSize = strlen(pString);
	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, pString);

	return *this;
}

CMyString& CMyString::operator=(CMyString& rString)
{
	Release();
	
	m_iSize = strlen(rString.m_pString);
	m_pString = new char[m_iSize + 1];

	strcpy_s(m_pString, m_iSize + 1, rString.m_pString);


	return *this;
}

CMyString CMyString::operator+(char * pString)
{
	char*		pStr = new char[m_iSize + strlen(pString) + 1];

	strcpy_s(pStr, m_iSize + strlen(pString) + 1, m_pString);
	strcat_s(pStr, m_iSize + strlen(pString) + 1, pString);

	CMyString	Temp(pStr);

	SAFE_DELETE_ARRAY(pStr);

	return Temp;
}

CMyString CMyString::operator+(CMyString & rString)
{
	char*		pStr = new char[m_iSize + strlen(rString.m_pString) + 1];

	strcpy_s(pStr, m_iSize + strlen(rString.m_pString) + 1, m_pString);
	strcat_s(pStr, m_iSize + strlen(rString.m_pString) + 1, rString.m_pString);

	CMyString	Temp(pStr);

	SAFE_DELETE_ARRAY(pStr);

	return Temp;
}

bool CMyString::operator==(char * pString)
{
	return !strcmp(m_pString, pString);
}

bool CMyString::operator==(CMyString & rString)
{
	return !strcmp(m_pString, rString.m_pString);
}

void CMyString::Release(void)
{
	SAFE_DELETE_ARRAY(m_pString);
}
