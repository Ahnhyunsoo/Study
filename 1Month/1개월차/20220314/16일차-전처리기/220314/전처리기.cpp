#pragma region ��ó����

/*
#include <iostream>

// ���� ġȯ : ������ Ÿ�� ������ �ش� ��ũ�� ��ġ�� ���� �״�� ġȯ�ȴ�.
// ��� ��ũ��
//#define			PI		3.14f

// �Լ� ��ũ�� : �ڷ����� ������� �״�� ġȯ(��� �ڷ��� ȣȯ)
// ������ �켱������ �����Ͽ� �Ұ�ȣ�� ������� �Ѵ�.
// �� ��¥�� �ڵ带 ���� �� �ַ� ���(������ �Լ��� ���� ����� �� �����.)

// ���� : ��ó�����̴� ���� ����뿡 ������� �ִ�.
// ������ �Լ��� �����ϱⰡ ��ٷӴ�.

//#define			SQUARE(X)	X * X
//#define			SQUARE(X)	((X) * (X))

// �� �� �̻��� �Լ� ��ũ���� ��� ���������� �����Ͽ� 1�� ���Ⱑ �����ϴ�.
// ���� �������� �� �� ���� ���������� �������� ������ 1�ٸ� ��ũ�η� �ν��Ѵ�.
/ *
#define			SQUARE(X)	\
				((X) * (X))					
* /

//#define			SAFE_DELETE(p) if(p) { 	delete p; 	p = nullptr; }

// �Լ� ��ũ�θ� �̿��� ���ڿ� ġȯ
//#define			STRINGTEMP(A, B)		A"�� ������" B "�Դϴ�."
//#define			STRINGTEMP(A, B)		#A"�� ������" #B "�Դϴ�."
//#define		COMBINE(A, B)		A##00##B

using namespace std;

void main(void)
{
	//cout << PI << endl;

	//cout << SQUARE(5) << endl;
	//cout << SQUARE(0.1f) << endl;
	//cout << SQUARE(2 + 2) << endl;
	//cout << STRINGTEMP(�̼���, �屺) << endl;
	//cout << COMBINE(11, 22) << endl;
}*/

#pragma endregion ��ó����

#pragma region ���Ǻ� ������

/*
#if(����) : if���� ���۰� ������ ���
#elif(����) : elseif���� ����
#else
#endif : ���Ǻ� ������ ����

#ifdef : define���� ���ǵǾ� �ִٸ� ����
#elif() : define���� ���ǵǾ� �ִٸ� ����
#else  : ��� ���ǵǾ� ���� �ʴٸ� ����
#endif : ���Ǻ� ������ ����

#ifndef 
#endif : ���Ǻ� ������ ����*/

//#define		TEST 3

/*
void main(void)
{
#if 5 > TEST
	cout << "�۴�" << endl;

#elif 5 < TEST
	cout << "ũ��" << endl;

#else
	cout << "����" << endl;

#endif

}*/



#include <iostream>

using namespace std;

void main(void)
{
/*
#ifdef _DEBUG
	cout << "Hello" << endl;

#endif // _DEBUG*/
}




#pragma endregion ���Ǻ� ������

#pragma region ���۷���

/*
#include <iostream>

using namespace std;

void main(void)
{
	int			iA = 10;
	int			iB = 20;

	int&		r = iA;		// ���۷����� ���� �ϳ��� ���� �����Ѵ�.
	int&		r2 = iB;

	//int*	const p = &iA;

	r = 200;

	r = iB;

	//r = 4000;

	cout << iA << endl;
	cout << iB << endl;
}*/

#pragma endregion ���۷���