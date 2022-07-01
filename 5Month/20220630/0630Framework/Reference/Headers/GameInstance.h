#pragma once
#include "Graphic_Device.h"
#include "Level_Manager.h"
#include "Object_Manager.h"

/* 클라이언트로 보여주기위한 가장 대표적인 클래스이다.  */
/* 각종 매니져클래스들의 주요함수를 클라로 보여준다.  */
/* 엔진초기화. */
/* 엔진정리. */

BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)

private:
	CGameInstance();
	virtual ~CGameInstance() = default;

public:
	//엔진을 초기화해주는 함수 1인자 : 레벨의 갯수, 2인자 : Engine_Struct에서 선언한 구조체, 3인자 : Device를 저장할 포인터
	//IDirect3DDevice9** = LPDIRECT3DDEVICE9* IDirect3DDevice9*은 내부에서 LPDIRECT3DDEVICE9으로 재정의되어있음
	HRESULT Initialize_Engine(_uint iNumLevel, const GRAPHICDESC& GraphicDesc, IDirect3DDevice9** pOut);
	void Tick_Engine(_float fTimeDelta);
	void Clear(_uint iLevelIndex);

public: 
	//Graphic_Device에 있는 함수를 호출하는 역할을함
	//이렇게 하면 Graphic_Device를 라이브러리화 시키지않고 이 GameInstance만 라이브러리화 시키면됨. 다른클래스도 마찬가지
	//결과적으로 라이브러리를 가벼워지고 클라이언트에 꼭필요한 기능들만 이 GameInstance로 인해
	//사용할 수 있게됨 즉 GameInstance내의 함수들은 클라에서 이용하는 함수들을 호출해주는 연결다리 역할을 한다.
	void Render_Begin(void);
	void Render_End(HWND hWnd = 0);

public: 
	//Level_Manager에 있는 함수들을 호출하는 역할을함
	HRESULT Open_Level(_uint iLevelIndex, class CLevel* pNewLevel);
	HRESULT Render_Level();

public:
	//Object_Manager에 있는 함수들을 호출하는 역할을함
	//함수 인자들이나 내부 동작들은 Object_Manager에 설명했으니 혹시 모르겠으면 한번더 보세요
	HRESULT Add_Prototype(const _tchar* pPrototypeTag, class CGameObject* pPrototype);
	HRESULT Add_GameObjectToLayer(const _tchar* pPrototypeTag, _uint iLevelIndex, const _tchar* pLayerTag, void* pArg = nullptr);

private:
	//클래스내에 접근해서 함수를 호출해야하기 때문에 객체를 저장할 포인터변수를 선언함.
	CGraphic_Device*				m_pGraphic_Device;
	CLevel_Manager*					m_pLevel_Manager;
	CObject_Manager*				m_pObject_Manager;

public:
	static void Release_Engine(); //매우 중요함 cpp에서 설명
	virtual void Free() override;
};

END