// 20220331����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

namespace AHS
{
	class Mystring
	{
	private:
		char* sA;
		char Temp[10000];
		char* Myendl = "\n";
		int Length;
		int count;

	public:
		void Print() { cout << sA; }
		

		Mystring& operator = (char* a)
		{
			sA = a;
			return *this;
		}

		Mystring& operator + (Mystring& r)
		{
			Length = 0; 
			count = 0;
			for (int i = 0; i >= 0;)
			{
				if (*(sA+i) != NULL)
				{
					Temp[i] = *(sA+i);
					++i;
				}
				else
				{
					Length = i;
					break;
				}
			}
			
			for (int i = Length; i >= 0;)
			{
				if (*(r.sA+count) != NULL)
				{
					Temp[i] = *(r.sA + count);
					++i;
					++count;
				}
				else
				{
					sA = Temp;
					break;
				}
			}

			return *this;
		}

		Mystring& operator - (Mystring& r)
		{
			Length = 0;
			count = 0;

			for (int i = 0; i >= 0;)
			{
				if (*(sA + i) != NULL)
				{
					++i;
				}
				else
				{
					Length = i;
					break;
				}
			}

			for (int i = 0; i >= 0;)
			{
				if (*(r.sA + i) != NULL)
				{
					++i;
				}
				else
				{
					count = i;
					break;
				}
			}

			if (Length <= count)
			{
				sA = "";
			}
			else
			{
				for (int i = 0; i < Length - count; ++i) 
				{
					Temp[i] = *(sA + i);
				}
				sA = Temp;
			}
			return *this;
		}

		int operator == (Mystring& r)
		{

			if (sA == r.sA)
			{
				return 0;
			}

			else
			{
				return 1;
			}

			/*for (int i = 0; i >= 0;)
			{
				if (*(sA + i) != NULL)
				{
					++i;
					++Length;
				}
			}

			for (int i = 0; i >= 0;)
			{

			}*/

		}
		

		Mystring&	operator << (Mystring a)
		{
			a.Print();

			return *this;
		}

		Mystring&	operator << (char* a)
		{
			
			cout << a;
			return *this;
		}


		Mystring() 
		{
			sA = new char;
			sA = "";
		}

		Mystring(char* a)
		{
			sA = a;
		}
		~Mystring()
		{

		}

	};

	Mystring e;
	Mystring Mycout;
	char* Myendl = "\n";
	
	
}

using namespace AHS;

void main(void)
{
	/*Mystring a = "aa";
	Mystring b = "bb";
	a = a;

	Mycout << a << b << Myendl;*/

	/* ����
	Mystring a;
	a = "��°�����";
	Mystring b;
	b = "���";
	a = b;
	*/

	/* ����
	Mystring a;
	a = "��°�����";
	Mystring b;
	b = "���";
	
	a = a+b;
	*/

	/* ����
	Mystring a;
	a = "��°�����";
	Mystring b;
	b = "���";

	a = a-b;
	//������ �� Ŭ�� �������� ó��
	*/


	
	Mystring a = "sss";
	Mystring b = "ss";
	
	if ((a == b) == 0)
	{
		Mycout << "����" << Myendl;
	}
	else
	{
		Mycout << "�ٸ�" << Myendl;
	}




	//C << a << ENDL;
}


	/*class Ostream
	{
	public:
		Ostream&	operator <<(int iDest)
		{
			printf("%d", iDest);

			return *this;
		}

		Ostream&	operator <<(char* pDest)
		{
			printf("%s", pDest);

			return *this;
		}
	};

	Ostream		COUT;
	char*		ENDL = "\n";
	}

using namespace MyStd;

void main(void)
{
	COUT << 100 << ENDL;
}
	*/




