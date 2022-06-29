#pragma once
#include "Client_Defines.h"
#include "Base.h"

BEGIN(Client)

class CLoader final : public CBase
{
private:
	CLoader(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLoader() = default;

public:
	LEVEL Get_NextLevelID() const {
		return m_eNextLevelID;
	}

	const _tchar* Get_LoadingText() const {
		return m_szLoadingText;
	}

	_bool Get_Finished() const {
		return m_isFinished;
	}

	CRITICAL_SECTION Get_CS() const {
		return m_CriticalSection;
	}

public:
	HRESULT Initialize(LEVEL eNextLevelID);
	HRESULT LoadingForLogoLevel();
	HRESULT LoadingForGamePlayLevel();

private:
	LPDIRECT3DDEVICE9 m_pGraphic_Device = nullptr;

private:
	HANDLE m_hThread = 0;
	CRITICAL_SECTION m_CriticalSection;
	LEVEL m_eNextLevelID = LEVEL_END;

private:
	_tchar m_szLoadingText[MAX_PATH] = TEXT("");
	_bool m_isFinished = false;

public:
	static CLoader* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID); //로더를 생성할 때 디바이스와 변경할 레벨을 인자로 보내준다.
	virtual void Free() override;

};

END