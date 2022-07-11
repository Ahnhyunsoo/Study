#pragma once
namespace Engine
{
	//탬플릿 모르면 C++복습하기
	//탬플릿 함수를 만든다. 
	template<typename T>
	void Safe_Delete(T& Temp)
	{
		if (Temp)
		{
			delete Temp; //인자로 받은 포인터가 가르키는 객체를 삭제해줌
			Temp = nullptr; //댕글리 방지를 위해서 인자로 받은 포인터를 널포인터로 초기화해줌
		}
	}
	//위와 동일 배열을 삭제해줌
	template<typename T>
	void Safe_Delete_Array(T& Temp)
	{
		if (Temp)
		{
			delete[] Temp;
			Temp = nullptr;
		}
	}
	//래퍼런스 카운트를 증가시키기위한 탬플릿함수
	template<typename T>
	unsigned long Safe_AddRef(T& Temp)
	{
		unsigned long dwRefCnt = 0; //인자로받은 객체의 AddRef리턴값을 저장하기위해 변수를 선언함.
		if (Temp != nullptr) //만약 인자로받은 포인터가 nullptr가 아니라면
		{
			dwRefCnt = Temp->AddRef(); //인자로받은 객체의 AddRef함수를 실행하고 그 결과값을 선언해둔 dwRefCnt변수에 저장
		}
		return dwRefCnt; //연산이 끝난 dwRefCnt를 리턴해줌
	}
	//래퍼런스 카운트를 감소시키기 위한 탬플릿함수
	template<typename T>
	unsigned long Safe_Release(T& Temp)
	{
		unsigned long dwRefCnt = 0; //AddRef와 같은 흐름
		if (Temp != nullptr)
		{
			dwRefCnt = Temp->Release(); //인자로받은 객체의 Release를 호출한 후 변수에 저장
			Temp = nullptr; //nullptr을 해주는 이유는 Release가 호출된 시점이 
			//호출한 객체를 삭제하는 시점이기 때문이다.
			//즉 더이상 호출한 객체에서 참조를 하지 않기 때문에 댕글리 방지를 위해 nullptr로 초기화해준다.
		}
		return dwRefCnt;	//저장한 래퍼런스카운트를 리턴
	}
}