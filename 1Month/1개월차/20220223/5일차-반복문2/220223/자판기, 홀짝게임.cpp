#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
#pragma region ���Ǳ� �����

	/*int		iCoin = 0, iInput = 0;
	int		iCoke = 100, iCider = 200, iFanta = 300;
	bool	bExit = true;

	cout << "�ݾ��� �Է��ϼ��� : ";
	cin >> iCoin;

	while (bExit)
	{
		system("cls");
		cout << "������ : " << iCoin << endl;
		cout << "1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ : ";
		cin >> iInput;

		/ *if (1 == iInput)
		{
		if (iCoin >= iCoke)
		{
		cout << "�ݶ� ���� �Ϸ�!" << endl;
		iCoin -= iCoke;
		}
		else
		cout << "�������� �����մϴ�" << endl;
		}
		else if (2 == iInput)
		{
		if (iCoin >= iCider)
		{
		cout << "���̴� ���� �Ϸ�!" << endl;
		iCoin -= iCider;
		}
		else
		cout << "�������� �����մϴ�" << endl;
		}
		else if (3 == iInput)
		{
		if (iCoin >= iFanta)
		{
		cout << "ȯŸ ���� �Ϸ�!" << endl;
		iCoin -= iFanta;
		}
		else
		cout << "�������� �����մϴ�" << endl;
		}
		else if (4 == iInput)
		{
		cout << "�Ž��� ���� " << iCoin << "�� �Դϴ�. " << endl;
		bExit = false;
		}
		else
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;* /

		switch (iInput)
		{
		case 1:

			if (iCoin >= iCoke)
			{
				cout << "�ݶ� ���� �Ϸ�!" << endl;
				iCoin -= iCoke;
			}
			else
				cout << "�������� �����մϴ�" << endl;

			break;

		case 2:

			if (iCoin >= iCider)
			{
				cout << "���̴� ���� �Ϸ�!" << endl;
				iCoin -= iCider;
			}
			else
				cout << "�������� �����մϴ�" << endl;

			break;

		case 3:

			if (iCoin >= iFanta)
			{
				cout << "ȯŸ ���� �Ϸ�!" << endl;
				iCoin -= iFanta;
			}
			else
				cout << "�������� �����մϴ�" << endl;

			break;

		case 4:

			cout << "�Ž��� ���� " << iCoin << "�� �Դϴ�. " << endl;
			bExit = false;
			break;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			break;
		}

		system("pause");
	}*/

#pragma endregion ���Ǳ� �����

#pragma region Ȧ¦ �Ǻ��ϱ�

/*
int	iInput = 0, iCount = 5, iWin = 0, iLose = 0, iRandom = 0;
bool bExit = true;

srand(unsigned(time(NULL)));

while ((0 < iCount) && bExit)
{
	system("cls");

	iRandom = rand() % 10 + 1;
		
	cout << "������ " << iRandom << "�Դϴ�. �˰� ���ߴ� �����̿���" << endl;
	cout << "1. Ȧ 2. ¦ 3. ���� : ";
	cin >> iInput;

	--iCount;

	iRandom %= 2;

	if (1 == iInput)
	{
		if (1 == iRandom)
		{
			cout << "��ǻ�� : Ȧ" << endl;
			cout << "����� : Ȧ" << endl;
			cout << "�����Դϴ�" << endl;
			++iWin;
		}
		else
		{
			cout << "��ǻ�� : ¦" << endl;
			cout << "����� : Ȧ" << endl;
			cout << "�����Դϴ�" << endl;
			++iLose;
		}
	}

	else if (2 == iInput)
	{
		if (1 == iRandom)
		{
			cout << "��ǻ�� : Ȧ" << endl;
			cout << "����� : ¦" << endl;
			cout << "�����Դϴ�" << endl;
			++iLose;
		}
		else
		{
			cout << "��ǻ�� : ¦" << endl;
			cout << "����� : ¦" << endl;
			cout << "�����Դϴ�" << endl;
			++iWin;
		}

	}

	else if (3 == iInput)
	{
		bExit = false;
	}
	else
	{
		cout << "�߸� �Է��Ͽ����ϴ�" << endl;
		++iCount;
	}

	system("pause");
}

system("cls");
cout << "�� : " << iWin << "\t�� : " << iLose << endl;
system("pause");*/

#pragma endregion Ȧ¦ �Ǻ��ϱ�

	
}
