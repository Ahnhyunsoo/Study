#include <iostream>

using namespace std;

void main(void)
{
	// �޸� �Լ� : �޸� �� �޸� ������ �����͵��� �ʱ�ȭ �Ǵ� ���縦 �����ϴ� �Լ�

	// void* memset(void* pDest, int Value, size_t Size) : �޸� �ʱ�ȭ �Լ�
	// 1���� : �ʱ�ȭ�ϰ����ϴ� �������� �ּ�, 2���� : ����Ʈ ������ �ʱ�ȭ�� ��, 3���� : �󸶸�ŭ�� ũ�� ������ �ʱ�ȭ�� ���ΰ�
	
	//memset(�ʱ�ȭ�ϰ���� �������� �ּ� , ����Ʈ ������ �ʱ�ȭ�� �� , �󸶸�ŭ�� ũ���� ����
	//memset = �ʱ�ȭ ���ִ� �޸��Լ�
	//memset(�ʱ�ȭ�� ������ ��ǥ�ּ�, �ʱ�ȭ�ҹ���Ʈũ��, �ʱ�ȭ�� ũ��)
	//ex) int iArray [5];
	// memset(iArray, 0, sizeof(iArray));

	//memcpy = ���� �������ִ� �޸��Լ�
	//memcpy = (������� ������ ��ǥ�ּ�, ������ ������ ��ǥ�ּ�, ������ �޸�ũ��)
	//memcpy (iA, iB, sizeof(iB));

	//memmove = memcpy�� ���۸� �ٸ��� �Ȱ���

	/*int	iarray[5];
	memset(iarray, 0, sizeof(iarray));

	for (int i = 0; i < 5; ++i)
		cout << iarray[i] << endl;*/

	/*int	iA = 0;
	memset(&iA, 1, sizeof(int));

	cout << iA << endl;*/			// ����Ʈ ������ 2���� ������ �ʱ�ȭ �ϱ� ������ �츮�� ���ϴ� ����� �ٸ� ������� ����ȴ�.

	// void* memcpy(void* pDest, const void* pSrc, size_t Size) : �޸� ���� �Լ�
	// 1���� : ���� ���� ������ ���� �ּ� 2���� : ���縦 ������ ���� ������ �ּ�, 3���� : ������ �޸� ũ��

	//int	iSrc[5] = { 1, 2,3,4,5 };
	//int	iDest[5] = {};

	/*for (int i = 0; i < 5; ++i)
	{
		iDest[i] = iSrc[i];
		cout << iDest[i] << endl;
	}*/

	/*memcpy(iDest, iSrc, sizeof(iSrc));

	for (int i = 0; i < 5; ++i)
	{
		cout << iDest[i] << endl;
	}*/
	//memcpy (������� ������ ��ǥ�ּ�, ������ ������ ��ǥ�ּ�, ������ �޸�ũ��
	//memmove �� �Ȱ����� memcpy�� �ٷκ��� memmove�� �ӽð����� ������ ����
	//memcpy�� �����쿡���� ��밡�� memmove�� ������, ������ �Ѵ� ��밡���� ǥ��

	// void* memmove(void* pDest, const void* pSrc, size_t Size) : �޸� �̵� �Լ�
	// 1���� : ���� ���� ������ ���� �ּ� 2���� : ���縦 ������ ���� ������ �ּ�, 3���� : ������ �޸� ũ��

	//int	iSrc[5] = { 1, 2,3,4,5 };
	//int	iDest[5] = {};

	/*for (int i = 0; i < 5; ++i)
	{
	iDest[i] = iSrc[i];
	cout << iDest[i] << endl;
	}*/

	/*memmove(iDest, iSrc, sizeof(iSrc));

	for (int i = 0; i < 5; ++i)
	{
		cout << iDest[i] << endl;
	}*/

//	memcpy�� memmove�� ������

// - memcpy�� �ٷ� ����, memmove�� �ӽ� ���ۿ� �̵� �Ŀ� ���縦 ����
// - memcpy�� ��� linux �ü������ ��� �Ұ�, memmove�� ��� window, linux ��� ��� ������ ǥ�� ����

}