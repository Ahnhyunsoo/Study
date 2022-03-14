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
	cout << "잔액 : " << _iMoney << endl;
	cout << "1.콜라(100원) 2.사이다(200원) 3.환타(300원) 4.종료" << endl;
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
				if (Buy(iMoney, iNum) >= 100) //굳이 함수로 쓴 이유가 잇어?
				{
					cout << "콜라를 구입하셨습니다." << endl;
					iMoney -= Buy(iMoney, iNum);
					cout << "잔액 : " << iMoney << endl;
					system("pause");
				}
				else
				{
					cout << "잔액이 부족합니다." << endl;
					system("pause");
					break;
				}
			}
			else if (iNum == 2)
			{
				if (Buy(iMoney, iNum) >= 200)
				{
					cout << "사이다를 구입하셨습니다." << endl;
					iMoney -= Buy(iMoney, iNum);
					cout << "잔액 : " << iMoney << endl;
					system("pause");
				}
				else
				{
					cout << "잔액이 부족합니다." << endl;
					system("pause");
					goto m;
				}
			}
			else if (iNum == 3)
			{
				if (Buy(iMoney, iNum) >= 300)
				{
					cout << "환타를 구입하셨습니다." << endl;
					iMoney -= Buy(iMoney, iNum);
					cout << "잔액 : " << iMoney << endl;
					system("pause");
				}
				else
				{
					cout << "잔액이 부족합니다." << endl;
					system("pause");
					goto m;
				}
			}
			/*else if (iNum == 4)
			{
				cout << "프로그램을 종료합니다." << endl;
				break;
			}
			else
			{
				cout << "잘못된 값을 입력했습니다." << endl;
				system("pause");
				continue;
			}
			*/
		}
		else
		{
			system("cls");
			cout << "소지금을 입력해주세요 : (최소100원) ";
			cin >> iMoney;
		}
	}
}

//자판기 1 콜라 100 2 사이다 200 3 환타 300 4 종료
//지금 입력받고 시작

