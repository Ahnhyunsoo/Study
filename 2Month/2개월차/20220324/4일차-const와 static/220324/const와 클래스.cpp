// 220324.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#pragma region ��� ����� �ʱ�ȭ�ϴ� ���

/*
class CObj
{
private:
	const int			m_iA;
	int					m_iB;

public:
	void		Render(void) { cout << m_iA << endl; }

public:
	CObj();
	CObj(int _iA, int _iB);
};

CObj::CObj()
	: m_iA(10), m_iB(100) // �̴ϼȶ������� �̿��� �ʱ�ȭ ���
{
	//m_iB = 100;		// ������ �޸𸮿� ������ ���� �ʱ�ȭ

}
CObj::CObj(int _iA, int _iB)
	: m_iA(_iA), m_iB(_iB)
{

}
*/

class Test
{
private:
	const int a;

public:
	void Print() { cout << a << endl; }
	Test(int a) : a(a) {}
};

int main()
{
	Test t;

	t.Print();


	return 0;
}


#pragma endregion ��� ����� �ʱ�ȭ�ϴ� ���

#pragma region Ŭ���� �ȿ��� �����ϴ� �Լ��� ���ȭ

// �Ϲ����� ��� �Լ��� ��� ��ȯ Ÿ�� �Ǵ� �Ű� ������ const�� &�� ���̰� �Ǹ� �� ������ �Ұ����ϱ� ������ ����ؼ��� �� �ȴ�.

/*
class CObj
{
private:
	const int		m_iA = 10;
	int				m_iB = 0;

public:
	const int&		Get_A(void) const
	{ 
		return m_iA; 
	}
		
	void		Set_A(const int& _iB)	// �Ű������� ����� �޾Ƽ� �� ������ ���� �ʴ� ��� ����ϴ� �б� ���� �Ű�����
	{									// �޸� ���簡 �߻��� �� ����, const�� �پ� �ֱ� ������ �� ������ �Ұ����ϴ�.
		//_iB += 10;
		m_iB = _iB;
	}

public:
	void	Render(void) const			// �б� ���� �Լ�
	{ 
		// m_iA = 20;					// ���� ����� �����ϰ� �ִ� �ڵ�, const �Լ� �������� �̿� ���� ������ �� �� ����.

		cout << "Hello World" << endl;
		//cout << m_iA << endl; 

		Draw();						// draw�Լ������� ������ ���� ���ɼ��� ���� �ֱ� ������ �����Ϸ��� �̿� ���� ȣ���� ������� �ʴ´�.
	}								// ���� draw�Լ� ���� const�� ���� �б� �����̶�� �����Ϸ��� ������ ������ ���ɼ��� ���� ���� �����Ͽ� ȣ���� ����Ѵ�.

	void		Draw(void) const;
	void		Draw(void);
};

void	CObj::Draw() const
{
	cout << "jusin" << endl;
}

void	CObj::Draw()
{
	cout << "�Ϲ� �Լ�" << endl;
}

void main(void)
{
	CObj	Obj;

	//Obj.Render();

	//Obj.Draw();

	cout << Obj.Get_A() << endl;

	int iTemp = 200;

	Obj.Set_A(iTemp);

	//const CObj		Temp;
	//Temp.Draw();


	/ *int	a = 10;

	int& r = a;

	const int& r2 = 10;
	
	cout << r2 << endl;* /

}*/

#pragma endregion Ŭ���� �ȿ��� �����ϴ� �Լ��� ���ȭ

