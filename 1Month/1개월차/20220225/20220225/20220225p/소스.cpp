#include <iostream>

using namespace std;

#pragma region ����Լ�
// ��� �Լ� : �ڱ� �ڽſ��� ���ư��� �Լ���� ������ �ڽ��� �ٽ� ȣ���ϴ� ������ �Լ��� ���ϳ�.
// �ݵ�� Ż�� ������ �����߸� �Ѵ�. �ȱ׷��� ���� ������ ������.
void Return(int iNumber);

void main(void)
{
	Return(5);
}

void Return(int iNumber)
{
	if (0 >= iNumber)
		return;

	cout << "��� ȣ��" << endl;
	--iNumber;
		Return(iNumber);
}

#pragma region �޸�
int iTemp = 0;	// ������ ������ �Ҵ�Ǵ� ���� ���� : �� ���� �ȿ����� ���������� ����� ������ ����
int iTest = 4000;

void Plus(void)
{
	//int iTemp = 10; // ���� �޸𸮿� �Ҵ�� ���� ����(�� ���� �ȿ����� ��ȿ�� �̸�)
	iTemp = 100;

	cout << iTemp << endl;
}

void Minus(void)
{	
	iTemp = 200;
	cout << iTemp << endl;
}

void Add(void)
{
	static int iTest = 1000; // �����Ϳ����� �Ҵ�Ǵ� ���� ���� : ���� ������ �����ϸ�, ���������� �޸� ��밡���� ����
	cout << ++iTest << endl;
}
#pragma endregion �޸�

void Render(int _iA , int _iB = 100);// ����Ʈ �Ű����� (�� ���ʺ��� ���ʴ�� ���� ä���� �����)
void Print(int); 

#pragma region �Լ�
//�Լ� �����ε� : �̸��� ���� �� �Ű������� ����, �ڷ��� Ÿ�Կ� ���� � �Լ��� ȣ��� �� �����Ǵ� ����
//��ȯ Ÿ���� �ٸ��ٴ� ������ �Լ� �����ε��� ���������� �ʴ´�.
//�Լ� �����ε� �� ����Ʈ �Ű������� Ȯ���ϴ� �Լ��� ȣ�� ��ȣ���� �߻���Ű���� �ʴ��� ����ؾ� �Ѵ�.


//void Draw(int);


namespace A
{
	void Draw(void) { cout << "A" << endl; }
}

namespace B
{
	void Draw(void) { cout << "B" << endl; }
}

using namespace A;



void Render(int _iA , int _iB) 
{
	cout << _iA << endl;
	cout << _iB << endl;
}

void Draw()
{
	cout << "Draw" << endl;
}

void Draw(int _iTemp)
{
	cout << "int" << endl;
}

void Draw(float _fTemp)
{
	cout << "float" << endl;
}

void Draw(int _iTemp, int _iSour)
{
	cout << _iTemp << _iSour << endl;
}

void Print(int)
{
	cout << "���" << endl;
}
#pragma endregion �Լ�

// 5 ���丮���� �Լ��� �����϶�


// 5! = 5 * 4 * 3 * 2 * 1
// ����Լ��� �̿��ؼ� �����϶�

