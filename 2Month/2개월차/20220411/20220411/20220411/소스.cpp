#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

using namespace std;



struct taginfo
{
	int a;
	int b;
};

class CObj
{
public:
	taginfo Get_info() {
		return{ 300,400 };
	}

private:
	taginfo m_tinfo;
public:
	CObj(taginfo _tinfo)
		:m_tinfo(_tinfo)
	{

	}
};


#pragma region mutable
//class CObj
//{
//private:
//	mutable int m_iA;  //�б� ���� �Լ� ������ �� ������ �����ϵ��� ���ִ� �Լ�
//	int m_iB;
//
//public:
//	void Render() const // �б� ����(������ ���� �Ұ���)
//	{
//		m_iA = 30;
//		//m_iB = 40;
//	}
//
//public:
//	CObj() : m_iA(10)//m_iB(20)
//	{
//
//	}
//};
#pragma endregion mutable

#pragma region ����ó��
//// ��ǻ�ʹ� ������0�� ������ �� ����.
//	// if���� ��� �Ϲ����� ���α׷��� ���� �����ϴµ� �� ������ �д�.
//int iNum1, iNum2;
//cout << "���� �Է� : ";
//cin >> iNum1 >> iNum2;
//
///*if (0 == iNum2)
//	cout << "0���� ���� �� �����ϴ�" << endl;
//else
//{
//	cout << "�� : " << (iNum1 / iNum2) << endl;
//	cout << "������ : " << (iNum1 % iNum2) << endl;
//}*/
//
//try
//{
//	if (0 == iNum2) // ����ó��
//		throw iNum2; //catch�� ������
//
//	//������ ���� ���ܰ� �߻��ϸ� ������ �ڵ� ����� �������� �ʰ� �ǳ� �ڴ�.
//	cout << "�� : " << (iNum1 / iNum2) << endl;
//	cout << "������ : " << (iNum1 % iNum2) << endl;
//}
//catch (int iNum2)
//{
//	cout << "0���� ���� �� �����ϴ�." << endl;
//}
#pragma endregion ����ó��


void main(void)
{
#pragma region C++11
	//auto Ű���� : ����ڰ� ���� Ÿ���� �������� �ʾƵ� �Ǵ� ����
	//auto�� �� �ʱ�ȭ�� ����� �Ѵ�.
	//auto�� �����Ϸ��� Ÿ���� �Ǵ��ϰ� �Ѵ�.
	//auto�� ��� �Ǻ��� �ָ�������. Ÿ�Ա����� ����

	/*auto i = 10;
	cout << sizeof(i) << endl;
	auto f = 3.14f;
	cout << sizeof(f) << endl;
	auto p = new int;
	cout << sizeof(p) << endl;
	*/

	// ���� ��� for�� : C# �̳� �ڹٿ��� �̹� �����ߴ� ���, C++11������ �����ϰ� ��
	// �����ϰ�, �迭 �ε��� ������ �Ѿ�� �ൿ�� ������ �� �ִ�.
	
	/*int iArray[5] = { 1,2,3,4,5 };

	for (int i : iArray)
		cout << i << endl;*/

	//vector<int> vec;
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);
	//vec.push_back(40);
	//vec.push_back(50);
	//
	//for (auto& iter : vec)
	//	cout << iter << endl;

	//������ �ʱ�ȭ
	//int iArray[5] = { 0,1,2,3,4 };
	/*int iArray[5]{ 1,2,3,4,5 };
	taginfo t{ 10,20 };

	vector<int> vec{ 1,2,3,4,5 };

	cout << vec.size() << " " << vec.capacity() << endl;*/

	/*map<int, int> MyMap{ {1,100},{2,200},{3,300} };
	for (auto mapiter : MyMap)
		cout << mapiter.second << endl;*/

	//����� �� ���� ������ 

	// std::array (stl����)
	// : ������ ����ϴ� ���� �迭�� ��üȭ ��, ������, �Ҹ���, ���� ������, ���Կ����ڰ� �����Ǿ� �� �� ��ü���� �ٿ� �迭�� ���� �����ϴ�
	// ���ʹ� ���� �迭�̾ ��� ����� ũ��.
	//�����迭�� �����Ͻ����� �������⶧���� �ӵ��� ��������. �뷮�� �� ����.
	//int iArray[5]{ 10,20,30,40,50 };
	//int iTemp[5]{};
	////cout << sizeof(iArray) / sizeof(int) << endl;

	//array<int, 5> arrEx{ 1,2,3 };
	//array<int, 5> arrTemp;
	//int* p = arrTemp.data(); // �迭�� ù �ּҸ� ��ȯ�ϴ� �Լ�
	//arrEx.fill(999); // �迭�� ��� ������ ���ڰ����� ä��� �Լ�
	//arrTemp = arrEx;
	//for (int i : arrTemp) // ���� ���� ������ ���� �� ���簡 �����ϴ�
	//	cout << i << endl;

	//�ݺ���, empty, swap, front, back �Լ��� ������
	//push_back, clear �Լ��� �������� ���� �����迭�̱� ������

	//cout << arrEx.size() << endl;

