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
	HRESULT Reserve_Container(_uint iNumLevels); // 맵컨테이너를 동적배열로 할당 해주는 함수
	HRESULT Add_Prototype(_uint iLevelIndex, const _tchar* pPrototypeTag, class CComponent* pPrototype); // 맵에 원형객체추가
	class CComponent* Clone_Component(_uint iLevelIndex, const _tchar* pPrototypeTag, void* pArg);//컴포넌트 복제

private:
	_uint m_iNumLevels;

	map<const _tchar*, class CComponent*>* m_pPrototypes = nullptr;
	typedef map<const _tchar*, class CComponent*> PROTOTYPES;

private:
	class CComponent* Find_Component(_uint iLevelIndex, const _tchar* pPrototypeTag); // 컴포넌트 검색함수

public:
	virtual void Free() override;
};

END