#include <iostream>



//char* Func()
//{
//	char szName[16] = "";
//
//	cin >> szName;
//	
//	return szName;
//}
using namespace std;

void main(void)
{
	/*char* pName = Func();
	cout << pName << endl;*/

#pragma region c������ �����Ҵ�

	//malloc, calloc

	//void* �� : � �ּҰ��� �������� �� �� ���� �� ����ϴ� ����, ���� ��������
	//void* �� �����ص� ��� ������ ���� ��� ���������� � �ڷ����� �ּҰ����� ��������� ����ȯ�� �����ؾ� �Ѵ�.

	/*void* malloc(size_t size);

	int* p = (int*)malloc(sizeof(int));*/
/*
	malloc�� calloc�� ������
		1. ���ڰ��� ������ �ٸ���
		2. �Ҵ��� heap�޸� ������ ���� calloc�� ���� �ڵ� 0�ʱ�ȭ�� ����*/  // ���� �迭�� ������� �� �� ����ϱ� ���ϴ�.


	void* calloc(size_t Count, size_t Size);

	int* p = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < 5; ++i)
	{
		cout << p[i] << endl;
	}



	//*p = 20;

	//cout << (*p) << endl;

	//void free(void* p) // �����Ҵ��� �޸𸮸� ��ȯ�ϴ� �Լ�

	//free(p);
	//p = nullptr; //��۸� �����͸� �����ϱ� ���� �޸� ��ȯ���� �ݵ�� �����ؾ���.
	//cout << p << endl;

#pragma endregion c������ �����Ҵ�
}


/*
text RPG
1.���� 2.���� 3.���� 4.�ҷ����� 5.����

���ý�
���� ���ݷ� ü�� ����

������ =
*/


