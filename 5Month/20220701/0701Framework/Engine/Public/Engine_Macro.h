#pragma once

//���ӽ����̽� ��ũ�� ���ڷ� ���� ���ӽ����̽��� ���ӽ����̽��� ��������
#define BEGIN(NAMESPACE) namespace NAMESPACE {
#define END }

//DLL������Ʈ�� export��°��� ���ǵǾ����� ������ Ŭ���̾�Ʈ�� Import �����̸� Export�� ��ũ�ΰ� �۵���.
#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)

#else
#define ENGINE_DLL _declspec(dllimport)
#endif


//#define (��ũ������) �������� \�̶� �Ʒ��ڵ�� �������ִ� ��� �� �̾ �ۼ��Ѵٴ� ��
#define MSG_BOX(message)	\
::MessageBox(nullptr, message, L"System Message", MB_OK)

//��������ڿ� ���Կ����� �����ִ� ��ũ�� �̱����̴� ��ü�� �ϳ��� �����ؾ��ϱ� ������ �������, ���Կ����� ���ϰ���
#define NO_COPY(ClassName)	\
ClassName(const ClassName&) = delete;	\
ClassName& operator=(const ClassName&) = delete;

//�̱��� ����� ����ϴ� ��ũ�� ���ڷ� ���� ��ü�� �Լ��� �����ؼ� Ŭ������ �̱���ȭ ������
#define DECLARE_SINGLETON(ClassName)	\
	NO_COPY(ClassName)	\
public :	\
	static ClassName* Get_Instance();	\
	static unsigned long Destroy_Instance();	\
private:	\
	static ClassName* m_pInstance;

//�̱��� cpp�� ����ϴ� ��ũ�� ���ڷ� ���� ��ü�� �ʿ��� �ʱ�ȭ �� �Լ����Ǻθ� �����ؼ� Ŭ������ �̱���ȭ ������
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



