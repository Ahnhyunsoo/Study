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

	cout << "���Ǳ⿡ ���� �־��ּ��� : ";
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
				cout << "�ݶ� ���� �Ϸ�" << endl;
				iCoin -= iCoke;
			}
			else
				cout << "�ܾ��� �����մϴ�" << endl;
			
			break;

		case 2:
			if (iCoin >= iCider)
			{
				cout << "���̴� ���� �Ϸ�" << endl;
				iCoin -= iCider;
			}
			else
				cout << "�ܾ��� �����մϴ�" << endl;
			
			break;

		case 3:
			if (iCoin >= iFanta)
			{
				cout << "ȯŸ ���� �Ϸ�" << endl;
				iCoin -= iFanta;
			}
			else
				cout << "�ܾ��� �����մϴ�" << endl;
			
			break;

		case 4:
			cout << "�Ž��� ���� " << iCoin << endl;
			//bExit = false;
			return;

		default:
			cout << "�߸� �����̽��ϴ�" << endl;
			break;
		}
	}


}

int	Output_Menu(int _iCoin)
{
	int iInput = 0;

	system("cls");
	cout << "�ܾ� : " << _iCoin << endl;
	cout << "1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ : ";
	cin >> iInput;

	return iInput;
}