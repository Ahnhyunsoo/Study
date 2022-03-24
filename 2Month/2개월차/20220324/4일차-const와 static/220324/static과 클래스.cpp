#include "stdafx.h"

#pragma region ����ν� �����ϴ� static����

/*
static int		g_iA = 10;		// ��������(�ܺο��� ���� ������ ��������)

class CObj
{
public:
	static int		m_iA; // = 10; ����� ���ÿ� �ʱ�ȭ ����

private:
	int				m_iB;

public:
	void	Render()
	{
		//static int		iA = 10; // ��������(���ο��� ���� ������ ��������)
		//cout << (++iA) << endl;

		m_iA++;
		cout << (m_iA) << endl;
	}
	CObj()// : m_iA(10) �̴ϼȶ������� �̿��� �ʱ�ȭ ����
	{
		// m_iA = 10;	������ ���� �ʱ�ȭ ����
	}
};

// Obj.cpp

int		CObj::m_iA = 100;		// ����� �����ϴ� �������� �ʱ�ȭ ����




void main(void)
{
	// ���� ��ü Ÿ�Գ����� STATIC ��� ������ �޸� ������ �����Ͽ� ����Ѵ�.
	// STATIC ��� ������ �� ��ü�� ������ �ƴ϶�� ����


	CObj	Obj;
	Obj.Render();

	//Obj.m_iA = 200;

	CObj::m_iA = 200;		// ��ü ������ �ʿ� ���̵� ����� ������ �����ϴ�.


							/ *CObj	Temp;
							Temp.Render();

							CObj	Dest;
							Dest.Render();* /

}*/

#pragma endregion ����ν� �����ϴ� static����

#pragma region ����ν� �����ϴ� static �Լ�

int	g_iNumber = 10;

class CObj
{
private:
	int			m_iNormal = 20;
	static int  m_iStatic;

public:
	static void Render(void)		// static�� ���� �Լ��� Ŭ���� ���� �Ϲ� ��� ������ ����� �� ����.
	{								// ���� Ŭ���� ���� �ִ��� �Ϲ� ��� �Լ� ���� static �Լ� ������ ȣ�� �� �� ����.
		// ++m_iNormal;
		// Draw();
		
		//cout << (++m_iStatic) << endl;	// static ������ ��밡���ϴ�.
		
		//int	iTemp = 10;				// �Ϲ����� �Լ� �� ���������� ����ϴ� ���� ������ ���� �ʴ´�.
		//cout << (++iTemp) << endl;

		// cout << (++g_iNumber) << endl;	// ���������� ��쵵 ����� �����ϴ�.
	}
	void		Draw(void)
	{
		//cout << (++m_iStatic) << endl;
		cout << m_iNormal << endl;
	}
};

int CObj::m_iStatic = 10;

void main(void)
{
	CObj	Obj;

	//Obj.Render();
	
	CObj::Render();

	Obj.Draw();

}

/*
namespace MyStd
{
	static void Print();
}*/

// 1. static ��� �Լ��� static ��� ������ ������ ����� ������.
// 2. static���� ����� ������ �Լ��� �ش� Ŭ������ ������ ��� ��ü�� �����Ѵ�.
// 3. �� ��ü�� ������ �ƴϴ�
// 4. stiatic ��� �Լ� ���ο��� �Ϲ����� ��� ����, �Լ��� ������ �� ����.
// 5. namespace�� ���� ��ü�� �������� �ʰ� ȣ���� �� �ִ�.
// 6. ���α׷� ���� ��(������ ����) �޸𸮰� �Ҵ�ǰ� ���α׷� ���� �� �޸𸮰� �����ȴ�.
// 7. �Ҵ�Ǵ� �޸� ������ data ������ �ش��Ѵ�.

#pragma endregion ����ν� �����ϴ� static �Լ�

