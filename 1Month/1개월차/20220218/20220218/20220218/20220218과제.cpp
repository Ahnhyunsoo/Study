#include <iostream>

using namespace std;

#pragma region ����
void main(void)
{
	int iKorean = 0, iEnglish = 0, iMath = 0, iSum = 0; //������ �������� �� �ʱ�ȭ
	float fAvg = 0.f; // �Ǽ��� ���� ���� �� �ʱ�ȭ
	
	cout << "=========================" << endl;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iKorean; // ���� �Է¹޾� ������ ����
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iEnglish; // ���� �Է¹޾� ������ ����
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iMath; // ���� �Է¹޾� ������ ����
	cout << '\n';
	
	iSum = iKorean + iMath + iEnglish; // ó���� �����ϸ� �Է¹��� ���� ������ ���� �Է� ���� �� ���� �ʱ�ȭ
	fAvg = (iKorean + iMath + iEnglish) / 3.0f; // ó���� �����ϸ� �Է¹��� ���� ������ ���� �Է� ���� �� ���� �ʱ�ȭ
						//3���� ������ ����� �������� �����Ƿ� �Ҽ��� ������
						//�Ҽ��� �⺻�ڷ����� double�̹Ƿ� f�� ������ float������ ������ֱ�


	cout << fixed; 
	cout.precision(4); //precision(�Ҽ������ڸ�����ǥ��)

	cout << "�� ������ ���� : " << iSum << "��" << endl;
	cout << "�� ������ ��� : " << fAvg << "��" << endl;
	cout << "=========================" << endl;
	

}
#pragma endregion ����