#include <iostream>

using namespace std;

void			Func(void);		// 함수의 선언부
void			Print(int _iA);
int				Get_Temp(void);
int				Add(int _iTemp, int _iSour);

void main(void)
{
	// 함수 : 데이터를 가공하는 기능 상태를 말한다.
	// 함수의 제작하는 이유 : 코드의 재사용성(같은 기능을 매번 새로 만들지 않고 한 번 만든 뒤, 필요할 때마다 불러서 사용하기 위함)

	//Func();		// 함수를 호출하고 있다(함수의 이름() : 함수 호출 연산자)

	//Print(100);

	// cout << Get_Temp() << endl;

	// Print(Get_Temp());

	cout << Add(Get_Temp(), 10) << endl;
}

//반환타입		함수이름		매개변수, 인자값, 파라미터
void			Func(void)				
{											//: 함수 정의부(몸체)
	cout << "Hello" << endl;
}
void			Print(int _iA)
{
	cout << _iA + 50 << endl;
}

int				Get_Temp(void)
{
	// 반환 타입이 void가 아닌 경우 반드시 return 키워드 사용해야 한다.
	// return : 함수를 강제로 종료하는 키워드
	// return 키워드는 삽입된 위치의 해당하는 함수를 강제 종료하는 키워드이다.

	return   400;
}
int				Add(int _iTemp, int _iSour)
{
	return _iTemp + _iSour;
}

// 1. 함수를 이용하여 자판기 코드를 수정하라