#include <iostream>

using namespace std;

void Render();
int Add(int iA, int iB);
int Minus(int iA, int iB);
int Mul(int iA, int iB);
int Div(int iA, int iB);


int Get_A(int iA);

void main(void)
{
	/*�Լ� ������ : �Լ��� �̸��� �����ϱ� ���� ������

	�迭�� �̸��� �迭 ��ü ���� �� ù ��° ������ �ּ� ��
	�Լ��� �̸� ���� �Լ��� ��ϵ� �޸� ����(code����)�� �ּ� ���� �ش��Ѵ�.*/
	//cout << Render;   //() = �Լ� ȣ�� ������

	// �Լ� �������� ����

	//Ÿ��(*������)(�Ű�����) : �߰� ������ �־ �������
	/*void(*ptrVoid)(void) = Render;
	ptrVoid();

	int(*ptrGet_A)(int) = Get_A;
	cout << ptrGet_A(10) << endl;

	int(*ptrAdd)(int, int) = Add;
	cout << ptrAdd(20, 30) << endl;*/

#pragma region �Լ������� ��� ��
	/*int iInput = 0;
	int iResult = 0;
	cout << "1. ���� 2. ���� 3. ���� 4. ������ : ";
	cin >> iInput;

	int(*ptrAdd)(int, int) = Add;

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
	}*/
	int iInput = 0;
	+
	int(*ptr[4])(int, int) = { Add,Minus,Mul,Div }; // 16����Ʈ

	cin >> iInput;
	cout << ptr[iInput - 1](10, 20) << endl;


	

}

void Render()
{
	cout << 1 << endl;
}

int Add(int iA, int iB)
{
	return iA + iB;
}

int Get_A(int iA)
{
	return iA;
}


int Minus(int iA, int iB)
{
	return iA - iB;
}
int Mul(int iA, int iB)
{
	return iA * iB;
}
int Div(int iA, int iB)
{
	return iA / iB;
}

/*
1. 0 ���� �̵�
5 * 5 �迭�� 0 ~ 24 ���� ���
2(�Ʒ�) 4(����) 6(������) 8(����)���� ���� 0�� �̵�

���� ������ ����ϰ� �� �� �ִ�.

���̻� �� ������ ������ �̵����� �ʴ´�.
0	1	2			1	0	2			1	4	2			1	4	2
3	4	5	6���Է� 3	4	5 2�� �Է�	3	0	5 4�� �Է�  0	3	5
6	7	8			6	7	8			6	7	8			6	7	8


2. ���ڿ��� �Է� �޾� null���ڸ� ������ ���� ���ڿ��� ���̸� ���ϴ� �Լ��� ������(strlen ��� ����)

3. �Է� ���� ���ڿ��� ������ �Լ� �����
ex jusin �� �Է¹����� nisuj�� ���

���� ���� ���� �ݺ�
4. 3���� �Է� ������ ����ǥ ���α׷� �����(�̸�, ����, ����, ����, ����, ���) (����ü ��� ����)

1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ����






*/