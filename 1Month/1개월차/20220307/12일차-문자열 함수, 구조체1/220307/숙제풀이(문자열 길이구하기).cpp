#include <iostream>

using namespace std;

int	My_strlen(char szName[]);
void Rev_Name(char szName[]);


void main(void)
{
	char		szName[64] = "";
	int			iLength = 0;

	cout << "���ڿ� �Է� : ";
	cin >> szName;

	iLength = My_strlen(szName);
	cout << "���ڿ� ���� : " << iLength << endl;

	Rev_Name(szName);

	cout << "������ ��� : " << szName << endl;

}
int	My_strlen(char szName[])
{
	int	iLength = 0;

	while ('\0' != szName[iLength])
		++iLength;
	
	return iLength;
}

void Rev_Name(char szName[])
{
	int	iLength = My_strlen(szName);
	int	iRevIndex = iLength - 1;

	for (int i = 0; i < iLength / 2; ++i)
	{
		char	chTemp = szName[i];
		szName[i] = szName[iRevIndex];
		szName[iRevIndex--] = chTemp;
	}

}
