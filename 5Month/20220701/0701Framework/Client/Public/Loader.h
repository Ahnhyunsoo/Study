#pragma once

#include "Client_Defines.h"
#include "Base.h"
/*
이 클래스는 다음레벨에 필요한 리소스,객체들을 생성해주고
쓰레드를 생성해서 생성한 쓰레드에선 로딩도중에 화면에 표현해줄 작업들을 한다.
쓰레드란? 또하나의 실행흐름이다.
막연하게 실행흐름이라하면 이해가 잘안될텐데 예를 들어보자.
프로그램이란 흐름이 존재하고 반드시 흐름에 따라서 진행되어야한다.
하지만 내가 a~z라는 흐름이 있는데 a라는 흐름을 진행하고있는데 f라는 흐름을 동시에 진행하고싶다면
또하나의 실행흐름인 쓰레드를 생성하고 a라는 흐름을 진행할 때 생성한 쓰레드에서 f라는 흐름을 실행하게하면 
두개를 동시에 진행하는 효과를 얻을 수 있다.
즉 Loader클래스에서 객체와 리소스들을 불러들이는 작업을 할 때는 화면이 랜더라는 작업을 동시에 할 수 없기때문에 멈춰있다.
하지만 이 때 쓰레드를 하나 생성해서 이 쓰레드에게 랜더작업을 실행하게하면 불러들이는작업과동시에 랜더작업까지 동시에 할 수 있다. 
*/

BEGIN(Client)

class CLoader final : public CBase
{
public:
	CLoader(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLoader() = default;

public:
	LEVEL Get_NextLevelID() const {
		return m_eNextLevelID;
	}

	const _tchar* Get_LoadingText() const { // 
		return m_szLoadingText;
	}

	_bool Get_Finished() const { //로딩이 끝났는지 체크해주는 불변수
		return m_isFinished;
	}

	CRITICAL_SECTION Get_CS() const {
		return m_CriticalSection;
	}

public:
	HRESULT Initialize(LEVEL eNextLevelID);
	HRESULT Loading_ForLogoLevel();
	HRESULT Loading_ForGamePlayLevel();

private:
	LPDIRECT3DDEVICE9	m_pGraphic_Device = nullptr;

private:
	HANDLE				m_hThread = 0;
	CRITICAL_SECTION	m_CriticalSection;
	LEVEL				m_eNextLevelID = LEVEL_END;

private:
	_tchar				m_szLoadingText[MAX_PATH] = TEXT("");
	_bool				m_isFinished = false;

public:
	static CLoader* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID);
	virtual void Free() override;
};

END