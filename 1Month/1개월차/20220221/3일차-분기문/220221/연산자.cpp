#include <iostream>
#include <bitset>

using namespace std;

void main(void)
{
#pragma region ����Ʈ ������

	// ����Ʈ ������ : �� ��Ʈ�� ����, ���������� �̵���Ű�� ������
	// ���� ����Ʈ ������ ��� 2�� n������ŭ ���ϱ� ������ �����ϸ�, �����÷ο찡 �߻����� �ʵ��� �����ؾ� �Ѵ�.
	// ������ ����Ʈ ������  ��� 2�� n������ŭ ������ ������ �����Ѵ�.
	
	/*int		iTemp = 10;

	cout << bitset<8>(iTemp) << endl;
	cout << "=====================" << endl;
	cout << bitset<8>(iTemp << 2) << endl;*/

#pragma endregion ����Ʈ ������

#pragma region ���� ������

	// ++, -- : �ϳ��� ���� �Ǵ� ���� ��Ű�� ������

	// 1. ����� ���� �����ڸ� ����� �� ����.
	// ex) ++10;

	// 2. ���� �����ڰ� �پ��ִ� ��ġ�� ���� ����� �޶�����.

	/*int	iNumber = 10;

	++iNumber;		// ���� ���� : �� ���� �� ����

	iNumber++;		// ���� ���� : �� ���� �� ����

	cout << iNumber << endl;*/

	/*int iNumber = 3;

	while (iNumber--)
	{
	cout << 1 << endl;
	}*/

	// 3. ���� ������ ���� ���޾Ƽ� ����� �����ϴ�.

// 	/*int iNumber = 3;
// 	cout << (++(++iNumber)) << endl;*/

#pragma endregion ���� ������

#pragma region ������ ���

	// �ڱ� �ڽ��� ���� ��ȭ�� �� �������� ���¸� �ٿ��� ǥ���� �� �ִ�.

	// int	iNumber = 10;

	// iNumber = iNumber + 20;
	// iNumber += 20;	// -, *, /, % � ��������� ǥ���� �����ϴ�

	// cout << iNumber << endl;

#pragma endregion ������ ���

#pragma region ���� ������

	// ������ ������ �̿��Ͽ� ���� �����ϰ��� �� �� �Ǵ� �ܼ� ���ǽ��� �ذ��ϰ��� �� �� ���� ���ȴ�.
	/*
	int		iNum = 10;
	int		iNum2 = 20;

	int		iResult = 0;

	// ���  = ���� ? ���� ��� ��ȯ : ������ ��� ��ȯ
	iResult  = (iNum > iNum2) ? iNum : iNum2;

	cout << iResult << endl;*/

#pragma endregion ���� ������


	int		iKor = 0, iEng = 0, iMath = 0, iTotal = 0;
	float	fAver = 0.f;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iKor;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iEng;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iMath;

	// �� ��ȯ(ĳ����) : ����ڰ� ���α׷� �ڵ� ���࿡ ���� ���ϴ� �ڷ������� ���������� ��ȯ�ϴ� ��

	iTotal = iKor + iEng + iMath;
	// fAver  = iTotal / 3.f;			// ������ �� ��ȯ

	fAver = (float)iTotal / 3.f;		// ����� �� ��ȯ

	cout << "����\t����\t����\t����\t���" << endl;
	cout << iKor << "\t" << iEng << "\t" << iMath << "\t" << iTotal << "\t" << fAver << endl;


}