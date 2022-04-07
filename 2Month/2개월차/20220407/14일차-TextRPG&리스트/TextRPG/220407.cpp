#include "stdafx.h"

void main(void)
{

	// list 컨테이너
	
	// 선형적인 구조를 갖고 있음
	// 노드 기반의 컨테이너 구조를 갖고 있음

	// vector와 차이점

	// 배열 기반(임의 접근이 가능한 반복자 사용) vs 노드 기반(양방향 가능한 반복자 사용)
	// 탐색의 이점 vs 중간 삽입 삭제의 이점
	
	// 중간 삽입 삭제 시, 벡터는 배열의 특성상 메모리 재할당 또는 인덱스 재배치가 발생하여 느림
	// 리스트의 경우 노드의 포인터 링크가 교체하면 되기 때문에 비용적인 측면이 적고 동작 속도도 빠르다.

#pragma region 리스트 기본 사용법
	/*list<int>		ListInt;

	ListInt.push_back(10);
	ListInt.push_back(20);
	ListInt.push_back(30);

	/ *for (size_t i = 0; i < ListInt.size(); ++i)
	{
	cout << ListInt[i] << endl;		// 배열 기반 컨테이너만 사용가능한 문법
	}* /

	list<int>::iterator iter = ListInt.begin();

	// iter += 2;		// 임의 접근 방식을 list 컨테이너는 사용할 수 없다.
	++iter;
	++iter;

	cout << (*iter) << endl;*/

	/*for( iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	{
	cout << (*iter) << endl;
	}*/

	/*ListInt.push_front(10);
	ListInt.push_front(20);
	ListInt.push_front(30);

	ListInt.pop_front();

	for (list<int>::iterator iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	{
	cout << (*iter) << endl;
	}*/

	// 리스트 또한 size, clear, empty, swap, erase 멤버 함수 모두 지니고 있다.
#pragma endregion 리스트 기본 사용법

#pragma region 중간 삽입의 예


	/*list<int>		ListInt;

	ListInt.push_back(10);
	ListInt.push_back(20);
	ListInt.push_back(30);
	ListInt.push_back(40);
	ListInt.push_back(50);

	list<int>::iterator	iter = ListInt.begin();

	++iter;
	++iter;
	++iter;

	//ListInt.insert(iter, 600);

	iter = ListInt.erase(iter);
	cout << (*iter) << endl;
*/

	/*for (iter = ListInt.begin(); iter != ListInt.end(); ++iter)
		cout << (*iter) << endl;*/



#pragma endregion 중간 삽입의 예

#pragma region 리스트와 정렬


	/*vector<int>		vecInt;

	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);

	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;

	cout << "=============after============" << endl;
	
	sort(vecInt.begin(), vecInt.end());
	
	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;*/

	/*list<int>		listInt;

	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);

	for (list<int>::iterator iter = listInt.begin();
		iter != listInt.end(); ++iter)
		cout << (*iter) << endl;

	cout << "=============after============" << endl;

	// sort(listInt.begin(), listInt.end()); // 퀵 정렬로 설계, 배열 기반으로 생성

	listInt.sort(greater<int>());	// 퀵정렬 기반, 노드기반으로 설계된 멤버함수

	for (list<int>::iterator iter = listInt.begin();
		iter != listInt.end(); ++iter)
		cout << (*iter) << endl;*/


list<int>		ListInt;

ListInt.push_back(10);
ListInt.push_back(20);
ListInt.push_back(30);
ListInt.push_back(40);
ListInt.push_back(50);


for (list<int>::iterator iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	cout << (*iter) << endl;

cout << "---------------after==================" << endl;


ListInt.reverse();

for (list<int>::iterator iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	cout << (*iter) << endl;

#pragma endregion 리스트와 정렬

}