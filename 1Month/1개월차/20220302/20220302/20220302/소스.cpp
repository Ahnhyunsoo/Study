#include <iostream>

using namespace std;

void main(void)
{

#pragma region 이중 포인터
	/*int iTemp = 10;
	int* p = &iTemp;
	int** pp = &p;

	cout << iTemp << endl;
	cout << p << endl;
	cout << pp << endl;

	cout << &iTemp << endl;
	cout << &p << endl;
	cout << &pp << endl;

	cout << iTemp << endl;
	cout << *p << endl;
	cout << **pp << endl;*/


	//포인터는 자료형 타입만 일치한다면 주소 값을 저장하는 용도 자체는 가능하기 때문에 형변환이 가능하다.
	//그러나 데이터 타입이 다르거나 크기가 다르면 심각한 문제를 발생시키기 때문에 포인터 자료형은 반드시 일치하도록 해야한다.
	//실수형을 정수형으로 바꾸면 쓰레기값때문에 결과값이 바뀐다.

	

#pragma endregion 이중 포인터
}