#include "stdafx.h"

#define			SAFE_DELETE(p) if(p) { delete p; p =nullptr;}

template<typename T>
void	Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

// ���ø��� �����

/*
1. ��� �ڷ����� ȣȯ�Ѵ�.
2. ���ø��� ���Ǵ� ������ ������ Ÿ�ӿ� �̷����� ������ ������ �߻��ϱ� ���� �����Ϸ��� �˻縦 �����Ͽ� �����ϴ�.
3. �����Ϸ��� �Լ� �Ǵ� Ŭ������ �������ֱ� ������ �����ӵ��� ������.

1. �ڷ����� ������ ���������� ������ �����ϱ� ������ �ڵ� ���ȭ�� �ҷ��´�.
2. ���������� ũ�Ⱑ Ŀ����.*/


#pragma region ���ø�

// �Լ� ���ø��� ��(���� ���ø�)
/*
template<typename T>
T		Add(T a, T b)
{
	return a + b;
}

// ���ø� Ư��ȭ : Ư�� �ڷ����� �ش��ϴ� ���ø� ������ ���� �����ϴ� ����
// ���� : ��� �ڷ����� �ش��ϴ� ���ø��� �켱 �����ؾ���
template<>
char* Add(char* a, char* b)
{
	int iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// Ư��ȭ�� ������ ���ø��� �ڷ����� ��õǾ� �ֱ� ������ �Լ� �����ε� ���� ���� �����ȴ�.
template<>
const char* Add(const char* a, const char* b)
{
	int iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// ���� ���ø� : �� �� �̻��� Ÿ���� ���� ���ø�

template<typename T1, typename T2, typename T3>
T3		Add(T1 a, T2 b)
{
return a + b;
}

void main(void)
{
	// ���ø� : Ʋ, �Լ� �Ǵ� Ŭ������ �����ϱ� ���� ����

	// ����� �����Ǿ� ������ �ڷ����� �����Ǿ� ���� ���� ����

	// �Լ� ���ø� : �Լ��� ������� �̷����� �Լ��� �����ϴ� ���ø�
	// ���ø� �Լ� : ���ø��� ���� ������ �Լ�

	cout << Add<short>(5, 10) << endl;	// ���ø� �Լ�

	cout << Add<float>(3.14f, 6.27f) << endl;	// ���ø� �Լ�

	char* pStr = Add<char*>("a", "b");

	cout << pStr << endl;

	delete[]pStr;
	pStr = nullptr;

	const char* pConsStr = Add<const char*>("c", "d");

	cout << pConsStr << endl;

	delete[]pConsStr;
	pConsStr = nullptr;


	double		dNumber = Add<int, float, double>(10, 20.1f);
	cout << dNumber << endl;

}*/
#pragma endregion ���ø�

#pragma region Ŭ���� ���ø�

/*
template<typename T>
class CObj
{
private:
	T		m_X;
	T		m_Y;

public:
	CObj() {}
	CObj(T _X, T _Y) : m_X(_X), m_Y(_Y) {}
	~CObj() {}
};

void main(void)
{
	CObj<int>		IntObj(10, 20);
	CObj<float>		FloatObj(10.f, 20.f);
}*/

/*
template<typename T>
class CObj
{
public:
	T Add(T a, T b)
	{
		return a + b;
	}
};

template<>
class CObj<char*>
{
public:
	char* Add(char* a, char* b)
	{
		int iLength = strlen(a) + strlen(b);

		char*		pString = new char[iLength + 1];

		strcpy_s(pString, iLength + 1, a);
		strcat_s(pString, iLength + 1, b);

		return pString;
	}
};

template<typename T1, typename T2>
class CTest
{

};

// ���� ���ø��� �κ� Ư��ȭ
template<>
class CTest<int, char*>
{

};

template<typename T>
class CTest<T, char*>
{

};*/

/*
template<typename T>
class CObj
{
public:
	T Add(T a, T b);	
	void	Render(T a);
};

template<typename T>
T CObj<T>::Add(T a, T b)
{
	return a + b;
}

template<typename T>
void	CObj<T>::Render(T a)
{
	cout << a << endl;
}


void main(void)
{

}
*/





#pragma endregion Ŭ���� ���ø�

#pragma region static�� ���ø��� ����

template<typename T>
T Func(T Num)
{
	static T Temp = 0;

	Temp += Num;

	return Temp;
}

template<typename T>
class CObj
{
public:
	T Func(T Num)
	{
		m_Temp += Num;

		return m_Temp;
	}

private:
	static T	m_Temp;
};

template<typename T>
T CObj<T>::m_Temp = 0;

template<typename T>
class CMonster : public CObj<T>
{

};


void main(void)
{
	// ���ø� ���� ������ static ������ ���� �ڷ����� ���ø��� ��쿡�� �޸𸮸� �����Ѵ�.

	/*Func<int>(10);
	Func<double>(20.1);
	
	cout << Func<int>(5) << endl;
	cout << Func<double>(3.14) << endl;*/


	//CObj<int>		intObj;
	//CObj<int>		intObj2;

//	CObj<double>	doubleObj;

	//intObj.Func(10);
	//intObj2.Func(20);

	//cout << intObj.Func(0) << endl;
	
	/*doubleObj.Func(20.1);

	cout << intObj.Func(5) << endl;
	cout << doubleObj.Func(3.14) << endl;
*/
}



#pragma endregion static�� ���ø��� ����