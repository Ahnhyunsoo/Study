#include <iostream>

using namespace std;

void			Func(void);		// �Լ��� �����
void			Print(int _iA);
int				Get_Temp(void);
int				Add(int _iTemp, int _iSour);

void main(void)
{
	// �Լ� : �����͸� �����ϴ� ��� ���¸� ���Ѵ�.
	// �Լ��� �����ϴ� ���� : �ڵ��� ���뼺(���� ����� �Ź� ���� ������ �ʰ� �� �� ���� ��, �ʿ��� ������ �ҷ��� ����ϱ� ����)

	//Func();		// �Լ��� ȣ���ϰ� �ִ�(�Լ��� �̸�() : �Լ� ȣ�� ������)

	//Print(100);

	// cout << Get_Temp() << endl;

	// Print(Get_Temp());

	cout << Add(Get_Temp(), 10) << endl;
}

//��ȯŸ��		�Լ��̸�		�Ű�����, ���ڰ�, �Ķ����
void			Func(void)				
{											//: �Լ� ���Ǻ�(��ü)
	cout << "Hello" << endl;
}
void			Print(int _iA)
{
	cout << _iA + 50 << endl;
}

int				Get_Temp(void)
{
	// ��ȯ Ÿ���� void�� �ƴ� ��� �ݵ�� return Ű���� ����ؾ� �Ѵ�.
	// return : �Լ��� ������ �����ϴ� Ű����
	// return Ű����� ���Ե� ��ġ�� �ش��ϴ� �Լ��� ���� �����ϴ� Ű�����̴�.

	return   400;
}
int				Add(int _iTemp, int _iSour)
{
	return _iTemp + _iSour;
}

// 1. �Լ��� �̿��Ͽ� ���Ǳ� �ڵ带 �����϶