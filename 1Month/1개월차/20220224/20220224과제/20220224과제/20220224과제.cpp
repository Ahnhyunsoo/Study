#include <iostream>

using namespace std;

void Menu(int _iMoney);
int Buy(int _iMoney, int _iNum); 
void Exe(void);

void main(void)
{
	Exe();
}

int Buy(int _iMoney, int _iNum)
{
	if (_iMoney >= 100 && _iNum == 1)
	{
		return(100);
	}
	else if (_iMoney >= 200 && _iNum == 2)
	{
		return(200);
	}
	else if (_iMoney >= 300 && _iNum == 3)
	{
		return(300);
	}
	else
		return(-1);
	
}
void Menu(int _iMoney)
{
	system("cls");
	cout << "�ܾ� : " << _iMoney << endl;
	cout << "1.�ݶ�(100��) 2.���̴�(200��) 3.ȯŸ(300��) 4.����" << endl;
}

void Exe(void)
{
	int iMoney = 0;
	int iNum = 0;
	bool iCheck = true;

	while (true)
	{
		if (iMoney >= 100)
		{
		m:
			Menu(iMoney);
			cin >> iNum;

			if (iNum == 1)
			{
				if (Buy(iMoney, iNum) >= 100) //���� �Լ��� �� ������ �վ�?
				{
					cout << "�ݶ� �����ϼ̽��ϴ�." << endl;
					iMoney -= Buy(iMoney, iNum);
					cout << "�ܾ� : " << iMoney << endl;
					system("pause");
				}
				else
				{
					cout << "�ܾ��� �����մϴ�." << endl;
					system("pause");
					break;
				}
			}
			else if (iNum == 2)
			{
				if (Buy(iMoney, iNum) >= 200)
				{
					cout << "���̴ٸ� �����ϼ̽��ϴ�." << endl;
					iMoney -= Buy(iMoney, iNum);
					cout << "�ܾ� : " << iMoney << endl;
					system("pause");
				}
				else
				{
					cout << "�ܾ��� �����մϴ�." << endl;
					system("pause");
					goto m;
				}
			}
			else if (iNum == 3)
			{
				if (Buy(iMoney, iNum) >= 300)
				{
					cout << "ȯŸ�� �����ϼ̽��ϴ�." << endl;
					iMoney -= Buy(iMoney, iNum);
					cout << "�ܾ� : " << iMoney << endl;
					system("pause");
				}
				else
				{
					cout << "�ܾ��� �����մϴ�." << endl;
					system("pause");
					goto m;
				}
			}
			/*else if (iNum == 4)
			{
				cout << "���α׷��� �����մϴ�." << endl;
				break;
			}
			else
			{
				cout << "�߸��� ���� �Է��߽��ϴ�." << endl;
				system("pause");
				continue;
			}
			*/
		}
		else
		{
			system("cls");
			cout << "�������� �Է����ּ��� : (�ּ�100��) ";
			cin >> iMoney;
		}
	}
}

//���Ǳ� 1 �ݶ� 100 2 ���̴� 200 3 ȯŸ 300 4 ����
//���� �Է¹ް� ����

