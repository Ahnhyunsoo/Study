#pragma once

#include "Client_Defines.h"
#include "GameObject.h"

BEGIN(Engine)
class CRenderer;
END

BEGIN(Client)
//��Ŭ�������� �Լ����� Engine�� GameObjectŬ������ ��� ��ӹ޴´�.
//GameObjectŬ������ ����� �ѹ� ������°� ��õ
class CBackGround final : public CGameObject
{
public:
	typedef struct tagBackGroundDesc //�纻��ü�� ������ ����ü�� ����
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