#include <iostream>

using namespace std;

void main(void)
{

#pragma region 이중 포인터

	/*// 이중 포인터
	int			iTemp	= 10;
	int*		p		= &iTemp;
	int**		pp		= &p;

	cout << "iTemp 값 : " << iTemp << endl;
	cout << "p 값 : " << p << endl;
	cout << "pp 값 : " << pp << endl;

	cout << "=======================" << endl;

	cout << "iTemp 주소 값 : " << (&iTemp) << endl;
	cout << "p 주소 값 : " << (&p) << endl;
	cout << "pp 주소 값 : " << (&pp) << endl;

	cout << "=======================" << endl;

	cout << "iTemp 값 출력 방식 : " << iTemp << endl;
	cout << "p를 통한 iTemp 값 출력 방식 : " << (*p) << endl;
	cout << "pp를 통한 iTemp 값 출력 방식 : " << (*(*pp)) << endl;*/


#pragma endregion 이중 포인터

#pragma region 포인터의 형변환의 특징

	/*int		iA = 10;

	int*	p = &iA;

	// 포인터는 자료형 타입만 일치한다면 주소 값을 저장하는 용도 자체는 가능하기 때문에 다음과 같은 문법이 가능하다.
	float*	fp = (float*)p;

	*fp = 20.f; // 그러나 데이터 타입이 다르거나 크기가 다르면 심각한 문제를 발생시키기 때문에 포인터 자료형은 반드시 일치하도록 맞춰서 쓸 것을 권장한다.

	cout << iA << endl;*/

#pragma endregion 포인터의 형변환의 특징

#pragma region const와 포인터의 관계

	// const	int iA = 0;		// 반드시 선언과 동시에 초기화를 수행해야 함
							// 읽기 전용으로 만들겠다는 의미

	// iA = 20;
	// cout << iA << endl;

	int			iA = 0;
	int			iB = 10;
	//const int*	p = &iA;
	// int*	const  p = &iA;	// 상수 포인터(오로지 하나의 메모리 공간만 참조하는 포인터)

	const int*	const  p = &iA;		// 참조하는 주소 값, 메모리 공간이 가리키는 값 변경 불가한 완전한 읽기 전용 포인터

	//*p = 10;
	//p = &iB;

	cout << iA << endl;
	cout << (*p) << endl;



#pragma endregion const와 포인터의 관계

	

}