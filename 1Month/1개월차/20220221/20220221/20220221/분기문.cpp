#include <iostream>

using namespace std;
void main(void)
{
#pragma region if��
	//�б⹮ : ������ ��Ƽ� ������ ����
	// if��, switch��, goto��

	/*
	int iTemp = 0;
	//cin >> iTemp;

	if (iTemp > 10)
		cout << 1 << endl; //���� �ڵ� (�� �ֶ󤹸� �ڵ�)�� ��� �߱�ȣ�� ������ �� �ִ�.
	else				   //else �� ����Ϸ��� �ݵ�� if���� ���� ������� �־�� �Ѵ�.
		cout << 2 << endl;
	*/

	int iInput = 0;

	cout << "���ڸ� �Է��ϼ���(1. ���� 2. ��� 3. �Ķ�) : ";
	cin >> iInput;

	if (1 == iInput) // if = �������� ó�� �ϳ��� true���� �ٸ����� true ����, else if = �������� ó�� �ϳ��� true�� ������ false
		cout << "����" << endl;
	else if (2 == iInput)	// else if ���� ���� if���� �־�� ��� �����ϴ�.
		cout << "���" << endl;
	else if (3 == iInput)
		cout << "�Ķ�" << endl;
	else
		cout << "�߸��� �Է��Դϴ�." << endl;
#pragma endregion if��

#pragma region switch��

	// ����� �̿��Ͽ� �б��ϴ� ����, ��� ���� �б⹮�̶�� �Ѵ�.
	// �������� ��� �Ǵ� ������ ����ϸ�, �Ǽ��δ� �б��� �� ����.

	int iSelect = 0;
	cin >> iSelect;

	//int iA = 1, iB = 2, iC = 3;

	switch (iSelect) // switch�� ���� case ���� ���� �ݵ�� ����� �;� �Ѵ�.
	{
	case 1 :
		cout << "�ݶ� " << endl;
		break;
	case 2 :
		cout << "���̴� " << endl;
		break;
	case 3 :
		cout << "ȯŸ " << endl;
		break;

	default :
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		break;
	}

	/*
	if (1)
	{
		cout << 1 << endl;
		break;
		cout << 2 << endl;
		}
	*/

}


// ����ǥ ����� ���α׷�

// 1. ��,��,�� ����,��� ���ϱ�
// 2. if���� �̿��ؼ� ��� ������ ���� ���� ����� �ű��.
// 90�� �̻� 100�������� ��� 'A'
// 80�� �̻� 90���̸��� ��� 'B'
// 70�� �̻� 80���̸��� ��� 'C'
// 60�� �̻� 70���̸��� ��� 'D'
// �������� ��� 'F'
//�������ϰ� ���� �� �־ �ȴ�. ����ó��


