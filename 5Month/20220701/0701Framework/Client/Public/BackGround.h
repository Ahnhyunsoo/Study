#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CRenderer;
END

BEGIN(Client)
//이클래스들의 함수들은 Engine의 GameObject클래스를 모두 상속받는다.
//GameObject클래스의 헤더를 한번 보고오는걸 추천
class CBackGround final : public CGameObject
{
public:
	typedef struct tagBackGroundDesc //사본객체에 적용할 구조체를 선언
	{
		_uint		iSizeX;
		_uint		iSizeY;
	}BACKDESC;
private:
	CBackGround(LPDIRECT3DDEVICE9 pGraphic_Device);
	CBackGround(const CBackGround& rhs);
	virtual ~CBackGround() = default;

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg) override;
	virtual void Tick(_float fTimeDelta) override;
	virtual void LateTick(_float fTimeDelta) override;
	virtual HRESULT Render() override;

private:
	BACKDESC				m_BackDesc;

private:
	CRenderer* m_pRendererCom;

public:
	static CBackGround* Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg);
	virtual void Free() override;
};

END