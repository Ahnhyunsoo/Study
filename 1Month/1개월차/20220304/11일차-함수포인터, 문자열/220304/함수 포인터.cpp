#include <iostream>

using namespace std;

void	Render();

int		Add(int iA, int iB);
int		Minus(int iA, int iB);
int		Mul(int iA, int iB);
int		Div(int iA, int iB);

int		Get_A(int iA);

void main(void)
{
	// �Լ� ������ : �Լ��� �̸��� �����ϱ� ���� ������

	// �迭�� �̸��� �迭 ��ü ���� �� ù ��° ������ �ּ� ��
	// �Լ��� �̸� ���� �Լ��� ��ϵ� �޸� ����(code����)�� �ּ� ���� �ش��Ѵ�.

	// �Լ� �������� ����

	// Ÿ��(*������)(�Ű�����) : �߰� ������ �־ �������

	/*void(*ptrVoid)(void) = Render;
	ptrVoid();

	int(*ptrGet_A)(int) = Get_A;
	cout << ptrGet_A(10) << endl;

	int(*ptrAdd)(int, int) = Add;
	cout << ptrAdd(20, 30) << endl;*/

	
#pragma region �Լ������� ��� ��

	/*int iInput = 0;
	int iResult = 0;

	int(*ptrAdd)(int, int) = nullptr;

	cout << "1. ���� 2. ���� 3. ���� 4.������ : ";
	cin >> iInput;

	/ *switch (iInput)
	{
	case 1:
		iResult = Add(10, 20);
		break;
	case 2:
		iResult = Minus(10, 20);
		break;
	case 3:
		iResult = Mul(10, 20);
		break;
	case 4:
		iResult = Div(10, 20);
		break;
	}* /

	switch (iInput)
	{
	case 1:
		ptrAdd = Add;
		break;
	case 2:
		ptrAdd = Minus;
		break;
	case 3:
		ptrAdd = Mul;
		break;
	case 4:
		ptrAdd = Div;
		break;
	}

	cout << "��� : " << ptrAdd(10, 20) << endl;*/


#pragma endregion �Լ������� ��� ��

#pragma region �Լ� ������ ��� �� 2

	/*int iInput = 0;
	int iResult = 0;

	// �Լ� ������ �迭
	int(*ptr[4])(int, int) = { Add, Minus, Mul, Div };

	cout << "1. ���� 2. ���� 3. ���� 4.������ : ";
	cin >> iInput;

	cout << "��� : " << ptr[iInput - 1](10, 20) << endl;*/
	
#pragma endregion �Լ� ������ ��� �� 2


}
void	Render()
{
	cout << 1 << endl;
}
int		Get_A(int iA)
{
	return iA;
}


int		Add(int iA, int iB)
{
	return iA + iB;
}
int		Minus(int iA, int iB)
{
	return iA - iB;
}
int		Mul(int iA, int iB)
{
	return iA * iB;
}
int		Div(int iA, int iB)
{
	return iA / iB;
}







