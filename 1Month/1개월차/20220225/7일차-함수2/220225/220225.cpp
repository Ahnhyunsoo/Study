#include <iostream>

using namespace std;

#pragma region data ������ stack ������ Ư��
/*
int		iTemp;			// ������ ������ �Ҵ�Ǵ� ���� ���� : �� ���� �ȿ����� ���������� ����� ������ ����
						//int		iTest = 4000;

static	int	iTest = 3000;

void	Plus(void)
{
	//int iTemp = 10;		// ���� �޸𸮿� �Ҵ�� ���� ����(�� ���� �ȿ����� ��ȿ�� �̸�)

	// cout << ++iTemp << endl;

	iTemp = 100;
	cout << iTest << endl;
}

void	Minus(void)
{
	//int iTemp = 10;
	//cout << (--iTemp) << endl;

	iTemp = 200;
	cout << iTemp << endl;
}

void		Add(void)
{
	static int	iTest = 1000;		// ������ ������ �Ҵ�Ǵ� ���� ���� : ���� ������ �����ϸ�, ���������� �޸𸮸� �����Ͽ� ����� �� �ִ�.

	cout << iTest << endl;

	cout << (++iTest) << endl;
}


void main(void)
{
	/ *int	iA = 10;
	int	iB = 20;
	int	iC = 30;* /

	//Plus();
	//Minus();
	//Add();
	//Add();
	//Add();

	//cout << iTest << endl;

	cout << iTemp << endl;

}*/
#pragma endregion data ������ stack ������ Ư��

#pragma region �߰����� �Լ� ����

/*
void	Render(int	_iA, int _iB = 0);		// ����Ʈ �Ű����� : �� ���ʺ��� ���ʴ�� ���� ä���� ���
void	Print(int);

// �Լ� �����ε� : �Լ��� �̸��� ���� ��, �Ű� ������ ����, �ڷ��� Ÿ�Կ� ���� � �Լ��� ȣ��� �� �����Ǵ� ����
// ��ȯ Ÿ���� �ٸ��ٴ� ������ �Լ� �����ε��� ���������� �ʴ´�.
// �Լ� �����ε� ��, ����Ʈ �Ű������� Ȱ���ϴ� �Լ��� ȣ�� ��ȣ���� �߻���Ű���� �ʴ��� ����ؾ� �Ѵ�.

/ *
void	Draw();				//	1
void	Draw(int _iTemp);	//  2
void	Draw(float _fTemp);	//  3* /
// int		Draw(int _iTemp);	//  4
// void	Draw(int _iTemp, int _iSour = 0); //5

namespace A
{
	void	Draw(void) { cout << "A" << endl; }
}

namespace B
{
	void	Draw(void) { cout << "B" << endl; }
}

/ *
using A::Draw;

using std::cout;* /

void main(void)
{
	//Render(200);
	//Print(10);

	A::Draw();
}
*/

/*
void	Render(int	_iA, int _iB)
{
	cout << _iA << endl;
	cout << _iB << endl;
}

void Print(int)
{
	cout << "���" << endl;
}

void	Draw()
{
	cout << "Draw" << endl;
}
void	Draw(int _iTemp)
{
	cout << "_iTemp Draw" << endl;
}
void	Draw(float _fTemp)
{
	cout << "_fTemp Draw" << endl;
}*/
/*
void	Draw(int _iTemp, int _iSour)
{
	cout << "_iTemp _iSour" << endl;
}*/
/*
int		Draw(int _iTemp)
{
	return _iTemp;
}*/

#pragma endregion �߰����� �Լ� ����

#pragma region ��� �Լ�

// ��� �Լ� : �ڱ� �ڽſ��� ���ư��� �Լ���� ������ �ڽ��� �ٽ� ȣ���ϴ� ������ �Լ��� ���Ѵ�.
// �ݵ�� Ż�� ������ �����߸� �Ѵ�. �ȱ׷��� ���� ������ ������ �ȴ�.

// void	Return();  ���� ��

void	Return(int iNumber);

void main(void)
{
	Return(5);
}

/*
void	Return()
{
	cout << "��� ȣ��" << endl;
	Return();
}*/
void	Return(int iNumber)
{
	if (0 >= iNumber)
		return;

	cout << "��� ȣ��" << endl;

	Return(--iNumber);
}

#pragma endregion ��� �Լ�


// 5 ���丮���� �Լ��� �����϶�
// 5! = 5 * 4 * 3 * 2 * 1