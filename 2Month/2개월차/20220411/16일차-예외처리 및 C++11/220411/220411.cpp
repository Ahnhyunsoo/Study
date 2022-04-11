// 220411.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#pragma region mutable

/*
class CObj
{
private:
	mutable int			m_iA;		// �б� ���� �Լ� ������ �� ������ �����ϵ��� ���ִ� Ű����
	int			m_iB;

public:
	void		Render() const // �б� ����(������ ���� �Ұ���)
	{
		m_iA = 30;
		//m_iB = 40;
	}

public:
	CObj() : m_iA(10), m_iB(20){	}
};*/

#pragma endregion mutable

#pragma region try, catch

/*
int main()
{
	// ��ǻ�ʹ� ������ 0�� ������ �� ����.
	// if���� ��� �Ϲ����� ���α׷��� ���� �����ϴµ� �� ������ �д�.

	int		iNum1, iNum2;

	cout << "���� �Է� : ";
	cin >> iNum1 >> iNum2;

	/ *if (0 == iNum2)
	cout << "0���� ���� �� �����ϴ�" << endl;

	else
	{
	cout << "�� : " << (iNum1 / iNum2) << endl;
	cout << "������ : " << (iNum1 % iNum2) << endl;
	}* /

	try
	{
		if (0 == iNum2)
			throw iNum2;

		// ������ ���� ���ܰ� �߻��ϸ� ������ �ڵ� ����� �������� �ʰ� �ǳ� �ڴ�.
		cout << "�� : " << (iNum1 / iNum2) << endl;
		cout << "������ : " << (iNum1 % iNum2) << endl;
	}

	catch (int iNum2)
	{
		cout << "0���� ���� �� �����ϴ�" << endl;
	}
	return 0;
}
*/

#pragma endregion try, catch

#pragma region C++11

/*
struct tagInfo
{
	int X;
	int Y;
};

class  CObj
{
public:
	tagInfo		Get_Info() 
	{
		return { 400, 100 };
	}

public:
	CObj(tagInfo _tInfo)
		: m_tInfo(_tInfo)
	{

	}
private:
	tagInfo		m_tInfo;
};


void main(void)
{
	// auto Ű���� : ����ڰ� ���� Ÿ���� �������� �ʾƵ� �Ǵ� ����

	/ *auto	i = 10;
	cout << sizeof(i) << endl;

	auto	l = 10l;
	cout << sizeof(l) << endl;

	auto	f = 3.14f;
	cout << sizeof(f) << endl;

	auto	p = new int;
	cout << sizeof(p) << endl;* /

	// vector<int>			vecInt;
	//vector<int>::iterator		iter = vecInt.begin();
	// auto	iter = vecInt.begin();

	// ���� ��� for�� : C#�̳� �ڹٿ��� �̹� �����ߴ� ���, C++11������ �����ϰ� ��
	// �����ϰ�, �迭 �ε��� ������ �Ѿ�� �ൿ�� ������ �� �ִ�.


	//int	iArray[5] = { 0, 1, 2, 3, 4 };

	/ *
	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << endl;* /

	/ *for (int i : iArray)
		cout << i << endl;* /

	/ *vector<int>		vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	for (auto& iter : vec)
	{
		iter += 5;
		cout << iter << endl;
	}* /

	// ������ �ʱ�ȭ

	//int	iArray[5] = { 0, 1, 2, 3, 4 };
	//int	iArray[5]{ 0, 1, 2, 3, 4 }; // ������ �ʱ�ȭ
	//tagInfo	tInfo{ 10 , 20 };

	// private ����� ������ �ʱ�ȭ �� ���� �ݵ�� �Ű������� �ִ� �����ڰ� �־�� �����Ѵ�.
	//CObj	Obj{ {100, 200} };

	/ *vector<int>		vec{ 10, 20, 30, 40, 50 };

	cout << vec.size() << "\t" << vec.capacity() << endl;

	map<int, int>	MyMap{ {1, 100},{ 2, 200 },{ 3, 300 } };

	for (auto mapiter : MyMap)
		cout << mapiter.first << "\t" << mapiter.second << endl;* /

	// std::array (stl ����)
	// ������ ����ϴ� ���� �迭�� ��üȭ ��, ������, �Ҹ���, ���� ������, ���� �����ڰ� �����Ǿ� �� �� ��ü���� �ٿ� �迭�� ���� �����ϴ�.
	// ���ʹ� ���� �迭�̾ ��� ����� ũ��. ũ�Ⱑ �̹� ������ ����� array�� ����ϴ� ���� ����. 
	

	//int	iArray[5]{ 10, 20, 30, 40, 50 };
	//int	iTemp[5]{};

	//cout << sizeof(iArray) / sizeof(int) << endl;

	//iTemp = iArray;

	// array<int, 5> arrEx; // { 1, 2, 3 };
	// cout << sizeof(arrEx) << endl;

	//int*	p = arrEx.data();	// �迭�� ù �ּҸ� ��ȯ�ϴ� �Լ�

	//arrEx.fill(999);	// �迭�� ��� ���Ҹ� ���ڰ����� ä���ִ� �Լ�

	//array<int, 5> arrTemp;

	/ *for (int i : arrEx)
		cout << i << endl;* /

	//cout << arrEx.size() << endl;

	//arrTemp = arrEx;		// ���� ���� ������ ���� �� ���簡 �����ϴ�

	/ *for (int i : arrTemp)
		cout << i << endl;* /

	// �ݺ���, empty, swap, front, back �Լ��� ����
	// push_back, clear�� ���� �Լ��� �������� �ʴ´�.



}
*/
#pragma endregion C++11

