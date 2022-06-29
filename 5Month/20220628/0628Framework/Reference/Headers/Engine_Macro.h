#pragma once
#define BEGIN(NAMESPACE) namespace NAMESPACE{
#define END }
//
#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)

#else
#define ENGINE_DLL _declspec(dllimport)
#endif
//메세지박스 매크로
#define MSG_BOX(message)									\
::MessageBox(nullptr, message, L"System Message :", MB_OK)
//😊😊😊😊😊😊😊

#define NO_COPY(ClassName)									\
ClassName(const ClassName&) = delete;						\
ClassName& operator=(const ClassName&) = delete;

#define DECLARE_SINGLETON(ClassName)						\
		NO_COPY(ClassName)									\
public:														\
	static ClassName* Get_Instance();						\
	static unsigned long Destroy_Instance();				\
private:													\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)						\
ClassName* ClassName::m_pInstance = nullptr;				\
ClassName* ClassName::Get_Instance()						\
{															\
	if(m_pInstance == nullptr)								\
		m_pInstance = new ClassName;						\
		return m_pInstance;									\
}															\
unsigned long ClassName::Destroy_Instance()					\
{															\
	unsigned long dwRefCnt = 0;								\
	if(nullptr != m_pInstance)								\
	{														\
		dwRefCnt = m_pInstance->Release();					\
		if(0 == dwRefCnt)									\
			m_pInstance = nullptr;							\
	}														\
	return dwRefCnt;										\
}