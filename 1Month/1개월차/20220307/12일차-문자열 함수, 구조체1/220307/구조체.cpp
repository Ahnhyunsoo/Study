#include <iostream>

using namespace std;

struct tagInfo			// 24
{
	//char		szName[64];		// ��� ����

	bool		bChoice;
	short		sT;
	int			iA;				// ��� ����
	float		fB;				// ��� ����
	double		dbTemp;
};

struct  tagTemp
{
	char	cName;
	short	sBB;
	long long llCC;

	tagInfo		tInfo;		// ����� ���� �ڷ����� ����ü �޸� �Ҵ� ��å�� ������ �ʴ´�.
};

void main(void)
{
	// ����ü : ���� �ڷ����� �ѵ� ��� �����ϴ� ����� ���� �ڷ���

	//cout << sizeof(tagInfo) << endl;
	//cout << sizeof(tagTemp) << endl;

	tagInfo		tInfo = { "ȫ�浿", 100, 6.27f };
	//tagInfo		tInfo = { "" };

	/*cout << "�̸� �Է� : ";
	cin >> tInfo.szName;		// . : ��� ���� ������

	cout << "int�� ���� �Է� : ";
	cin >> tInfo.iA;

	cout << "float�� ���� �Է� : ";
	cin >> tInfo.fB;*/

	/*cout << tInfo.szName << endl;
	cout << tInfo.iA << endl;
	cout << tInfo.fB << endl;*/

// 	/*tagInfo*		pInfo = &tInfo;
// 
// 	tInfo.sT;
// 	(*pInfo).sT;
// 	pInfo->sT;
// */

}