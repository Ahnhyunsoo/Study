#include <iostream>

using namespace std;

struct tagInfo
{
	char szName[64]; // ����ü ���� ���� = �ɹ�����
	int iA;
	float fB;
	bool bChoice;
	double db;
	//����ü�� ũ�� = 24 ����ū �ڷ������� �ϳ��� �Ҵ��ϸ鼭 �ִ´�.
};

tagInfo* pInfo = &tInfo;

tInfo.sT;
(*pInfo).sT;
pInfo->sT;    pInfo�� �ɹ��� sT

struct tagTemp
{
	char cName;
	short sBB;
	int iAA;
	long long llCC; //�޸� �Ҵ��� �⺻ �ڷ����϶��� �ش�
	//long long 2�� + 24byte

	tagInfo tInfo; // 40byte
};

void main(void)
{
	tagInfo tInfo{ "ȫ�浿", 100, 6.27 };
	cout << "�̸��Է� : ";
	cin >> tInfo.szName; //. : �ɹ� ���� ������
	cout << "int�� ���� �Է� : ";
	cin >> tInfo.iA;

	//���ڿ� ����
	//SBCS ->					MBCS ->		WBCS
//single byte character set		multi		wide byte

	//���ڿ� ���� ��ȯ �Լ�

	//size_t strlen(char*)
	//size_t strlen(char const* pstr);
	//Null���ڸ� ������ ������ ���ڿ��� ���̸� ��ȯ�ϴ� �Լ�
	//char szName[64] = "hello";

	//cout << strlen(szName) << endl;
	
	//���ڿ� ���� �Լ�
	//char szTemp[64] = "";
	//szTemp = "hello"; ���ڿ� ������ �Ұ���
	//int strcpy_s(char* _Destination, rsize_t _SizeInBytes, char const* _Source);
	//1���� : ��� ������ ���ΰ�
	//2���� : �󸶸�ŭ�� ũ�� ������ ������ ���ΰ�
	//3���� : �����ϰ��� �ϴ� ���� ���ڿ�

	/*strcpy_s(szTemp, sizeof(szTemp), "hello");
	cout << szTemp << endl;*/

	//���ڿ� ���� �Լ�

	//1���� : ��� ������ ���ΰ�
	//2���� : �󸶸�ŭ�� ũ�� ������ ������ ���ΰ�
	//3���� : �����ϰ��� �ϴ� ���� ���ڿ�

	//strcat_s();

	//���ڿ� �� �Լ�
	//strcmp

	//����ü : ���� �ڷ����� �ѵ� ��� �����ϴ� ����� ���� �ڷ���
	//C��� ����� ���� �ڷ��� = ����ü ����ü ����ü
							  //Struct enum union
	//c++ ������ C��� 3�� + Ŭ���� �ؼ� �� 4��

	
}


/*

char "abcd" = 5byte null���� �����Ǿ� �ֱ� ����
strcmp = ���ں� �Լ��ε� ���ڰ� ���� ������ false�� ����
�׷��� �տ� !(not)�����ڸ� �ٿ��� ����Ѵ�.

���� �������α׷� ����ü�� �̿��ؼ� �����

*/
