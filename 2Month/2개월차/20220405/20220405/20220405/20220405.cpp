// 20220405.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//vector<int> vecInt;
	//vector<float> vecFloat;

	////push_back  //뒤쪽에 원소를 추가해주는 함수
	////pop_back	// 뒤쪽의 원소를 제거해주는 함수	
	////push_front // 앞쪽에 원소를 추가해주는 함수
	////pop_front // 앞쪽의 원소를 제거해주는 함수

	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);

	////백터는 배열 기반이기 때문에 []인덱스(내부적으로 오버로딩 되어있음)연산자를 사용할 수 있다.
	////[]연산자를 토대로 임의 접근이 가능하다.

	//for (int i = 0; i < 3; ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}

	////size() == 컨테이너 원소의 개수를 반환하는함수(모든 컨테이너가 갖고있는 맴버 함수)

	//

	//vecInt.pop_back();

	//cout << vecInt.size() << endl;  // size_t = 언사인드인트이다. 갯수는 음수가 나올수 없기 때문
	//								// 내부적으로 size_t 는 언사인드인트로 typedef로 별명을 만들어준것

	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}


#pragma region 백터와 카파시티

	//vector<int> vecInt;

	// 컴파일러마다 규칙이 다른데 비쥬얼 스튜디오는 n + (n / 2) 정책을 사용하고 있다.
	// 카파시티를 둔 이유는 동적배열 기반의 백터의 메모리 재할당을 최소화하기 위한 수단으로 카파시티 정책을 사용하고 있다.

	//for (int i = 0; i < 10; ++i)
	//{
		//cout << "사이즈 : " << vecInt.size() << " 카파시티 : " << vecInt.capacity() << endl;
	//	vecInt.push_back(10);
	//}

	//vecInt.clear(); // 컨테이너 내의 모든 원소들을 제거하는 함수 모든 컨테이너들이 이 맴버함수를 포함하고있다.
	//cout << "사이즈 : " << vecInt.size() << " 카파시티 : " << vecInt.capacity() << endl;

	// 원소들을 제거해도 카파시티는 남아있다. 이미늘려놓은 메모리를 다시 줄일 필요가 없기 때문이다.

	//if (vecInt.empty())	// empty함수 = 컨테이너 내의 원소의 유무를 판단하는 함수 모든 컨테이너들이 이 맴버함수를 포함하고있다.
	//	cout << "vecInt 원소 없음" << endl;
	//else
	//	cout << "vecInt 원소 있음" << endl; 

	// pop_back 이든 clear든 둘다 원소만 삭제한다. 카파시티는 지울 수 없다.

	//vector<int> vecTemp;

	//vecTemp.push_back(100);
	//vecTemp.push_back(200);
	//vecTemp.push_back(300);

	//vecInt.swap(vecTemp); // 스왑함수 = 같은 타입의 컨테이너끼리 원소와 메모리 모두 교환하는 함수

	//cout << "사이즈 : " << vecInt.size() << " 카파시티 : " << vecInt.capacity() << endl;

	//cout << "사이즈 : " << vecTemp.size() << " 카파시티 : " << vecInt.capacity() << endl;

	// swap을 이용한 카파시티 삭제 방법
	//임시 객체 생성을 통한 교환
	//vector<int>().swap(vecInt); // 임시객체에 스왑의 값을 넣고 이 코드라인을 벗어나면 임시객체는 삭제된다.
	//cout << "사이즈 : " << vecInt.size() << " 카파시티 : " << vecInt.capacity() << endl;

#pragma endregion 백터와 카파시티


#pragma region 또다른 맴버 함수

	//vector<int> vecInt;

	//vecInt.push_back(10);
	//vecInt.push_back(20);
	//vecInt.push_back(30);
	//vecInt.push_back(40);

	//vecInt.front() = 100; // 맨 앞의 원소의 메모리 공간에 접근가능한 함수
	//vecInt.back() = 5000; // 맨 뒤의 원소의 메모리 공간에 접근가능한 함수
	////래퍼런스기때문에 원본값에 대입이 일어난다.
	//
	//vecInt[3] = 777;

	//for (size_t i = 0; i < vecInt.size(); ++i)
	//{
	//	cout << vecInt[i] << endl;
	//}



	//cout << vecInt.front() << endl;
	//cout << vecInt.back() << endl;

#pragma endregion 또다른 맴버 함수


