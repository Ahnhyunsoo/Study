#include <iostream>
#include <bitset>		// �������� ���ϴ� ��Ʈ���� ǥ���ϱ� ���� ����

using namespace std;

void main(void)
{
	/*int		iKorean = 0;
	int		iEnglish = 0;
	int		iMath = 0;*/

	/*int	iKorean = 0, iEnglish = 0, iMath = 0;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iKorean;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iEnglish;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iMath;

	cout << "=================================" << endl;
	cout << "����\t����" << '\t' << "����" << endl;
	cout << iKorean << '\t' << iEnglish << '\t' << iMath << endl;*/

#pragma region ǥ���
	// ���� �̸� ���� ��Ģ

	/*1. ���� ���� ���ĺ��� ���ڷ� ������ �� �ִ�. ��, ���ڰ� ���ĺ����� ���� �� �� ����. ���ڴ� �ݵ�� ���ĺ� �� �� �̻� �Է� �� ��� ����
	2. ���� ���� ��ҹ��ڸ� Ȯ���� �����ؾ� �Ѵ�.
	3. ���α׷��ֿ��� �����ϴ� �⺻ Ű����δ� �̸��� ���� �� ����.
		ex) int	namespace; // �Ұ���
	4. ���� �Ǵ� Ư�� ���ڰ� �� �� ����. ��, _�� ���
	5. ���� �̸��� ������ �ٽ� ������ �� ����.(������)*/
		
	// 1. �밡���� ǥ��� : ���� �� �տ� �� �ڷ����� ��¡�ϴ� ���ڸ� �����ϴ� ���
	// ex) int iTemp; float fTemp;

	// 2. ī�� ǥ��� : �ܾ�� �ܾ� ���̸� �빮�ڷ� �����ϴ� ���
	// ex) int	playerHp;

	// 3. �Ľ�Į ǥ��� : �������� ������ �빮�ڷ� ����, ���վ��� ��� �߰��� �����ϴ� ���ο� �ܾ��� ù ���ڵ� �빮�ڷ� ǥ��
	// ex) int PlayerHp;

	// 4. ����� ǥ��� : �ܾ�� �ܾ� ���̿� _�� ���, �ַ� �Լ� �Ű� ������ ���
	// ex) void Func(int _iPlayerHp);

#pragma endregion ǥ���

#pragma region ������

	// ��� ������(+, -, *, /, %)
	int a = 10;
	int b = 2;
	if (a % b != 0)


	// int		iTemp = 10 + 20;
	// cout << iTemp << endl;
	/*
	int		iResult = 20 % 6;
	cout << iResult << endl;

	iResult = 20 / 6;
	cout << iResult << endl;*/

	// sizeof ������ : �ڷ����� ũ�⸦ ����Ʈ ������ ������ִ� ������
	// �迭�� �̸��� �����ڸ� �̿��Ͽ� ũ�⸦ ���� ��� �迭 ��ü�� ũ�⸦ ����� �ش�.

	//int	iTemp = 10;

	/*cout << sizeof(char) << endl;
	cout << sizeof(bool) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(iTemp) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long double) << endl;*/

	//char	A = 'A';
	//char	B = 'B';

	//cout << sizeof(A + B) << endl;	// ������ ����� 4����Ʈ�� ���´�. char�� �������� �����ϴ� �ڷ����̱⵵ �ϴ�. ���� ������ 65 + 66�̶� ������̰�
									// ����� ������ 131�� �Ϲ����� ����Ÿ���̱� ������ �����Ϸ��� �ӽ� �޸� ������ int�� ũ�� ��ŭ�� 4����Ʈ�� �Ҵ��ϰ� ������ �Ϳ� �ش��Ѵ�.

	// = ���� ������(�Ҵ� ������)
	// 1. �����ڸ� �������� ���װ� ������ �ڷ����� �ݵ�� ��ġ�ؾ� �Ѵ�.
	// 2. ���� �����ڸ� �������� �����ʿ� �ִ� �����Ͱ� �������� ������ �߻��Ѵ�.
	
	/*int	iA = 10, iB = 20, iC = 30;
	
	//int iD(40);		// c++�ʱ�ȭ ���
	iA = iB = iC = 200;

	cout << iA << "\t" << iB << "\t" << iC << endl;

	int iTemp = 3.14f;
	cout << iTemp << endl;*/

	// ���� ������ : �����ڸ� �������� ���װ� ������ ����� �Ǵ��ϴ� ������, ��� ������ �� �Ǵ� ������ �Ǻ�
	// <, > <=, >=, ==, !=

	/*int	iTemp = 10, iSour = 20;

	cout << (iTemp < iSour) << endl;		// 1
	cout << (iTemp > iSour) << endl;		// 0 
	cout << (iTemp <= iSour) << endl;		// 1
	cout << (iTemp >= iSour) << endl;		// 0
	cout << (iTemp == iSour) << endl;		// 0	
	cout << (iTemp != iSour) << endl;		// 1*/

	// �� ������ : �����ڸ� �������� ���װ� ������ ���� ���¿� ���� �� �Ǵ� ������ ��ȯ�ϴ� ������
	// &&(and), ||(or), !(not)

	// and ������ :�����ڸ� �������� ���� �� ���� �� ���� ��ȯ�ϴ� ������
/*
	cout << (false && false) << endl;
	cout << (false && true) << endl;
	cout << (true && false) << endl;
	cout << (true && true) << endl;*/


	// or ������ : �����ڸ� �������� ������ ���̸� ������ ���� ��ȯ�ϴ� ������

	/*cout << (false || false) << endl;
	cout << (false || true) << endl;
	cout << (true  || false) << endl;
	cout << (true  || true) << endl;*/


	// not ������ : ���� �������� ������ ������ ������ִ� ������
	// bool		bChoice = true;
	// cout << (!bChoice) << endl;

#pragma endregion ������

#pragma region ��Ʈ ���� ������

// &(and), |(or), ~(not), ^(xor)

int		iTemp = 10;
int		iSour = 13;
			// <�� ��Ʈ�� ǥ���� ���ΰ�>(������)
cout << bitset<8>(iTemp) << endl;
cout << bitset<8>(iSour) << endl;

cout << "===========================" << endl;
//cout << bitset<8>(iTemp &iSour) << endl;
//cout << bitset<8>(iTemp |iSour) << endl;
// cout << bitset<8>(iTemp ^ iSour) << endl;
cout << bitset<8>(iTemp ^ iSour) << endl;
cout << (~iTemp) << endl;

#pragma endregion ��Ʈ ���� ������








		 

}