#include <iostream>

using namespace std;

void main(void)
{
	// ���ڿ� ����
	// SBCS -> MBCS -> WBCS

	// ���ڿ� ���� ��ȯ �Լ�
	// size_t strlen(char const* pstr);
	// null���ڸ� ������ ������ ���ڿ� ���̸� ��ȯ�ϴ� �Լ�

	// char	szName[64] = "hello";
	// cout << strlen(szName) << endl;


	// ���ڿ� ���� �Լ�

	//char	szTemp[64] = "asdgasdgsadgsdagsdagsadgsdagsadg";
	//char	szSour[64] = "hello";
	/* szTemp = "hello"; ���ڿ� ������ �Ұ���

	 int strcpy_s(char* _Destination, rsize_t     _SizeInBytes,  char const* _Source);
	 1���� : ��� ������ ���ΰ�
	 2���� : �󸶸�ŭ�� ũ�� ������ ������ ���ΰ�
	 3���� : �����ϰ����ϴ� ���� ���ڿ�*/

	//strcpy_s(szTemp, sizeof(szTemp), szSour);
	//cout << szTemp << endl;
	//cout << szSour << endl;


	// ���ڿ� ���� �Լ�

	//char	szSour[64] = "hello";
	//char	szTemp[64] = "world";

	//errno_t strcat_s(char*       _Destination, rsize_t     _SizeInBytes, char const* _Source)
	
	// 1���� : ��� ������ ���ΰ�
	// 2���� : �󸶸�ŭ�� ũ�� ������ ������ ���ΰ�
	// 3���� : �����ϰ����ϴ� ���� ���ڿ�
	
	//strcat_s(szSour, sizeof(szSour), szTemp);

	//cout << szSour << endl;
	//cout << szTemp << endl;


	// ���ڿ� �� �Լ�
	// int __cdecl strcmp(char const* _Str1,char const* _Str2)
	// ���ڰ� �ΰ��� ���Ͽ� ��ġ�� ��� 0��, ����ġ�� ��� 1�� ��ȯ
/*

	char	szSour[64] = "hello";
	char	szTemp[64] = "hello";

	if (!strcmp(szSour, szTemp))
	{
		cout << "��ġ" << endl;
	}
	else
		cout << "����ġ" << endl;*/

}