#pragma region 반복자


	//end는 원소가 있을 때 성립한다. 원소가 없으면 begin과 end를 구분못해서 같다.	

	/*
	반복자 = 포인터와 비슷한 동작을 한다. 그러나 절대 포인터가 아님. 컨테이너 원소를 접근하고 값변경을 위한 목적의 객체
	*가 오버로딩 되어있기 때문에 사용할 때 포인터와 흡사하지만 포인터가 아니다.
	백터 데크 맵을 제외하면 이터레이터 없이 탐색할 수 없다.
	
	*/



	vector<int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);

	vector<int>::iterator iter = vecInt.begin();

	for (vector<int>::iterator iter = vecInt.begin(); iter != vecInt.end(); ++iter)
	{
		cout << *iter << endl;	
	}

	//cout << *iter << endl;  //begin = 주소가아닌 그 원소를 가르킨다. 메모리공간의 이터레이터 위치 
	//맨끝원소의 다음 위치 end = 반개구간 

	//begin = 맨 첫번 째 원소의 위치
	//end = 맨 끝 원소의 다음 위치
	//비긴 엔드로 for문안에서 비교할 때 != 논리비교로 조건을 건다.
	// 어떤 컨테이너는 < 이 연산자가 오버로딩이 안되어있을 수 있기때문

#pragma endregion 반복자

    return 0;
}

/*
선형적 구조는 앞과 뒤과 명확하고
비선형적 구조는 앞과 뒤 구분이 없다.
이진탐색트리 : 각 노드는 2개 이하의 자식 노드를 갖는 트리를 이진 트리라 한다.
이진탐색 트리는 임의 노드를 기준으로 좌측은 자신보다 작은 값, 우측은 자신보다 큰 값을 갖는 규칙이 있다.
이규칙을 통해 이진 탐색을 해나갈 수 있는 트리가 이진 탐색 트리가 되겟다.
연관 컨테이너에는 map, multimap, set, multiset 등이 있다.
전위 순회 : 뿌리를 먼저 방문
중위 순회 : 왼쪽 하위 트리를 방문 후 뿌리 방문
후위 순회 : 하위 트리 모두 방문 후 뿌리를 방문
층별 순회 : 뿌리부터 층별로 방문

Map 키와 벨류를 가진거를 페어라는 객체에 저장한다.
map의 원소들은 각 key와 value로 한 쌍을 이룬다.
각 원소들은 삽입 시에 key값에 따라 자동 정렬된다. 삽입 삭제가 불리하다. 원소를 삽입 삭제 할 때마다 자동정렬이 일어남
대신 원소들이 key값에 따라 정렬되고 있고 반복자를 통한 탐색 또한 가능하다.
노드 기반 컨테이너들 중 유일하게 key값으로 임의 접근(인덱스접근)이 가능하다.
리소스 탐색용으로 많이 쓰이며, 중복 key값은 허용하지 않는다.
map컨테이너는 내부적으로 []인덱스연산자가 오버로딩되어있다.
map컨테이너는 배열인것처럼 문법적표기가 가능한것이지 배열이 아니다. 노드기반의 트리구조이다.

비선형적 구조로 분포되어있는 리스트가 트리 구조이다.

데이터가 많으면 많을수록 트리의 탐색속도가 빠르다. 무조건 제일빠른건 아니다.
맵은 트리구조라서 키값을 기준으로 작으면 왼쪽 크면 오른쪽으로 이동해 절반을 제외해서 탐색시간이 빠르다.


MultiMap

Map과의 차이점
MultiMap은 []인덱스 연산자가 오버로딩되어있지않다.
중복키값을 가질 수 있다.


Set
map과 달리 원소 한 쌍이 아닌 하나의 key만 갖는다.
삽입 시 key값 기준으로 정렬이 일어난다.
중복 key값은 허용하지 않는다.
(set에 넣어서 자동정렬을 하기위해서 사용한다.)

MultiSet = 중복키값을 허용하는 Set


string 클래스 (컨테이너)
연속된 메모리 기반 컨테이너이며 vector와 비슷한 특징을 지닌다.
표준 시퀀스 컨테이너의 일종이긴 하지만 문자만을 저장하는 컨테이너여서 표준 컨테이너 요구사항을
충족시키지 못한다. 이런 컨테이너를 근사 컨테이너 almostcontainer라고한다.

STL의 특징
장점
효율성
일반화프로그래밍 재사용성 보장
하나의 알고리즘으로 복수의 컨테이너에 동일한 작업을 똑같은 방식으로 수행할수있다
이식성확보


단점
템플릿 기반으로 컴파일시 타입마다 함수와 클래스가 인스턴스화 되기때문에 코드가 비대해지는 문제가있다.
가독성이 떨어진다.

정리
우리가 앞으로 살펴볼 컨테이너는 vector와 list map 이다.
제일 많이 사용하는 컨테이너이기 때문이다.
STL은 선택이지 필수가 아니다.


vector
STL은 클래스 템플릿을 모아놓은것
맴버함수가 있다.


*/

백터를 이용한 성적표 프로그램을 작성하자
1. 입력 2. 전체 출력 3. 검색 출력 4. 삭제 구현하기

반환타입도 iterator  인자도 iterator
erase() = 특정 원소를 삭제가능한데 이터레이터를 통해 접근가능하다.
