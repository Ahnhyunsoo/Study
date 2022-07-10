#pragma once

namespace Engine
{
	//함수객체들을 구현한다. 함수객체는 임시객체를 생성해서 객체를 함수처럼 사용하는문법 중요하니 모르면 C++복습하기
	class CTag_Finder //
	{
	private:
		const wchar_t* m_pStr;//문자열을 저장하는변수

	public:
		CTag_Finder(const wchar_t* pStr)//생성자인자로 받은 문자열을 변수 m_pStr에 저장
			: m_pStr(pStr)
		{

		}

	public:
		template<typename T>
		bool operator()(T& Pair)//연산자 오버로딩 ()을 오버로딩함 
		{	//strcmp는 같으면 false를반환 다르면 true를 리턴해줌 (원래 내부적으로 약간 다르게 동작한다. 궁금하면 구글링)
			if (!lstrcmp(m_pStr, Pair.first)) //객체(Pair)를 호출했을 때 임시객체 생성했을 때 인자로 넣어준 태그와
				return true;	//()인자로 들어온 pair의 first를 비교해서 같으면 리턴해줌

			return false;
		}
	};
}