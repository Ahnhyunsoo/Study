#include <iostream>



//char* Func()
//{
//	char szName[16] = "";
//
//	cin >> szName;
//	
//	return szName;
//}
using namespace std;

void main(void)
{
	/*char* pName = Func();
	cout << pName << endl;*/

#pragma region c언어에서의 동적할당

	//malloc, calloc

	//void* 형 : 어떤 주소값의 형태인지 알 수 없을 때 사용하는 문법, 선언 시점에는
	//void* 로 선언해도 상관 없으나 실제 사용 시점에서는 어떤 자료형의 주소값인지 명시적으로 형변환을 수행해야 한다.

	/*void* malloc(size_t size);

	int* p = (int*)malloc(sizeof(int));*/
/*
	malloc과 calloc의 차이점
		1. 인자값의 개수가 다르다
		2. 할당한 heap메모리 공간의 값의 calloc의 경우는 자동 0초기화를 진행*/  // 동적 배열을 만들고자 할 때 사용하기 편하다.


	void* calloc(size_t Count, size_t Size);

	int* p = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < 5; ++i)
	{
		cout << p[i] << endl;
	}



	//*p = 20;

	//cout << (*p) << endl;

	//void free(void* p) // 동적할당한 메모리를 반환하는 함수

	//free(p);
	//p = nullptr; //댕글링 포인터를 방지하기 위해 메모리 반환이후 반드시 수행해야함.
	//cout << p << endl;

#pragma endregion c언어에서의 동적할당
}


/*
text RPG
1.전사 2.법사 3.도둑 4.불러오기 5.종료

선택시
직업 공격력 체력 레벨

선택지 =
*/


