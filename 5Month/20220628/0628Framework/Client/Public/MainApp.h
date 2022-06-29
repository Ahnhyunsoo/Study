#pragma once
#include "Client_Defines.h"
#include "Base.h"

BEGIN(Engine)
class CGameInstance;
END

BEGIN(Client)

class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Initialize(); //초기화작업
	void Tick(_float fTimeDelta); // API때 업데이트와 유사하다. 인자로받은 델타타임에 따라서 Update를 해준다.
	HRESULT Render();  //랜더함수 디바이스를 통해 랜더링한다.

private:
	CGameInstance* m_pGameInstance = nullptr; //게임인스턴스 클래스의 객체포인터를 저장할 포인터변수

private:
	LPDIRECT3DDEVICE9		m_pGraphic_Device = nullptr; //디바이스객체를 저장할 변수 LPDIRECT3DDEVICE9은 이중포인터이다.

private:
	HRESULT Open_Level(LEVEL eLevelID); //레벨 enum값을 인자로 받아서 LevelManager의 Open_Level함수를 실행시켜주기위한 함수

public:
	static CMainApp* Create(); // Create함수 API때와는 다르게 new로 객체를 생성하지않고 이 전역함수인 Create를 이용해 생성한다.
	virtual void Free(); //프리함수 부모클래스인 Base클래스에서 순수가상함수이기때문에 반드시 정의부를 구현해줘야한다.
};

END
