#include <iostream>
#include <time.h>
//#include <ctime>

using namespace std;

void main(void)
{
	//�ݺ��� : �ݺ����� �ڵ带 �����ϰ� �����Ű�� ���� ����ϴ� ����
	//while, do while, for
#pragma region while��
	//while�� : ���� ������ �⺻ ������ ��� �ݺ���
	/*
	int iScore = 3;

	while (true)
	{
		if (0 == iScore) {
			break;
		}
		cout << 1 << endl;
		iScore--;
		

	}
	*/
	/*
	int i = 1;

	while (10 > i)
	{
		cout << 2 << " * " << i << " = " << i * 2 << endl;
		++i;
	}
	*/
#pragma endregion while��

#pragma region do while��

	// do while : ���ѷ����� ������ ��� �ݺ������� ���ǽ��� �Ʒ��ʿ� ��ġ�Ǿ� �ִ�.
	// �ݺ��������� ����� �� �ִ� Ű���� continue;
	/*
	do
	{
		cout << 1 << endl;

		

		continue;	//��Ƽ���� ������ ������ ����ƴ� �ڵ��� ù ��ġ�� �̵���Ų��.

		cout << 2 << endl;

	} while (true);
	*/
#pragma endregion do while��


#pragma region for��

#pragma endregion for��


#pragma region ���� (������ ��)
	
	//rand�Լ� : 0~32767���� ���� ���� �������� �����ϴ� �Լ�
	//srand�Լ� : rand�Լ��� seed(���� ǥ) ���� �����ϱ� ���� �Լ�
	//time�Լ� : ���� �ð��� �� ������ �ҷ����� �Լ�

	time_t Temp = 0;
	time(&Temp);
	cout << Temp << endl;
	
	
	srand(unsigned(time(NULL))); // ����ǥ�� �ٲ��ִ� ���� NULL = 0; unsigned = �����

	int iA = rand();
	int iB = rand();

	cout << iA << endl;
	cout << iB << endl;
	
#pragma endregion ���� (������ ��)

}



/*
system("cls"); // ������ ��µ� ������� ����� �Լ�

system("pause"; //��»��¸� �Ͻ� �����ϴ� �Լ�
*/

//1. while ���� �̿��Ͽ� ������ 2~9�� ����ϱ�
//2. do while���� �̿��Ͽ� ���ڸ� �Է�(5��)�ް� ¦���� ��쿡��(¦�������ؼ�) ���� ���ϴ� ���α׷� �����
//3. ���Ǳ� �����ϱ�(while��)
/*
- ������ �Է� �ޱ�
- ���� �������� '�ܾ�'���� ǥ���Ͽ� ���
- �޴��� ���, 1.�ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ��ȯ
- ���ÿ� ���� ���� �� �ܾ��� �ٲ��� ��
-�������� ������ ��� ���Ŵ� �Ұ����ϰ�, �ܾ��� �����մϴ� ���
- 4���� ������ �ܾ��� ~~���Դϴ�. ��� �� ���α׷� ����
*/

//4. Ȧ¦ ����
/*
- ������ �̾Ƴ��� �� ���ڰ� Ȧ���� ¦���� �Ǻ��ϴ� ����
- ������ 1~10���� �� �ϳ��� ����
- 1. Ȧ�� 2. ¦�� 3. ����
- �� 5���� �����Ͽ� ������ ���� ����� �� �� �� �� ���
- �Ŷ��帶�� ������ ���� �̴´�.
*/