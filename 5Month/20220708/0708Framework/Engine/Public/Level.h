#pragma once
//이 클래스는 클라이언트에서 선언한 모든 레벨들이 반드시 상속받아야하는 부모클래스다.
//이 클래스를 상속받는다는건 즉 Base도 상속받는의미이기 때문에 클라이언트의 레벨들은 이 Level클래스만 상속받으면 된다.
#include "Base.h"

BEGIN(Engine)
/*CBase에서 설명했지만 중요하니 한번더 설명함
ENGINE_DLL은 라이브러리화 시키는 매크로이다. Engine_Macro에 정의되어있음 
어떤 클래스를 매크로화 시킬지 판단할 수 있어야한다.
예시로 CBase클래스는 ENGINE_DLL을 통해 라이브러리화 시켰지만
Graphic_Device는 라이브러리화 시키지 않았다.
그 이유는 클라이언트에서 Graphic_Device의 초기화부분을 사용할 필요가 있을가? 당연히 없다.
반면에 클라이언트에서 CBase의 함수들을 모두 사용하고 꼭 CBase를 상속받아야하기 때문에 라이브러리화는 필수다.
즉 쓰지도 않을 Device초기화함수나 다른 함수들을 라이브러리화 시키면 라이브러리가 너무 비대해지기 때문에
나중에 작성할 GameInstance클래스에 꼭 필요한 함수들만 호출하는식으로 구현한 후 이 GameInstance를 라이브러리화 시킨다.
GameInstance에서 한번더 설명할테니 일단 이정도만 알고가자.
*/
class ENGINE_DLL CLevel abstract : public CBase //CBase를 상속받는 추상클래스
{
protected:
	CLevel(LPDIRECT3DDEVICE9 pGraphic_Device); //생성할 때 장치를 인자로 넣어줌
	virtual ~CLevel() = default;

public:
	virtual HRESULT Initialize(); //초기화 함수
	virtual void Tick(_float fTimeDelta); //_float 모르면 Engine_Struct 확인하고 다음부터 _붙은 자료형 헷갈리지말기
											//API때 Update와 유사한 함수이다. 객체의 상태를 갱신해주는 함수
											//인자로 받는 fTimeDelta는 시간값이다. 이 시간값을 통해 갱신주기를 제어할 수 있다.
	virtual HRESULT Render();	//그냥 랜더함수 API때와 다른점은 핸들이 아닌 디바이스로 랜더하기때문에 인자가 없다.

protected:
	LPDIRECT3DDEVICE9 m_pGraphic_Device;

public:
	virtual void Free() override; //override = 부모의 가상함수를 재정의 했다고 알려주는 키워드 
								//쓰나 안쓰나 기능은 똑같지만 협업을 생각한다면 쓰는 버릇을 들이자.
};

END