#include <iostream>

using namespace std;

void main(void)
{

#pragma region ���� ������

	/*// ���� ������
	int			iTemp	= 10;
	int*		p		= &iTemp;
	int**		pp		= &p;

	cout << "iTemp �� : " << iTemp << endl;
	cout << "p �� : " << p << endl;
	cout << "pp �� : " << pp << endl;

	cout << "=======================" << endl;

	cout << "iTemp �ּ� �� : " << (&iTemp) << endl;
	cout << "p �ּ� �� : " << (&p) << endl;
	cout << "pp �ּ� �� : " << (&pp) << endl;

	cout << "=======================" << endl;

	cout << "iTemp �� ��� ��� : " << iTemp << endl;
	cout << "p�� ���� iTemp �� ��� ��� : " << (*p) << endl;
	cout << "pp�� ���� iTemp �� ��� ��� : " << (*(*pp)) << endl;*/


#pragma endregion ���� ������

#pragma region �������� ����ȯ�� Ư¡

	/*int		iA = 10;

	int*	p = &iA;

	// �����ʹ� �ڷ��� Ÿ�Ը� ��ġ�Ѵٸ� �ּ� ���� �����ϴ� �뵵 ��ü�� �����ϱ� ������ ������ ���� ������ �����ϴ�.
	float*	fp = (float*)p;

	*fp = 20.f; // �׷��� ������ Ÿ���� �ٸ��ų� ũ�Ⱑ �ٸ��� �ɰ��� ������ �߻���Ű�� ������ ������ �ڷ����� �ݵ�� ��ġ�ϵ��� ���缭 �� ���� �����Ѵ�.

	cout << iA << endl;*/

#pragma endregion �������� ����ȯ�� Ư¡

#pragma region const�� �������� ����

	// const	int iA = 0;		// �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �����ؾ� ��
							// �б� �������� ����ڴٴ� �ǹ�

	// iA = 20;
	// cout << iA << endl;

	int			iA = 0;
	int			iB = 10;
	//const int*	p = &iA;
	// int*	const  p = &iA;	// ��� ������(������ �ϳ��� �޸� ������ �����ϴ� ������)

	const int*	const  p = &iA;		// �����ϴ� �ּ� ��, �޸� ������ ����Ű�� �� ���� �Ұ��� ������ �б� ���� ������

	//*p = 10;
	//p = &iB;

	cout << iA << endl;
	cout << (*p) << endl;



#pragma endregion const�� �������� ����

	

}