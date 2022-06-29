#pragma once
namespace Engine
{
	template<typename T> //템플릿 함수
	void Safe_Delete(T& Temp) // 객체를 삭제해주는 함수 객체삭제후 널포인터로 채워준다.(댕글리방지)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}

	template<typename T>
	void Safe_Delete_Array(T& Temp) // 배열객체를 삭제해주는 템플릿함수
	{
		if (Temp)
		{
			delete[] Temp;
			Temp = nullptr;
		}
	}

	template<typename T> 
	unsigned long Safe_AddRef(T& Temp) // 래퍼런스 카운터를 올려주는 템플릿함수
	{
		unsigned long dwRefCnt = 0;
		if (Temp != nullptr) // 객체가 nullptr이 아니라면
		{
			dwRefCnt = Temp->AddRef(); // 해당객체의 AddRef함수를 실행하고 나온 리턴값을 dwRefCnt에 저장
		}
		return dwRefCnt;		// 그리고 리턴해준다.	
	}

	template<typename T>
	unsigned long Safe_Release(T& Temp)
	{
		unsigned long dwRefCnt = 0;
		if (Temp != nullptr)
		{
			dwRefCnt = Temp->Release();
			Temp = nullptr;
		}

			return dwRefCnt;
		
	}
}