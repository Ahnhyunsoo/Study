#include <iostream>

using namespace std;


char*	Func()
{
	//char szName[16] = "";		// 지역변수

	char*	pName = (char*)calloc(16, sizeof(char));
	// 0x30

	cin >> pName;

	return pName;
}


void main(void)
{
	//char*		pName = Func();
	//cout << pName << endl;

	//free(pName);
	//pName = nullptr;


#pragma region c언어에서의 동적할당

	// malloc, calloc

	// void* 형 : 어떤 주소값의 형태인지 알 수 없을 때 사용하는 문법, 선언 시점에는 void*로 선언해도 무방하나
	//            실제 사용시점에는 어떤 자료형의 주소값이 반드시 명시적으로 형변환을 수행해야 한다.

	// void*		malloc(size_t size);		// 동적할당을 수행하는 함수
	// int*	p = (int*)malloc(sizeof(int));

	//void*			calloc(size_t Count, size_t Size);

	//malloc과  calloc의 차이점

	//1. 인자값의 개수가 다르다
	//2. 할당한 heap메모리 공간의 값의 calloc의 경우 자동 0초기화를 진행한다.

//	int	iCount = 0;
	//cin >> iCount;

	//int*	p = (int*)calloc(iCount, sizeof(int));		// 동적배열을 만들고자 할 때 사용이 편리하다.

//	int*	p = (int*)malloc(iCount * sizeof(int));

	//for (int i = 0; i < iCount; ++i)
	//	cout << p[i] << endl;
	
	//cout << p << endl;		// heap 공간의 주소값 출력

	//cout << (*p) << endl;

	// void free(void* p);		// 동적할당한 메모리를 반환하는 함수

	//free(p);	
	//p = nullptr;			// 댕글링 포인터를 방지하기 위해 메모리 반환이후 반드시 수행해야 함.

	/*cout << p << endl;		// heap 공간의 주소값 출력(댕글링 포인터)
	*p = 100;

	cout << (*p) << endl;*/
	
#pragma endregion c언어에서의 동적할당

#pragma region  c++언어에서의 동적할당

	/*int*	p = new int;	// 연산자를 통해 동적할당을 int형 크기만큼을 heap할당을 하고 그 첫 번째 주소를 리턴

	cout << p << endl;

	delete p;		// 연산자를 통해 메모리 반환
	p = nullptr;*/
	//cout << p << endl;

	/*int*	p2 = new int[4];		// int형 4개 크기만큼을 힙공간에 할당

	for (int i = 0; i < 4; ++i)
		cout << p2[i] << endl;

	delete[] p2;			// 동적 배열을 메모리 반환하는 문법
	p2 = nullptr;*/

	// 조심해야할 사항 : 프로그래머는 heap메모리에 누수가 발생하지 않도록 반드시 관찰하고, 메모리를 해제하는 코드를 짜야 한다.

	/*int		iA = 100;
	int*	p = new int;

	p = &iA;

	*p = 20;*/	

#pragma endregion  c++언어에서의 동적할당

}