#include <iostream>

using namespace std;

void		Input_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount);
void		Output_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount);
void		Search_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount);


void main(void)
{
	const int	COUNT = 3;

	char	szName[COUNT][256] = {};

	int		iKor[COUNT] = {}, iEng[COUNT] = {}, iMath[COUNT] = {}, iTotal[COUNT] = {};
	float	fAver[COUNT] = {};

	int		iInput = 0;

	void(*ptrFunc[3])(char(*)[256], int*, int*, int*, int*, float*, int) = { Input_Data, Output_Data, Search_Data };

	while (true)
	{
		system("cls");
		cout << "1. 입력 2. 전체 출력 3. 검색 출력 4. 종료 : ";
		cin >> iInput;

		/*switch (iInput)
		{
		case 1:
			Input_Data(szName, iKor, iEng, iMath, iTotal, fAver, COUNT);
			break;

		case 2:
			Output_Data(szName, iKor, iEng, iMath, iTotal, fAver, COUNT);
			break;

		case 3:
			Search_Data(szName, iKor, iEng, iMath, iTotal, fAver, COUNT);
			break;

		case 4:
			return;

		default:
			continue;
		}*/

		if (4 == iInput)
			return;

		ptrFunc[iInput - 1](szName, iKor, iEng, iMath, iTotal, fAver, COUNT);

	}
}

void Input_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount)
{
	system("cls");

	for (int i = 0; i < _iCount; ++i)
	{
		cout << "이름 : ";
		cin >> _szName[i];

		cout << "국어 : ";
		cin >> _iKor[i];

		cout << "영어 : ";
		cin >> _iEng[i];

		cout << "수학 : ";
		cin >> _iMath[i];

		_iTotal[i] = _iKor[i] + _iEng[i] + _iMath[i];
		_fAver[i] = (float)_iTotal[i] / 3.f;
	}
	system("pause");

}

void Output_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount)
{
	system("cls");

	for (int i = 0; i < _iCount; ++i)
	{
		cout << "============= " << i + 1 << "번 학생 성적표 ===============" << endl;
		cout << "이름 : " << _szName[i] << endl;
		cout << "국어 : " << _iKor[i] << endl;
		cout << "영어 : " << _iEng[i] << endl;
		cout << "수학 : " << _iMath[i] << endl;
		cout << "총점 : " << _iTotal[i] << endl;
		cout << "평균 : " << _fAver[i] << endl;
	}

	system("pause");
}

void		Search_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount)
{
	char	szFindName[256] = {};

	system("cls");
	cout << "검색할 학생의 이름을 입력하세요 : ";
	cin >> szFindName;

	for (int i = 0; i < _iCount; ++i)
	{
		if (!strcmp(_szName[i], szFindName))
		{
			cout << "이름 : " << _szName[i] << endl;
			cout << "국어 : " << _iKor[i] << endl;
			cout << "영어 : " << _iEng[i] << endl;
			cout << "수학 : " << _iMath[i] << endl;
			cout << "총점 : " << _iTotal[i] << endl;
			cout << "평균 : " << _fAver[i] << endl;

			system("pause");
			return;
		}		
	}

	cout << "검색된 이름이 없습니다" << endl;
	cout << "입력한 학생의 이름은 다음과 같습니다" << endl;
	for (int i = 0; i < _iCount; ++i)
	{
		cout << "이름 : " << _szName[i] << endl;
	}

	system("pause");


}
