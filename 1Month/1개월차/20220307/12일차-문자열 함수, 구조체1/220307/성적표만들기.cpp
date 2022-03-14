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
		cout << "1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ���� : ";
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
		cout << "�̸� : ";
		cin >> _szName[i];

		cout << "���� : ";
		cin >> _iKor[i];

		cout << "���� : ";
		cin >> _iEng[i];

		cout << "���� : ";
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
		cout << "============= " << i + 1 << "�� �л� ����ǥ ===============" << endl;
		cout << "�̸� : " << _szName[i] << endl;
		cout << "���� : " << _iKor[i] << endl;
		cout << "���� : " << _iEng[i] << endl;
		cout << "���� : " << _iMath[i] << endl;
		cout << "���� : " << _iTotal[i] << endl;
		cout << "��� : " << _fAver[i] << endl;
	}

	system("pause");
}

void		Search_Data(char(*_szName)[256], int _iKor[], int _iEng[], int _iMath[], int _iTotal[], float _fAver[], int _iCount)
{
	char	szFindName[256] = {};

	system("cls");
	cout << "�˻��� �л��� �̸��� �Է��ϼ��� : ";
	cin >> szFindName;

	for (int i = 0; i < _iCount; ++i)
	{
		if (!strcmp(_szName[i], szFindName))
		{
			cout << "�̸� : " << _szName[i] << endl;
			cout << "���� : " << _iKor[i] << endl;
			cout << "���� : " << _iEng[i] << endl;
			cout << "���� : " << _iMath[i] << endl;
			cout << "���� : " << _iTotal[i] << endl;
			cout << "��� : " << _fAver[i] << endl;

			system("pause");
			return;
		}		
	}

	cout << "�˻��� �̸��� �����ϴ�" << endl;
	cout << "�Է��� �л��� �̸��� ������ �����ϴ�" << endl;
	for (int i = 0; i < _iCount; ++i)
	{
		cout << "�̸� : " << _szName[i] << endl;
	}

	system("pause");


}
