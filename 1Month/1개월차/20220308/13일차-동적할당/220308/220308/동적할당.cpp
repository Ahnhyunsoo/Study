#include <iostream>

using namespace std;


char*	Func()
{
	//char szName[16] = "";		// ��������

	char*	pName = (char*)calloc(16, sizeof(char));
	// 0x30

	cin >> pName;

	return pName;
}


void main(void)
{
	//char*		pName = Func();
	//cout << pName << endl;

	//free(pName);
	//pName = nullptr;


#pragma region c������ �����Ҵ�

	// malloc, calloc

	// void* �� : � �ּҰ��� �������� �� �� ���� �� ����ϴ� ����, ���� �������� void*�� �����ص� �����ϳ�
	//            ���� ���������� � �ڷ����� �ּҰ��� �ݵ�� ��������� ����ȯ�� �����ؾ� �Ѵ�.

	// void*		malloc(size_t size);		// �����Ҵ��� �����ϴ� �Լ�
	// int*	p = (int*)malloc(sizeof(int));

	//void*			calloc(size_t Count, size_t Size);

	//malloc��  calloc�� ������

	//1. ���ڰ��� ������ �ٸ���
	//2. �Ҵ��� heap�޸� ������ ���� calloc�� ��� �ڵ� 0�ʱ�ȭ�� �����Ѵ�.

//	int	iCount = 0;
	//cin >> iCount;

	//int*	p = (int*)calloc(iCount, sizeof(int));		// �����迭�� ������� �� �� ����� ���ϴ�.

//	int*	p = (int*)malloc(iCount * sizeof(int));

	//for (int i = 0; i < iCount; ++i)
	//	cout << p[i] << endl;
	
	//cout << p << endl;		// heap ������ �ּҰ� ���

	//cout << (*p) << endl;

	// void free(void* p);		// �����Ҵ��� �޸𸮸� ��ȯ�ϴ� �Լ�

	//free(p);	
	//p = nullptr;			// ��۸� �����͸� �����ϱ� ���� �޸� ��ȯ���� �ݵ�� �����ؾ� ��.

	/*cout << p << endl;		// heap ������ �ּҰ� ���(��۸� ������)
	*p = 100;

	cout << (*p) << endl;*/
	
#pragma endregion c������ �����Ҵ�

#pragma region  c++������ �����Ҵ�

	/*int*	p = new int;	// �����ڸ� ���� �����Ҵ��� int�� ũ�⸸ŭ�� heap�Ҵ��� �ϰ� �� ù ��° �ּҸ� ����

	cout << p << endl;

	delete p;		// �����ڸ� ���� �޸� ��ȯ
	p = nullptr;*/
	//cout << p << endl;

	/*int*	p2 = new int[4];		// int�� 4�� ũ�⸸ŭ�� �������� �Ҵ�

	for (int i = 0; i < 4; ++i)
		cout << p2[i] << endl;

	delete[] p2;			// ���� �迭�� �޸� ��ȯ�ϴ� ����
	p2 = nullptr;*/

	// �����ؾ��� ���� : ���α׷��Ӵ� heap�޸𸮿� ������ �߻����� �ʵ��� �ݵ�� �����ϰ�, �޸𸮸� �����ϴ� �ڵ带 ¥�� �Ѵ�.

	/*int		iA = 100;
	int*	p = new int;

	p = &iA;

	*p = 20;*/	

#pragma endregion  c++������ �����Ҵ�

}