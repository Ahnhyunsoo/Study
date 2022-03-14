#include <iostream>

using namespace std;

// typedef		int			STATE;	// typedef�� ������ �����ϴ� �ڷ��� �̸��� ���Ҿ� ����ڰ� ���ϴ� �̸����� �ڷ����� �����ϰ� ���� �� ����ϴ� ����

/*
typedef		int					BOOL;
typedef		unsigned long		DWORD;
typedef		unsigned short		WORD;
typedef		unsigned char		BYTE;
*/

typedef struct	tagInfo 
{
	char		szName[32];
	int			iKor;
	int			iEng;
	int			iMath;
	int			iTotal;
	float		fAver;

}INFO, *PINFO;

void	Input_Data(PINFO pStudent, int _iCount);
void	Output_Data(PINFO pStudent, int _iCount);
void	Search_Data(PINFO pStudent, int _iCount);

void main(void)
{
	//struct tagInfo tInfo;		// c������ ����ü ���� ���� ���
	
	//tagInfo		tInfo;			// c++���� ����ϰ� �� ����ü ���� ���� ���
	
	/*INFO*		pInfo;
	PINFO		pInfo;*/


	INFO	tStudent[3] = {};

	int		iInput = 0;

	while (true)
	{
		system("cls");
		
		cout << "1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Input_Data(tStudent, 3);
			break;

		case 2:
			Output_Data(tStudent, 3);
			break;

		case 3:
			Search_Data(tStudent, 3);
			break;

		case 4:
			return;

		default:
			continue;
		}
	}
	
}

void Input_Data(PINFO pStudent, int _iCount)
{
	system("cls");

	for (int i = 0; i < _iCount; ++i)
	{
		cout << "�̸� : ";
		cin >> pStudent[i].szName;

		cout << "���� : ";
		cin >> pStudent[i].iKor;

		cout << "���� : ";
		cin >> pStudent[i].iEng;

		cout << "���� : ";
		cin >> pStudent[i].iMath;

		pStudent[i].iTotal = pStudent[i].iKor + pStudent[i].iEng + pStudent[i].iMath;
		pStudent[i].fAver = pStudent[i].iTotal / 3.f;
	}
}

void Output_Data(PINFO pStudent, int _iCount)
{
	system("cls");

	for (int i = 0; i < _iCount; ++i)
	{
		cout << "�̸� : " << pStudent[i].szName << endl;
		cout << "���� : " << pStudent[i].iKor << endl;
		cout << "���� : " << pStudent[i].iEng << endl;
		cout << "���� : " << pStudent[i].iMath << endl;
		cout << "���� : " << pStudent[i].iTotal << endl;
		cout << "��� : " << pStudent[i].fAver << endl;
	}

	system("pause");
}

void Search_Data(PINFO pStudent, int _iCount)
{
	system("cls");

	char szFineName[256] = "";
	cout << "�л� �̸� : ";
	cin >> szFineName;

	for (int i = 0; i < _iCount; ++i)
	{
		if (!strcmp(szFineName, pStudent[i].szName))
		{
			cout << "�̸� : " << pStudent[i].szName << endl;
			cout << "���� : " << pStudent[i].iKor << endl;
			cout << "���� : " << pStudent[i].iEng << endl;
			cout << "���� : " << pStudent[i].iMath << endl;
			cout << "���� : " << pStudent[i].iTotal << endl;
			cout << "��� : " << pStudent[i].fAver << endl;
			system("pause");

			return;
		}	
	}

	system("pause");
}
