#include "..\Public\Level.h"



CLevel::CLevel(LPDIRECT3DDEVICE9 pGraphic_Device)
	:m_pGraphic_Device(pGraphic_Device)
{	
	Safe_AddRef(m_pGraphic_Device); //Graphic_Device클래스를 참조하고 있음으로 래퍼런스카운트를 증가시켜준다.
	//여기서 참조란? 
	//포인터 변수를 통해 다른 객체에 접근하는 행위를 참조라고 한다.
	//즉 포인터 변수에 다른 객체주소를 저장하면 이건 참조하는것이다. 때문에 참조하면 래퍼런스 카운트를 증가시켜야한다.
	//싱글톤의 Get_Instance를 통한 접근은 객체주소를 저장하는것이 아닌 사용만 하는것이기 때문에 
	//따로 래퍼런스 카운트를 증가시키지 않아도 된다.
	//결론적으로 참조란 다른객체의 주소를 "저장"시키는 행위라는걸 말하고 싶었다...
}

HRESULT CLevel::Initialize()
{
	return S_OK;
}

void CLevel::Tick(_float fTimeDelta)
{
}

HRESULT CLevel::Render()
{
	return S_OK;
}

void CLevel::Free()
{
	Safe_Release(m_pGraphic_Device); //참조했던 객체의 래퍼런스카운트를 감소시켜준다.
}
	
