#pragma once
//사실 이 클래스는 Base를 상속받고 Free를 호출하는것만 수정됐을뿐 유쌤 수업 때 배운 코드와 동일하다.
//코드를 외울 필요는 없지만 개념과 흐름은 꼭 알고가야함으로 
//유쌤이 작성한 클래스를 꼭한번 보자. 거기엔 코드마다 주석이 가득가득함.
#include "Base.h"

BEGIN(Engine) 

class CGraphic_Device final : public CBase //final = 더이상 상속을 내려주지 않음을 지정해주는 키워드
{
	DECLARE_SINGLETON(CGraphic_Device) //싱글톤화 시켜주는 매크로 Engine_Macro에 정의되어있음

public:

private:
	CGraphic_Device();
	virtual ~CGraphic_Device() = default;
	// com 객체 : 언어와의 통신 규약을 갖고 하드웨어를 통제하여 각종 기능을 제공하는 객체

public:
	LPDIRECT3DDEVICE9			Get_Device(void) { return m_pDevice; }
	LPD3DXSPRITE				Get_Sprite(void) { return m_pSprite; }
	LPD3DXFONT					Get_Font(void) { return m_pFont; }
public:
	HRESULT		InitDevice(HWND hWnd, _uint iWinSizeX, _uint iWinSizeY, GRAPHICDESC::WINMODE eWinMode, LPDIRECT3DDEVICE9* ppOut);
	//HRESULT = 결과값에 따라서 재정의된 값을 리턴해줌 ex) S_OK, E_FAIL 등등 그냥 성공했는지 실패했는지 리턴해준다고 보면된다.
	//HRESULT에 대한 자세한 정보를 보고싶으면 
	//https://docs.microsoft.com/ko-kr/windows-hardware/drivers/debugger/hresult-values 
	//이 링크참고
	void		SetParameters(D3DPRESENT_PARAMETERS& d3dpp, HWND hWnd, _uint iWinSizeX, _uint iWinSizeY, GRAPHICDESC::WINMODE eWinMode);

	void		Render_Begin(void);
	void		Render_End(HWND hWnd = NULL);

private:
	LPDIRECT3D9				m_p3D;
	LPDIRECT3DDEVICE9		m_pDevice;

	// dx 상에서 2d 이미지를 출력해주는 com객체
	LPD3DXSPRITE			m_pSprite;
	LPD3DXFONT				m_pFont;

public:
	virtual void Free() override;
};

END