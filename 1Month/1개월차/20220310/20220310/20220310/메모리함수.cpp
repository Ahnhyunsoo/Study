#include <iostream>

using namespace std;

void main(void)
{
	//�޸��Լ� : �޸� �� �޸� ������ �����͵��� �ʱ�ȭ �Ǵ� ���縦 �����ϴ� �Լ�

	// void* memset(void* pDest, int Value, size_t Size) : �޸� �ʱ�ȭ �Լ�
	//1���� : �ʱ�ȭ�ϰ����ϴ� �������� �ּ�
	//2���� : ����Ʈ ������ �ʱ�ȭ�� ��
	//3���� : �󸶸�ŭ�� ũ�⸦ �ʱ�ȭ �� ������
	//����Ʈ���� �ʱ�ȭ�̹Ƿ� �����ؾ��Ѵ�

	/*int iArray[5];
	memset(iArray, 0, sizeof(iArray));
	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << endl;*/ 
// ����Ʈ ������ 2���� ������ �ʱ�ȭ �ϱ� ������ �츮�� ���ϴ� ���� �ȳ��´�.

	/*void* memcpy(void* pDest, const void* pSrc, size_t Size) : �޸� ���� �Լ�
	1���� : ���� ���� ������ ���� �ּ�
	2���� : ���縦 ������ ���� ������ �ּ�
	3���� : ������ �޸�*/

	/*int iSrc[5] = { 1,2,3,4,5 };
	int iDest[5] = {};

	memcpy(iDest, iSrc, sizeof(iSrc));
	for(int i = 0; i < 5; ++i)
	{
		cout << iDest[i] << endl;
	}*/

	//memmove = �޸� �����Լ�

	//memcpy = �������� �纻�� �ٷιٷ� ����
	//memmove = �������� �ӽð����� �ű�� �ű� �ӽõ����͸� �纻�� ����

	//memcpy�� ��� linux �ü������ ��� �Ұ�,
	//memmove�� ��� window, linux ��� ��밡���� ǥ�� ����
	
	

}