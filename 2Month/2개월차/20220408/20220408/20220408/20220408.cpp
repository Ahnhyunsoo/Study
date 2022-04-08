// 20220408.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//자가 균형 이진 탐색 트리 = 반씩 쳐내서 탐색을 빠르게 하기위해 키값을 기준으로 정렬 

class CTag_Finder
{
private:
	char* m_Ptag;
public:
	CTag_Finder(char* ptag)
		: m_Ptag(ptag) {}

public:
	template<typename T>
	bool operator() (T& Pair)
	{
		if (!strcmp(Pair.first, m_pTag))
			return ture;

		return false;
	}
};

void main()
{
	/*
	map : 연관 컨테이너(비 선형적), 자가 균형 이진 탐색트리(레드-블랙 트리)로 구현
	중위 순회 기반으로 원소들을 정렬하는 트리 구조의 컨테이너
	탐색의 용이한 컨테이너이기 때문에 : 리소스 탐색

	특징

	1. map은 key, value라는 한 쌍의 데이터를 원소로 삼는다.
	2. map은 key 값 기준으로 자동 정렬이 일어난다. 삽입, 삭제가 발생할 경우 속도가 매우 느리다
	3. map은 key 값에 따라 정렬이 되어있기 때문에 반복자를 통한 탐색이 가능하다.
	4. map은 노드 기반 컨테이너 중 유일하게 []연산자가 오버로딩 되어 있어 'key값으로' 임의 접근이 가능하다.
	5. map은 양방향 반복자를 갖고 있다.
	6. map은 중복 key 값을 허용하지 않는다.

	*/

#pragma region map 컨테이너의 기본 사용법

	//map<키값의 자료형, value값의 자료형,조건자>

	map<int, int> MapInt;
	////map<string, list<CObj*>>
	//1. 페어 객체를 만들어서 원소를 삽입하는 방법
	////pair객체 : 한 쌍을 이루는 원소를 템플릿화 하여 저장할 수 있는 형식으로 만드는 것
	////클래스 템플릿
	//pair<int, int> MyPair(1, 10);
	//페어는 원소에 대입하여 값 변경 가능, 선언만하고 초기화 하지 않을 경우 0으로 자동 초기화됨
	//MapInt.insert(MyPair);
	////MapInt.insert(2, 20);
	////키값은 상수여야한다. 그래서 const를 붙여서 참조한다.
	//map<int, int>::iterator iter = MapInt.begin();

	//cout << "key = " << (*iter).first << "value = " << (*iter).second << endl;

	//2. 임시 pair 객체를 만들어서 원소를 삽입하는 방법
	//insert = 키값에 해당하는 노드가 존재하지 않는다면 해당 키와 벨류로 구성된 노드를 생성하여 삽입하는 함수
	//insert = 키값에 해당하는 노드가 없으면 생성 / 노드가 있으면 값만 대입

	//3. []연산자를 통한 원소 삽입
	//MapInt[1] = 200;	//해당 인덱스 값의 노드가 없는 경우 노드를 생성하여 value로 값을 대입
	//MapInt.insert(pair<int,int>(1,100);

	//4. make-pair함수를 이용하여 원소를 삽입하는 경우(pair 객체를 직접 생성하는 것보다 작동속도가 느려진다.)
	//MapInt.insert(make_pair(3,300)); // make_pair = 반환값을 페어로 갖는 템플릿

	//5. 데이터 삽입의 정규 문법 valut_type 을 이용하여 원소를 삽입하는 경우
	//map<int, int>::value_type MyMap(4,400); namespace에 정의되어 있어서 ::연산자를 사용해야함 key값에 자동 const가 삽입
	//MyMap 선언만 하고 초기화하지 않을 경우 자동으로 0초기화
	//MapInt.insert(MyMap);

	//MyMap.first = 5; // 키값이 const라 변경 불가능
	//MyMap.second = 200; // value는 가능

	//6. value_type 임시 객체를 이용하여 원소를 삽입하는 경우
	//MapInt.insert(map<int, int>::value_type(5,500)); // STL이 제일 추천하는 방법

	//7. c++이후 발생한 emplace 함수를 이용한 원소 삽입 경우 7번은 insert를 사용하기 때문에 내부적으로 논리판단을 한다.
	//MapInt.emplace(6,600); emplace를 쓰는게 편하다.

	//8. c++11이후 발생한 유니폼 초기화를 이용한 원소 삽입 경우 // 7,8번 중에 8번이 속도가 빠르다.
	//MapInt.insert({ 7,700 });



#pragma endregion map 컨테이너의 기본 사용법
   

#pragma region map 컨테이너의 각종 맴버 함수
	
	//size(), clear(), empty(), begin(), end()
	//map<int, int> MapInt;
	//MapInt.insert({ 1,100 });
	//MapInt.insert({ 2,200 });
	//MapInt.insert({ 3,300 });

	//map<int, int>::iterator iter = MapInt.begin();

	//iter += 3; // map 컨테이너는 임의 접근이 불가능한 양방향 반복자를 갖고 있다.
	//3칸 이동하려면 ++iter를 3번 해야한다. --도 가능 무조건 for문을 이용해서 찾아야한다.

	//MapInt.insert(iter,{6,600}); // map은 자동정렬이 일어나기 때문에 중간 삽입을 하더라도 큰 의미가 없다
	//중간 삽입해도 반복자의 무효화가 일어나지 않아서 중간 삽입 의미가 없다.
	//erase 함수의 개념은 동일하다. 반복자의 무효화가 일어나기 때문에 반드시 다음 반복자를 반환해주거나 begin 위치로 초기화 해야한다.
	//cout << iter->first << endl; // 불가능

	//map<int,int,greater<int>> 

	

#pragma endregion map 컨테이너의 각종 맴버 함수
	

#pragma region map컨테이너의 키 값 문자열
	//map<char*, int> MapChar;
	//MapChar.insert({"AAA",100});
	//MapChar.insert({"BBB",200});
	//MapChar.insert({"CCC",300});
	//MapChar.find();
	//find() = 키값을 입력하면 키값에 해당하는 iterator를 반환해준다.
	//iter = MapChar.find("AAA"); AAA의 키값을 갖고 있는 iter를 반환
	//char*로 했을 경우 멀티 쓰레드 기반 프로그램에서 문제가 생길 수 있다.
	//컴파일 타이밍에 AAA주소를 부여하는데 컴파일 타이밍이 다르기 때문에 주소가 바뀔 수 있다.
	//주소값이 바뀌기 때문에 문제가 생긴다. 때문에 글자로 찾으면 문제가 생기지않는다. 그래서 string을 쓴다.
	//iter = find_if(MapChar.begin(), MapChar.end(), 조건자  //조건자로 함수 템플릿을 썻을 경우 매개변수를 받을 수 없다. 때문에 함수객체를 쓴다.
	
	//문자열이 키 값일 때 정렬은 어떻게 되는가
	//1. key 값이 char 형인 경우 아스키코드값, 즉 알파벳 순으로 정렬이 일어난다.
	//2. key 값이 char* 형인 경우 16진수 주소(정수 값) 기준으로 정렬이 일어난다.
	//3. key 값 정렬을 문자열 기준으로 하고자 한다면 char* 형이 아니라 string을 사용해야 한다. string 컨테이너 내부적으로 문자열 대소비교 기능이 오버로딩 되어있음
	//4. char* 형을 굳이 정렬하고 싶다면 조건자를 직접 만들어서 비교 함수를 만들어야 한다.

#pragma endregion map컨테이너의 키 값 문자열
}

/*
deque는 백터랑 비슷하나 앞쪽에 데이터를 삽입할 수 있는게 특징이다.
deque는 앞쪽에 삽입 시에 모든 원소를 재배치 해야하기때문에 백터보다 느리다
중간 삽입 또는 중간 삭제시 백터는 해당위치 뒤쪽만 재배치가 일어나지만
데크는 앞 뒤 모두 재배치가 일어나서 느리다.
보통 잘 안쓴다.
*/

