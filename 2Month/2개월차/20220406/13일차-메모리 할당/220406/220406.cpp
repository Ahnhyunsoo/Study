#include "stdafx.h"

// 함수 템플릿
template<typename T>
bool	 Less(T Left, T Right)
{
	return Left < Right;
}

template<typename T>
bool	 Greater(T Left, T Right)
{
	return Left > Right;
}

template<typename T>
bool	IsOddNum(T Number)
{
	if (0 != Number % 2)
		return true;

	return false;
}


void main(void)
{
	// 반복자의 종류

	// 1. 출력 반복자 2. 입력 반복자 3. 순방향 반복자 4. 양방향 반복자 5. 임의 접근 반복자

	/*vector<int>		vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	vector<int>::iterator		iter = vecInt.begin();

	iter += 3;		// 임의 접근 반복자이기 때문에 가능하다.

	// vecInt.insert(iter, 60000);	// 중간 삽입 함수
	// iter = vecInt.erase(iter);		// 삭제 함수

	cout << (*iter) << endl;*/

	/*for( iter = vecInt.begin(); iter != vecInt.end(); ++iter)
		cout << (*iter) << endl;*/


/*
	list<int>		ListInt;

	ListInt.push_back(10);
	ListInt.push_back(20);
	ListInt.push_back(30);
	ListInt.push_back(40);
	ListInt.push_back(50);

	list<int>::iterator		iter = ListInt.begin();

	iter += 3;		// 양방향 반복자이기 때문에 사용이 불가능하다.

	cout << (*iter) << endl;*/


#pragma region 메모리 확보를 위한 vector의 함수들

	/*vector<int>		vecTemp;

	for (size_t i = 0; i < 10; ++i)
	{
		cout << "Size : " << vecTemp.size() << "\tCapacity : " << vecTemp.capacity() << endl;
		vecTemp.push_back(10);		
	}*/
	
	/*vector<int>		vecInt(10);		// 생성 시점에 원소 값이 0으로 초기화된 상태로 사이즈와 카파시티를 미리 10개 만들어주는 문법
									// 원소 10개 이상이 발생하는 순간 다시 카파시티 정책에 의해 재할당이 시작된다.
	
	cout << "Size : " << vecInt.size() << "\tCapacity : " << vecInt.capacity() << endl;
	
	//vecInt.push_back(10);
	
	vecInt.resize(20);		// 원소의 개수를 다시 조정하는 함수, 단, 이미 확보된 메모리 공간은 줄어들지 않는다.
	cout << "Size : " << vecInt.size() << "\tCapacity : " << vecInt.capacity() << endl;*/


	/*vector<int>		vecInt;
	vecInt.reserve(10);	// 원소 개수 변동 없이 오로지 메모리 공간을 미리 확보하는 함수
	cout << "Size : " << vecInt.size() << "\tCapacity : " << vecInt.capacity() << endl;
*/



#pragma endregion 메모리 확보를 위한 vector의 함수들

#pragma region 알고리즘과 조건자

	// 조건자 : bool 타입을 반환하는 함수 또는 함수 객체로 stl 알고리즘을 수행하기 위한 조건을 제공하는 기능을 의미한다.

	//int	iArray[5] = { 3, 4, 1 , 5, 2 };

	/*sort(iArray, iArray + 5, Less<int>);

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << endl;*/

	// count_if : 컨테이너 원소를 순회하면서 조건자의 반환 결과가 true일때의 개수를 반환하는 함수 템플릿
	//int	iCount = count_if(iArray, iArray + 5, IsOddNum<int>);

	//cout << iCount << endl;

	//find("jusin");

	//find_if();

#pragma endregion 알고리즘과 조건자
}