#pragma region ����(lambda) ǥ����

/*
void main(void)
{
	// ���ٽ� : �Լ� ��ü ������ �߻��� ����

	// �Լ� ��ü�� ���� : �ۼ��� �������� ���ϴ�, �Ϲ� ��� ������ �Լ����� ��ü���� ������ ��ƴ�.
	// ���ٽ��� ���� : �ۼ��� ���ϰ�, �������� �����ȴ�, �۵� �ӵ��� ������.
	// �Լ� ����γ� ��ü�� ���� ã�� �ʿ䰡 ���� ������ �������� �����ȴ�.

	//vector<int>		vec{ 10, 20, 30, 40, 50 };
	//for_each(vec.begin(), vec.end(), [](int n) {cout << n << endl; });

/ *
// 	vector<int>		vec{ 10, 20, 33, 40, 50 };
// 
// 	auto		iter = find_if(vec.begin(), 
// 								vec.end(), 
// 								[](int n)->bool { return (0 != n % 2);  });
// 
// 	cout << (*iter) << endl;
* /

	/ *vector<int>		vec{ 1, 2, 3, 4, 5 };

	int	iEvenSum = 0;
	int	iOddSum = 0;

	for_each(vec.begin(), vec.end(), [&](int n) {
		if (0 == n % 2)
			iEvenSum += n;

		else
			iOddSum += n;

	});

	cout << iEvenSum << endl;
	cout << iOddSum << endl;* /


	// ���ٽ� ����

	// [] : '���� �Ұ���', �����Ϸ��� �� ��ȣ�� ������ ���ٽ����� �����ϰ� ��
	// () : '�Ķ���� ������', �Ϲ� �Լ��� �Ķ���Ϳ� ������
	// {} : '���� ��ü',  �Ϲ� �Լ��� ��ü�� ���� �ǹ�

	// []() {cout << "hello world" << endl; }();
	// [](int iTemp) { cout << iTemp << endl; }(100);
	// [](int iTemp = 100) { cout << iTemp << endl; }();

	// ������ ��ȯ : ���� �Լ� ��ü ���ο��� �߻��� ��������� �����Ϸ��� �߷��Ͽ� ��ȯ Ÿ���� ����
	// int	iResult = [](int iTemp, int iSour) { return iTemp + iSour;  }(10, 20);
	
	// ����� ��ȯ
	// int	iResult = [](int iTemp, int iSour)->int { return iTemp + iSour;  }(10, 20);
	// cout << iResult << endl;
	
	// ĸó�� : ���� �Ұ��ڸ� �ٸ��� �θ��� ǥ��, �ܺο� �ִ� �����͸� �����ϴ� ����� ��ȣȭ�� ��


	/ *vector<int>		vec{ 1, 2, 3, 4, 5 };

	int	iEvenSum = 0;
	int	iOddSum = 0;

	for_each(vec.begin(), vec.end(), 
		[iEvenSum, iOddSum](int n)	mutable	// ������ �����Ͽ� ĸó(const ������ �Ǿ� �б� ������ �ȴ�.)
	{
		if (0 == n % 2)
			iEvenSum += n;	// �纻

		else
			iOddSum += n;	// �纻

	});

	cout << iEvenSum << endl;		// ���� ������ �Ͼ�� ����
	cout << iOddSum << endl;		// ���� ������ �Ͼ�� ����* /


// 	int	a = 10, b = 20, c = 30, d = 40;
// 
// 	[&a, &b, &c](int n)			// ���۷����� ĸó
// 	{
// 		a += n;
// 		b += n;
// 		c += n;
// 		d += n;
// 
// 	}(100);
// 
// 	cout << a << endl;
// 	cout << b << endl;
// 	cout << c << endl;
// 	cout << d << endl;

}
*/

#pragma endregion ���� ǥ����

void main(void)
{

}


