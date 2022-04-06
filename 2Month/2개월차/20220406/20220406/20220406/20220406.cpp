// 20220406.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//아까꺼는 함수 객체

//함수 템플릿

template <typename T>
bool Num(T num)
{
	if (0 != num % 2)
		return true;

	return false;
}

template<typename T>
bool Less(T left, T right)
{
	return left < right;
}

int main()
{
#pragma region 메모리 확보를 위한 vector의 함수들

	//vector<int> vecTemp;
	////vecTemp.resize(50);
	////resize(); 원소의 갯수를 다시 조정하는 함수, 단, 이미 확보된 메모리 공간은 줄어들지 않는다.

	//vecTemp.push_back(10);
	//vecTemp.push_back(20);
	//vecTemp.push_back(30);
	//vecTemp.push_back(40);

	//vecTemp.reserve(10); // 오로지 메모리 공간만 미리 예약해주는 함수 리절브는 꼭해야한다. 재할당하면 속도가 많이 줄어든다.
	////미리 공간을 잡아두는것이 재할당하는것보다 훨신 빠르다.


	//cout << "Size : " << vecTemp.size() << "\tCapacity : " << vecTemp.capacity() << endl;


#pragma endregion 메모리 확보를 위한 vector의 함수들



#pragma region 알고리즘과 조건자

	// 조건자 : bool 타입을 반환하는 함수 또는 함수 객체로 stl 알고리즘을 수행하기 위한 조건

	//int iArray[5] = { 3, 4 , 1 , 5 , 2 };
	
	//sort(iArray, iArray + 5, Less<int>); // sort라는 알고리즘은 디폴트조건자가 오름차순이다.

	/*for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << endl;
	}*/
	//count_if 컨테이너 원소를 순회하면서 조건자의 반환 결과가 true일 때 개수를 반환하는 함수
	//int iCount = count_if(iArray, iArray + 5, Num<int>);
	//cout << iCount << endl;

	//알고르즘( 범위 범위 조건자)
	find();
	<char*, >
		"jusin" = 문자열 상수 
		상수메모리에 올라가고
		캐릭터포인터에 이 상수메모리의 주솟값을 넣어주는것이다
	find_if();

#pragma endregion 알고리즘과 조건자

    return 0;
}

//과제 : 인벤토리 크기는 5칸
//백터를 이용한 텍스트알피지 구현

/*		vec.begin(),vec.end(), 함수명 함수객체는 연산자오버로딩을 통해 외부데이터를 참조할 수 있다.(그리고 함수객체는 메모리할당이 아닌 임시메모리이기 때문에 속도가 빠르다).
for_each(어디부터,어디까지,함수포인터or함수객체)

erase 동작원리
iterator를 이용한 조건자를 for each로 바꿔보기 알고리즘 사용법 익히기

반복자의 종류
1. 출력 반복자 2. 입력 반복자 3. 순방향 반복자 4. 양방향 반복자 5. 임의 접근 반복자
양방향 반복자, 임의 접근 반복자 주로 사용함
1~5번으로 갈수록 좋아짐 5번이 제일 좋은 반복자
임의접근 반복자를 사용하는 컨테이너 = 백터 데크
리스트포함 컨테이너들은 양방향 반복자를 사용한다.

insert함수 중간에 삽입해주는 함수
vec.insert(iter, data);
insert시에 만약 크기가 부족할 시 재할당과 원소들의 재배치가 일어나기 때문에 리스트에 비해서 불합리적이다.
iterator 는 원소를 가르키기 위한 객체
iterator는 독립적인 객체다
iterator의 주소와 iterator의 값은 완전 다르다.
iterator는 메모리를 가르키는게 아닌 원소를 가르키는것이다.







*/



