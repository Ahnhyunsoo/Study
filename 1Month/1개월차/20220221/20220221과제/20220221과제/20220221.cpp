#include <iostream>

using namespace std;

void main(void)
{
	int iKor = 0;
	int iEn = 0;
	int iMath = 0;
	int iSum = 0;
	int iAvg = 0;
	

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iKor;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iEn;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iMath;

	cout << fixed;
	cout.precision(4);

	cout << "=========================" << endl;
	
	iSum = iKor + iEn + iMath;
	iAvg = (iKor + iEn + iMath) / 3;
	
	cout << "�� ������ ���� : " << iSum << endl;    
	cout << "�� ������ ��� : " << iAvg << endl;


#pragma region ����ġ��
	switch (iAvg/10) 
	{

	case 10: case 9: 
		cout << "A�Դϴ�" << endl;
		break;
	case 8:
		cout << "B�Դϴ�" << endl;
		break;
	case 7:
		cout << "C�Դϴ�" << endl;
		break;
	case 6:
		cout << "D�Դϴ�" << endl;
		break;
	default :
		cout << "F�Դϴ�" << endl;
		break;

	}
	
	//ABCD F 100 90 80 90
#pragma endregion ����ġ��


#pragma region if��

	if (iAvg >= 90 && iAvg < 100)
	{
		cout << "A" << endl;
	}
	else if (iAvg >= 80 && iAvg < 90)
	{
		cout << "B" << endl;
	}
	else if (iAvg >= 70 && iAvg < 80)
	{
		cout << "C" << endl;
	}
	else if (iAvg >= 60 && iAvg < 70)
	{
		cout << "D" << endl;
	}
	else if(iAvg >= 0 && iAvg < 60)
	{
		cout << "F" << endl;
	}
	else
	{
		cout << "������ �߸��Է��ϼ̽��ϴ�" << endl;
	}
	
		
	
#pragma endregion if��




}