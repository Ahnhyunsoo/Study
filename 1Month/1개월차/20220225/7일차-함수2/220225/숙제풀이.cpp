#include <iostream>

using namespace std;

int		Input_Coin(void);
int		Output_Menu(int _iCoin);
void	Progress(void);

void main(void)
{
	Progress();
}

int	Input_Coin(void)
{
	int		iCoin = 0;

	cout << "자판기에 돈을 넣어주세요 : ";
	cin >> iCoin;

	return iCoin;
}

void Progress(void)
{
	int		iInput = 0, iCoin = 0, iCoke = 100, iCider = 200, iFanta = 300;
	bool	bExit = true;

	iCoin = Input_Coin();

	while (bExit)
	{
		switch (Output_Menu(iCoin))
		{
		case 1:
			if (iCoin >= iCoke)
			{
				cout << "콜라 구매 완료" << endl;
				iCoin -= iCoke;
			}
			else
				cout << "잔액이 부족합니다" << endl;
			
			break;

		case 2:
			if (iCoin >= iCider)
			{
				cout << "사이다 구매 완료" << endl;
				iCoin -= iCider;
			}
			else
				cout << "잔액이 부족합니다" << endl;
			
			break;

		case 3:
			if (iCoin >= iFanta)
			{
				cout << "환타 구매 완료" << endl;
				iCoin -= iFanta;
			}
			else
				cout << "잔액이 부족합니다" << endl;
			
			break;

		case 4:
			cout << "거스름 돈은 " << iCoin << endl;
			//bExit = false;
			return;

		default:
			cout << "잘못 누르셨습니다" << endl;
			break;
		}
	}


}

int	Output_Menu(int _iCoin)
{
	int iInput = 0;

	system("cls");
	cout << "잔액 : " << _iCoin << endl;
	cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 : ";
	cin >> iInput;

	return iInput;
}