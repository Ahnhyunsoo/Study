#pragma once
#include "Client_Defines.h"
#include "Level.h"

BEGIN(Client)

class CLevel_Loading final : public CLevel
{
private:
	CLevel_Loading(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLevel_Loading() = default;

public:
	virtual HRESULT Initialize(LEVEL eNextLevel);
	virtual void Tick(_float fDeltaTime) override;
	virtual HRESULT Render() override;

private:
	LEVEL m_eNextLevel = LEVEL_END; //레벨을 저장할 이넘 변수
	class CLoader* m_pLoader = nullptr; //로더의 주소를 기록할 포인터변수

public:
	static CLevel_Loading* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID);
	virtual void Free() override;
};

END
