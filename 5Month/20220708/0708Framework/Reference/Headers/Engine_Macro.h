#pragma once

//네임스페이스 매크로 인자로 받은 네임스페이스를 네임스페이스로 지정해줌
#define BEGIN(NAMESPACE) namespace NAMESPACE {
#define END }

//DLL프로젝트는 export라는것이 정의되어있음 때문에 클라이언트면 Import 엔진이면 Export로 매크로가 작동함.
#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)

#else
#define ENGINE_DLL _declspec(dllimport)
#endif


//#define (매크로정의) 구문에서 \이란 아래코드와 연결해주는 기능 즉 이어서 작성한다는 뜻
#define MSG_BOX(message)	\
::MessageBox(nullptr, message, L"System Message", MB_OK)

//복사생성자와 대입연산을 막아주는 매크로 싱글톤이니 객체를 하나만 생성해야하기 때문에 복사생성, 대입연산을 못하게함
#define NO_COPY(ClassName)	\
ClassName(const ClassName&) = delete;	\
ClassName& operator=(const ClassName&) = delete;

//싱글톤 헤더에 사용하는 매크로 인자로 받은 객체로 함수를 생성해서 클래스를 싱글톤화 시켜줌
#define DECLARE_SINGLETON(ClassName)	\
	NO_COPY(ClassName)	\
public :	\
	static ClassName* Get_Instance();	\
	static unsigned long Destroy_Instance();	\
private:	\
	static ClassName* m_pInstance;

//싱글톤 cpp에 사용하는 매크로 인자로 받은 객체로 필요한 초기화 및 함수정의부를 구현해서 클래스를 싱글톤화 시켜줌
#define IMPLEMENT_SINGLETON(ClassName)					\
ClassName* ClassName::m_pInstance = nullptr;			\
ClassName* ClassName::Get_Instance()					\
{														\
	if (nullptr == m_pInstance)							\
		m_pInstance = new ClassName;					\
	return m_pInstance;									\
}														\
unsigned long  ClassName::Destroy_Instance()			\
{														\
	unsigned long dwRefCnt = 0;							\
	if(nullptr != m_pInstance)							\
	{													\
		dwRefCnt = m_pInstance->Release();				\
		if(0 == dwRefCnt)								\
			m_pInstance = nullptr;						\
	}													\
	return dwRefCnt;									\
}



