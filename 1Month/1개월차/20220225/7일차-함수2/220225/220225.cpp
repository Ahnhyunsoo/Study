#include <iostream>

using namespace std;

#pragma region data 영역과 stack 영역의 특성
/*
int		iTemp;			// 데이터 영역에 할당되는 전역 변수 : 한 파일 안에서는 전역적으로 사용이 가능한 변수
						//int		iTest = 4000;

static	int	iTest = 3000;

void	Plus(void)
{
	//int iTemp = 10;		// 스택 메모리에 할당된 지역 변수(그 지역 안에서만 유효한 이름)

	// cout << ++iTemp << endl;

	iTemp = 100;
	cout << iTest << endl;
}

void	Minus(void)
{
	//int iTemp = 10;
	//cout << (--iTemp) << endl;

	iTemp = 200;
	cout << iTemp << endl;
}

void		Add(void)
{
	static int	iTest = 1000;		// 데이터 영역에 할당되는 정적 변수 : 지역 내에서 선언하며, 지속적으로 메모리를 공유하여 사용할 수 있다.

	cout << iTest << endl;

	cout << (++iTest) << endl;
}


void main(void)
{
	/ *int	iA = 10;
	int	iB = 20;
	int	iC = 30;* /

	//Plus();
	//Minus();
	//Add();
	//Add();
	//Add();

	//cout << iTest << endl;

	cout << iTemp << endl;

}*/
#pragma endregion data 영역과 stack 영역의 특성

#pragma region 추가적인 함수 문법

/*
void	Render(int	_iA, int _iB = 0);		// 디폴트 매개변수 : 맨 뒤쪽부터 차례대로 값을 채워서 사용
void	Print(int);

// 함수 오버로딩 : 함수의 이름이 같을 때, 매개 변수의 개수, 자료형 타입에 따라 어떤 함수가 호출될 지 결정되는 문법
// 반환 타입이 다르다는 이유로 함수 오버로딩이 성립되지는 않는다.
// 함수 오버로딩 시, 디폴트 매개변수를 활용하는 함수와 호출 모호성을 발생시키지는 않는지 고려해야 한다.

/ *
void	Draw();				//	1
void	Draw(int _iTemp);	//  2
void	Draw(float _fTemp);	//  3* /
// int		Draw(int _iTemp);	//  4
// void	Draw(int _iTemp, int _iSour = 0); //5

namespace A
{
	void	Draw(void) { cout << "A" << endl; }
}

namespace B
{
	void	Draw(void) { cout << "B" << endl; }
}

/ *
using A::Draw;

using std::cout;* /

void main(void)
{
	//Render(200);
	//Print(10);

	A::Draw();
}
*/

/*
void	Render(int	_iA, int _iB)
{
	cout << _iA << endl;
	cout << _iB << endl;
}

void Print(int)
{
	cout << "출력" << endl;
}

void	Draw()
{
	cout << "Draw" << endl;
}
void	Draw(int _iTemp)
{
	cout << "_iTemp Draw" << endl;
}
void	Draw(float _fTemp)
{
	cout << "_fTemp Draw" << endl;
}*/
/*
void	Draw(int _iTemp, int _iSour)
{
	cout << "_iTemp _iSour" << endl;
}*/
/*
int		Draw(int _iTemp)
{
	return _iTemp;
}*/

#pragma endregion 추가적인 함수 문법

#pragma region 재귀 함수

// 재귀 함수 : 자기 자신에게 돌아가는 함수라는 뜻으로 자신을 다시 호출하는 형태의 함수를 뜻한다.
// 반드시 탈출 조건을 만들어야만 한다. 안그러면 무한 루프에 빠지게 된다.

// void	Return();  수정 전

void	Return(int iNumber);

void main(void)
{
	Return(5);
}

/*
void	Return()
{
	cout << "재귀 호출" << endl;
	Return();
}*/
void	Return(int iNumber)
{
	if (0 >= iNumber)
		return;

	cout << "재귀 호출" << endl;

	Return(--iNumber);
}

#pragma endregion 재귀 함수


// 5 팩토리얼을 함수로 구현하라
// 5! = 5 * 4 * 3 * 2 * 1