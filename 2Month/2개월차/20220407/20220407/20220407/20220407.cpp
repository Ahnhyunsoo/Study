// 20220407.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
/*
	List 컨테이너
	선형적인 구조이다
	배열기반이 아닌 노드기반 구조이다.

	vector와 차이점
	배열기반(임의접근이 가능한 반복자 사용) vs 노드 기반 (양방향 가능한 반복자 사용)
	중간 삽입 삭제 시 백터는 배열의 특성상 메모리 재할당 또는 인덱스 재배치가 발생한다.
	리스트의 경우 노드의 포인터 링크만 교체하면 되기 때문에 비용적인 측면이 적고 동작 속도도 빠르다.
	탐색의 이점 vs 중간 삽입삭제의 이점 
	배열은 탐색이 빠르고 노드는 삽입 삭제가 빠르다 라는 특징

*/

	list<int> ListInt;

	ListInt.push_front(10);
	ListInt.push_front(20);
	ListInt.push_front(30);
	

	for (list<int>::iterator iter = ListInt.begin(); iter != ListInt.end();)
	{
		cout << (*iter) << endl;
		++iter;
	}
    return 0;

	//리스트 또한 size clear empty swap erase 맴버 함수 모두 지니고 있다.

	//만들어놓은 성적표프로그램이랑 텍스트 RPG 리스트로 바꿔보기 

	//리스트는 정렬 맴버함수가 있다. size() 디폴트는 오름차순 필요할경우 펑셔너리헤더 추가해서 조건자 삽입
	//reverse() = 원소들을 뒤집어라

}


