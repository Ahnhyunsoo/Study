// 220408.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


class CTag_Finder
{
private:
	char*		m_pTag;

public:
	CTag_Finder(char* pTag)
		: m_pTag(pTag) {	}

public:
	template<typename T>
	bool	operator()(T& Pair)
	{
		if (!strcmp(Pair.first, m_pTag))
			return true;

		return false;
	}
};

int main()
{
	// map : 연관 컨테이너(비 선형적), 자가 균형 이진 탐색 트리(레드-블랙 트리)로 구현
	// 중위 순회 기반으로 원소들을 정렬하는 트리 구조의 컨테이너

	// 탐색의 용이한 컨테이너이기 때문에 : 리소스 탐색

	// 특징
	// 1. map은 key, value라는 한 쌍의 데이터를 원소로 삼는다.
	// 2. map은 key 값 기준으로 자동 정렬이 일어난다.빈번한 삽입, 삭제가 발생한 경우 속도가 매우 느리다.
	// 3. map은 key 값에 따라 정렬이 되어있기 때문에 반복자를 통한 탐색이 가능하다.
	// 4. map은 노드 기반 컨테이너 중 유일하게[]연산자가 오버로딩 되어 있어 'key값으로' 임의 접근이 가능하다.
	// 5. map은 양방향 반복자를 갖고 있다.
	// 6. map은 중복 key 값을 허용하지 않는다.

#pragma region map 컨테이너의 기본 사용법

	//map<key값의 자료형, value값의 자료형, 조건자>

	//map<int, int>		MapInt;
	//map<char*, CObj*>
	//map<string, list<CObj*>>

	// pair객체 : 한 쌍을 이루는 원소를 템플릿화 하여 저장할 수 있는 형식으로 만드는 것

	// 클래스 템플릿

	// 1. pair 객체를 만들어서 원소를 삽입하는 방법
	//pair<int, int>		MyPair;
	// 원소에 대입하여 값 변경 가능, 선언만 하고 초기화하지 않는다면 자동 0 초기화
	/*
	MyPair.first = 2;
	MyPair.second = 200;*/

	//MapInt.insert(MyPair);		// 키값에 해당하는 노드가 존재하지 않는다면 해당 키와 value로 구성된 노드를 생성하여 삽입하는 함수

	// 2. 임시 pair 객체를 만들어서 원소를 삽입하는 방법
	//MapInt.insert(pair<int, int>(1, 100));

	// 3. []연산자를 통한 원소 삽입
	//MapInt[2] = 200;			// 해당 인덱스 값의 노드가 없는 경우 노드를 생성하여 value로 값을 대입
								// 해당 인덱스 값의 노드가 있는 경우 value 값만 대입이 가능

	// 4. make_pair함수를 이용하여 원소를 삽입하는 경우(pair 객체를 직접 생성하는 것보다 작동속도가 떨어진다)
	//MapInt.insert(make_pair(3, 300));

	// 5. 데이터 삽입의 정규 문법 value_type을 이용하여 원소를 삽입하는 경우
	//map<int, int>::value_type	MyMap(4, 400);	// namespace에 정의되어 있어서 ::연산을 사용해야 함, 선언만 하고 초기화하지 않을 경우 자동 0으로 초기화된다.
	//MapInt.insert(MyMap);

	// MyMap.first = 5;			key값에 자동 const가 삽입
	// MyMap.second = 500;		value는 대입 가능

	// 6. value_type 임시 객체를 이용하여 원소를 삽입하는 경우
	//MapInt.insert(map<int, int>::value_type(5, 500));

	// 7. c++11이후 발생한 emplace 함수를 이용한 원소 삽입 경우
	//MapInt.emplace(6, 600);

	// 8. c++11이후 발생한 유니폼 초기화를 이용한 원소 삽입 경우
	//MapInt.insert({7, 700});

	/*map<int, int>::iterator		iter = MapInt.begin();

	for( ; iter != MapInt.end(); ++iter)
		cout << "key 값 출력 : " << iter->first <<"\tvalue 값 출력 : " << iter->second << endl;*/

#pragma endregion map 컨테이너의 기본 사용법

#pragma region map 컨테이너의 각종 멤버 함수

		// size(), clear(), empty(), begin(), end()

	/*map<int, int, greater<int>>		MapInt;

	MapInt.insert({ 1, 100 });
	MapInt.insert({ 2, 200 });
	MapInt.insert({ 3, 300 });
	MapInt.insert({ 4, 400 });
	MapInt.insert({ 5, 500 });

	map<int, int>::iterator		iter = MapInt.begin();*/

	// iter += 3;		// map 컨테이너는 임의 접근이 불가능한 양방향 반복자를 갖고 있다.

	//++iter;
	//++iter;

	//MapInt.insert(iter, { 6, 600 });		// map은 자동정렬이 일어나기 때문에 중간 삽입을 하더라도 큰 의미가 없다.
											// 중간 삽입해도 반복자의 무효화가 일어나지 않아 중간 삽입의 의미가 없다.												

	// iter = MapInt.erase(iter);				// erase를 통한 삭제 시에는 반복자의 무효화가 일어나기 때문에 반드시 다음 반복자를 반환해주거나 begin 위치로 초기화 해야한다.
	// cout << iter->first << "\t" << iter->second << endl;

	/*for(iter = MapInt.begin(); iter != MapInt.end(); ++iter)
		cout << iter->first << "\t" << iter->second << endl;*/


#pragma endregion map 컨테이너의 각종 멤버 함수

#pragma region map 컨테이너의 키값 문자열

		/*
		map<char*, int>		MapChar;

		MapChar.insert({ "AAA", 100 });
		MapChar.insert({ "BBB", 200 });
		MapChar.insert({ "CCC", 300 });

		map<char*, int>::iterator		iter = MapChar.begin();

		/ *for (iter = MapChar.begin(); iter != MapChar.end(); ++iter)
		cout << iter->first << "\t" << iter->second << endl;* /

		// iter = MapChar.find("AAA");	// 0x16 , 0x27

		iter = find_if(MapChar.begin(), MapChar.end(), CTag_Finder("AAA"));

		// 멀티 쓰레드 기반의 프로그래밍, dll기반의 다중 프로젝트
		cout << iter->first << "\t" << iter->second << endl;*/

// 문자열이 키 값일 때 정렬은 어떻게 되는가
/*
1. key 값이 char 형인 경우 아스키코드 값, 즉 알파벳 순으로 정렬이 일어난다.
2. key 값이 char* 형인 경우 16진수 주소(정수 값) 기준으로 정렬이 일어난다.
3. key 값 정렬을 문자열 기준으로 하고자 한다면 char* 형이 아니라 string을 사용해야 한다.(string 컨테이너는 내부적으로 문자열 대소비교 기능이 오버로딩 되어있음)
4. char* 형을 굳이 정렬하고 싶다면 조건자를 직접 만들어서 비교 함수를 만들어야 한다.*/

#pragma endregion map 컨테이너의 키값 문자열

	return 0;
}

