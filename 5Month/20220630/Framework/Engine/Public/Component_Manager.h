#pragma once
#include "Renderer.h" 

BEGIN(Engine)

class CComponent_Manager final : public CBase
{
	DECLARE_SINGLETON(CComponent_Manager)
private:
	CComponent_Manager();
	virtual ~CComponent_Manager() = default;

public:
	HRESULT Reserve_Container(_uint iNumLevels); // �������̳ʸ� �����迭�� �Ҵ� ���ִ� �Լ�
	HRESULT Add_Prototype(_uint iLevelIndex, const _tchar* pPrototypeTag, class CComponent* pPrototype); // �ʿ� ������ü�߰�
	class CComponent* Clone_Component(_uint iLevelIndex, const _tchar* pPrototypeTag, void* pArg);//������Ʈ ����

private:
	_uint m_iNumLevels;

	map<const _tchar*, class CComponent*>* m_pPrototypes = nullptr;
	typedef map<const _tchar*, class CComponent*> PROTOTYPES;

private:
	class CComponent* Find_Component(_uint iLevelIndex, const _tchar* pPrototypeTag); // ������Ʈ �˻��Լ�

public:
	virtual void Free() override;
};

END