#include <iostream>
#include <random>

using namespace std;

void main(void)
{

#pragma region ���� 1��
	/* ���������� ���� 
	���� 0~2 ���� ����
	1���� 2���� 3�� �Է¹޾� �� �� �� �Ǻ�
	��5���� ����(������ ����)
	*/
	//random_device random;
	//mt19937 rd(random());
	//uniform_int_distribution<int> range(1, 3);
	//

	//int iRandom = 0; // ������ �����ϴ� ����
	//int iNum = 0; // ������������ �Ǻ��ϴ� ����
	//int iWin = 0; // �¸��� �����ϴ� ����
	//int iLose = 0; // �й踦 �����ϴ� ����
	//int iDraw = 0; // ���ºθ� �����ϴ� ����

	//for (int i = 0; i < 5; ++i) {
	//	iRandom = range(rd);
	//	cout << "  ���������� �����Դϴ�  " << endl;
	//	cout << "1.���� 2.���� 3.�� 4.����" << endl;
	//	cin >> iNum;
	//	system("cls");

	//	if (iNum == 1) {
	//		if (iRandom == 3)
	//		{
	//			iWin += 1;
	//		}
	//		if (iRandom == 2)
	//		{
	//			iLose += 1;
	//		}
	//		if (iRandom == 1)
	//		{
	//			iDraw += 1;
	//		}
	//	}
	//	
	//	if (iNum == 2) {
	//		if (iRandom == 1)
	//		{
	//			iWin += 1;
	//		}
	//		if (iRandom == 3)
	//		{
	//			iLose += 1;
	//		}
	//		if (iRandom == 2)
	//		{
	//			iDraw += 1;
	//		}
	//	}

	//	if (iNum == 3) {
	//		if (iRandom == 2)
	//		{
	//			iWin += 1;
	//		}
	//		if (iRandom == 1)
	//		{
	//			iLose += 1;
	//		}
	//		if (iRandom == 3)
	//		{
	//			iDraw += 1;
	//		}
	//	}

	//	if (iNum == 4) {
	//		cout << "���� : " << iWin << "�� " << iDraw << "�� " << iLose << "�� " << endl;
	//		cout << "������ �����մϴ�." << endl;
	//		break;
	//	}

	//	if ((iWin + iLose + iDraw) == 5)
	//	{
	//		cout << "���� : " << iWin << "�� " << iDraw << "�� " << iLose << "�� " << endl;
	//		cout << "������ �����մϴ�." << endl;
	//		break;
	//	}

	//}


#pragma endregion ���� 1��



#pragma region ���� 2��
	/*
	for���� �̿��� ������ ��� ����for�� ���
	*/

	/*for (int i = 2; i < 10; ++i)
	{
		cout << "===================" << endl;
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << (i*j) << endl;
		}
	}*/

#pragma endregion ���� 2��

#pragma region ���� 3��
	/*
	for���� �̿��Ͽ� �ܼ��� ���� �Է¹޾� �������� ���
	ex) 5�� 4�� = 2~5�� *4 
	*/
	
	//int iNum1 = 0; // ���� �����ϴ� ����
	//int iNum2 = 0; // ���� �����ϴ� ����
	//int iCount = 0; // 0���� iNum2���� �����ϴ� ����

	//cout << "�ܼ��� �Է��ϼ��� : " << endl;
	//cin >> iNum1;
	//cout << "���� �Է��ϼ��� : " << endl;
	//cin >> iNum2;
	//cout << endl;
	//
	//for (int i = 2; i <= iNum1; ++i)
	//{
	//	cout << "================" << endl;
	//	for (int j = 1; j <= iNum2; ++j)
	//	{		
	//		cout << i << " * " << j << " = " << (i*j) << endl;
	//	}
	//}



#pragma endregion ���� 3��

#pragma region ���� 4��
	/*
		���������� ����Ͽ� �Ƕ�̵� ���
	*/



	/*for (int i = 1; i < 6; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 6; i > 1; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}


	



	for (int i = 1; i < 6; ++i)
	{	
		for (int j = 5; j > i; --j)
		{
			cout << " ";			
		}
		for (int k = 0; k < i; ++k)
		{
			cout << "*";
		}
		cout << endl;
		
	}

	cout << endl;

	for (int i = 1; i < 6; ++i)
	{
		
		for (int j = 1; j < i; j++)
		{
		cout << " ";
		}
		for (int k = 6; k > i; --k)
		{
			cout << "*";
		}
		
		cout << endl;
	}*/
	
	
	
	

	
	


	
	


	

	

#pragma endregion ���� 4��


}