#include <iostream>

using namespace std;

void exe();
int menu();
//int Check(char* C, char* B);

void main(void)
{
	exe();
}

void exe()
{
	char* Name[3] = {};
	int Korean[3] = {};
	int Math[3] = {};
	int English[3] = {};
	char cTemp[4][100] = {};
	char* B[1] = {};

	while (true)
	{
		switch (menu())
		{
		case 1:
			for (int i = 0; i < 3; ++i)
			{
				cout << i + 1 << "�� �л��� �̸��� �Է��ϼ��� : ";
				cin >> cTemp[i];
				Name[i] = cTemp[i];

				cout << Name[i] << " �л��� ���� ������ �Է��ϼ��� : ";
				cin >> Korean[i];
				cout << Name[i] << " �л��� ���� ������ �Է��ϼ��� : ";
				cin >> Math[i];
				cout << Name[i] << " �л��� ���� ������ �Է��ϼ��� : ";
				cin >> English[i];

			}



		case 2:
			for (int i = 0; i < 3; ++i)
			{
				int Sum = Korean[i] + Math[i] + English[i];
				int Avg = (Korean[i] + Math[i] + English[i]) / 3;
				cout << Name[i] << "�л��� �������� : " << Korean[i] << " �������� : " << Math[i] << " �������� : " << English[i] << " ���� : " << Sum << " ��� : " << Avg << endl;
			}
			break;

		case 3:
			cout << "�л� �̸� �Է� : ";
			cin >> cTemp[4];
			B[0] = cTemp[4];

			for (int i = 0; i < 3; ++i)
			{ 
				if (*Name[i] == *B[0]) 
				{
					int Sum = Korean[i] + Math[i] + English[i];
					int Avg = (Korean[i] + Math[i] + English[i]) / 3;
					cout << Name[i] << "�л��� �������� : " << Korean[i] << " �������� : " << Math[i] << " �������� : " << English[i] << " ���� : " << Sum << " ��� : " << Avg << endl;
				}
			}
			break;
		case 4:
			cout << "���α׷��� �����մϴ�" << endl;
			return;
		}
	}
}



int menu()
{
	int iInput = 0;
	cout << "1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ���� : ";
	cin >> iInput;
	return iInput;
}


//int Check(char C[3], char B[1])
//{
//	cout << C[0] << endl;
//	return 1;
//	
//}










/*
4. 3���� �Է� ������ ����ǥ ���α׷� �����(�̸�, ����, ����, ����, ����, ���)
(����ü ������)
// 1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ����
�Է��� �� ���� 3�� ���� �Է�
�Է� �� ��ü ��� �˻� ���
*/