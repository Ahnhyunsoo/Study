#pragma once
#include "Base.h"
/*
클라이언트의 모든 Object들이 상속받는 부모클래스
*/
BEGIN(Engine)

class ENGINE_DLL CGameObject abstract : public CBase
{
protected:
	CGameObject(LPDIRECT3DDEVICE9 pGraphic_Device); //장치를 저장하는 생성자
	CGameObject(const CGameObject& rhs); //사본객체 생성을 위한 복사 생성자
	virtual ~CGameObject() = default;

public:
	virtual HRESULT Initialize_Prototype(); //원형객체의 초기화를 해주는함수
	virtual HRESULT Initialize(void* pArg); // 사본객체의 초기화를 해주는함수
	virtual void Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

protected:
	LPDIRECT3DDEVICE9 m_pGraphic_Device;

public:
	virtual CGameObject* Clone(void* pArg) = 0; //원형객체를 인자로 받아 복사해주는 함수
	virtual void Free() override;
};

END