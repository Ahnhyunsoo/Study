#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
	int	iInput = 0, iComputer = 0, iCount = 5;
	int iWin = 0, iDraw = 0, iLose = 0;
	bool	bExit = true;

	srand(unsigned(time(NULL)));

	while (bExit && (0 < iCount))
	{
		system("cls");
		iComputer = rand() % 3 + 1;
		cout << "1. ���� 2. ���� 3. �� 4. ���� : ";
		cin >> iInput;
		--iCount;

		switch (iInput)
		{
		case 1:
			if (1 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "�÷��̾� : ����" << endl;
				cout << "���º��Դϴ�" << endl;
				++iDraw;				
			}

			else if (2 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "�÷��̾� : ����" << endl;
				cout << "�����ϴ�" << endl;
				++iLose;
			}

			else
			{
				cout << "��ǻ�� : ��" << endl;
				cout << "�÷��̾� : ����" << endl;
				cout << "�̰��Դϴ�" << endl;
				++iWin;
			}

			break;

		case 2:
			if (1 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "�÷��̾� : ����" << endl;
				cout << "�̰���ϴ�" << endl;
				++iWin;
			}

			else if (2 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "�÷��̾� : ����" << endl;
				cout << "���º��Դϴ�" << endl;
				++iDraw;
			}

			else
			{
				cout << "��ǻ�� : ��" << endl;
				cout << "�÷��̾� : ����" << endl;
				cout << "�����ϴ�" << endl;
				++iLose;
			}
			break;

		case 3:
			if (1 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "�÷��̾� : ��" << endl;
				cout << "�����ϴ�" << endl;
				++iLose;
			}

			else if (2 == iComputer)
			{
				cout << "��ǻ�� : ����" << endl;
				cout << "�÷��̾� : ��" << endl;
				cout << "�̰���ϴ�" << endl;
				++iWin;
			}

			else
			{
				cout << "��ǻ�� : ��" << endl;
				cout << "�÷��̾� : ��" << endl;
				cout << "���º��Դϴ�" << endl;
				++iDraw;
			}
			break;

		case 4:
			bExit = false;
			break;

		default:
			cout << "�߸� �����̽��ϴ�" << endl;
			++iCount;
			continue;
		}

		system("pause");
	}

	system("cls");
	cout << "�� : " << iWin << "\t�� : " << iDraw << "\t�� : " << iLose << endl;
	system("pause");
}