#pragma endregion C++11
	
#pragma region ���� ǥ����

	// ���ٽ� : �Լ� ��ü ������ �߻��� ����,
	
	// �Լ� ��ü�� ���� : �ۼ��� �������� ���ϴ�, �Ϲ� ��� ������ �Լ����� ��ü���� ������ ��ƴ�.
	// ���ٽ��� ���� : �ۼ��� ���ϰ�, �������� ���� �ȴ�, �۵� �ӵ��� ������(����).
	// ���ٽ��� �ζ��� �Լ��� �޸𸮰����� �ö����ʰ� ����� ȣ��ǰ� �Ҹ�ȴ�.
	// �Լ� ����γ� ��ü�� ���� ã�� �ʿ䰡 ���� ������ �������� �����ȴ�.

	//vector<int> vec{ 10,20,30,40,50 };
	//for_each(vec.begin(), vec.end(), [](int n) {cout << n << endl; });

	/*vector<int> vec{ 10,20,33,40,50 };

	auto iter = find_if(vec.begin(), vec.end(), [](int n)->bool {return 0 != n % 2; });

	cout << (*iter) << endl;*/

	/*vector<int> vec{ 1,2,3,4,5 };

	int iEvenSum = 0;
	int iOddSum = 0;

	for_each(vec.begin(), vec.end(), [&](int n) { ������ �����Ͽ� ĸó (const ������ �Ǿ���Ѵ�)
		if (0 == n % 2)
			iEvenSum += n;

		else
			iOddSum += n;
		});
	
	cout << iEvenSum << endl;
	cout << iOddSum << endl;*/
	// ���ٽ� ����
	/*[] : '���� �Ұ���', �����Ϸ��� �� ��ȣ�� ������ ���ٽ����� �����ϰ� ��
	() : '�Ķ���� ������', �Ϲ� �Լ��� �Ķ���͞� ������
	{} : '���� ��ü', �Ϲ� �Լ��� ��ü�� ���� �ǹ�*/

	//[]() {cout << "hello world" << endl; } (); // ȣ�� // ���ٽ�

	//���ٽ��� �Լ������Ͱ� �ƴϴ�. ����� �����ǰ� �Ҹ�Ǵ� �����̱� ������.
	//������ ��ȯ : ���� �Լ� ��ü ���ο��� �߻��� ��������� �����Ϸ��� �߷��Ͽ� ��ȯ Ÿ���� ����
	//int iResult = [](int iTemp, int iSour) { return iTemp + iSour; } (10, 20);
	//cout << iResult << endl;
	
	//����� ��ȯ
	//int Result = [](int iTemp, int iSour)->int { return iTemp + iSour; }(10, 20);

	// ĸó�� : ���� �Ұ��ڸ� �ٸ��� �θ��� ǥ��, �ܺο� �ִ� �����͸� �����ϴ� ����� ��ȣȭ �� ��
	
	int a = 10, b = 20, c = 30, d = 40;
	[&a,&b](int n) // ���۷����� ĸó a,b�� ���� �� a,b�� ���۷����� ĸó��.
		//&���ָ� ���δ� ���۷����� ĸó�ϰڴٴ� ���̴�.
		//static������ ���������� ĸó�Ұ�
		//���ٽ��� �ζ��� �Լ��� ������ static������ ���������� ������� �ȵȴ�.
		//�ݺ����� �۾��� ���м� ���鿡�� �Լ���ü�� ����
		// �ӵ��� �߿��� �۾��̸� ���ٽ��� �����⶧���� ���ٽ��� ����.
	{
		a += n;
		b += n;
		c += n;
		d += n;
	}(100);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;



#pragma endregion ���� ǥ����
	
}