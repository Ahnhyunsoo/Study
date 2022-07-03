#pragma once

#include "Client_Defines.h"
#include "Base.h"

//GameInstance�� Engine�ȿ� �����Ǿ��ֱ⶧���� ���ӽ����̽��� Engine���� �����������.
BEGIN(Engine)
class CRenderer;
class CGameInstance; //���漱��
END

//GameInstance�� ���漱���������� �ٽ� Client�� namespace�� �������ش�.
BEGIN(Client)

class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Initialize();
	void Tick(_float fTimeDelta);
	HRESULT Render();

private:
	CGameInstance*				m_pGameInstance = nullptr;
	CRenderer*					m_pRenderer = nullptr;

private:
	LPDIRECT3DDEVICE9			m_pGraphic_Device = nullptr;

private:
	HRESULT Open_Level(LEVEL eLevelID);

private:  /* For.Static */
	HRESULT Ready_Prototype_Component();
	HRESULT Ready_Prototype_GameObject();


public:
	static CMainApp* Create();
	virtual void Free();
};


END