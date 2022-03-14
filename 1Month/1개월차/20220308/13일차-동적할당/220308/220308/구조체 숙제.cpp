#include <iostream>

using namespace std;

// typedef		int			STATE;	// typedef은 기존에 존재하는 자료형 이름과 더불어 사용자가 원하는 이름으로 자료형을 정의하고 싶을 때 사용하는 문법

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
	//struct tagInfo tInfo;		// c시절에 구조체 변수 선언 방식
	
	//tagInfo		tInfo;			// c++에서 허용하게 된 구조체 변수 선언 방식
	
	/*INFO*		pInfo;
	PINFO		pInfo;*/


	INFO	tStudent[3] = {};

	int		iInput = 0;

	while (true)
	{
		system("cls");
		
		cout << "1. 입력 2. 전체 출력 3. 검색 출력 4. 종료 : ";
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
		cout << "이름 : ";
		cin >> pStudent[i].szName;

		cout << "국어 : ";
		cin >> pStudent[i].iKor;

		cout << "영어 : ";
		cin >> pStudent[i].iEng;

		cout << "수학 : ";
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
		cout << "이름 : " << pStudent[i].szName << endl;
		cout << "국어 : " << pStudent[i].iKor << endl;
		cout << "영어 : " << pStudent[i].iEng << endl;
		cout << "수학 : " << pStudent[i].iMath << endl;
		cout << "총점 : " << pStudent[i].iTotal << endl;
		cout << "평균 : " << pStudent[i].fAver << endl;
	}

	system("pause");
}

void Search_Data(PINFO pStudent, int _iCount)
{
	system("cls");

	char szFineName[256] = "";
	cout << "학생 이름 : ";
	cin >> szFineName;

	for (int i = 0; i < _iCount; ++i)
	{
		if (!strcmp(szFineName, pStudent[i].szName))
		{
			cout << "이름 : " << pStudent[i].szName << endl;
			cout << "국어 : " << pStudent[i].iKor << endl;
			cout << "영어 : " << pStudent[i].iEng << endl;
			cout << "수학 : " << pStudent[i].iMath << endl;
			cout << "총점 : " << pStudent[i].iTotal << endl;
			cout << "평균 : " << pStudent[i].fAver << endl;
			system("pause");

			return;
		}	
	}

	system("pause");
}
