#include "stdafx.h"
#include "..\Public\BackGround.h"

CBackGround::CBackGround(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CGameObject(pGraphic_Device)
{
}

CBackGround::CBackGround(const CBackGround & rhs)
	: CGameObject(rhs)
{
}

HRESULT CBackGround::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CBackGround::Initialize(void * pArg)
{
	if (nullptr != pArg)
	{
		// memcpy(&m_BackDesc, pArg, sizeof(BACKDESC));
		m_BackDesc = *(BACKDESC*)pArg; //위에 코드나 이코드나 똑같은것이다.
		//인자로 받아온 pArg를 m_BackDesc에 저장함 형변환을 해준 이유는 pArg가 void포인터 이기때문이다.
		//void포인터는 어떤 자료형이든 저장할 수 있지만 사용할 때 형변환을 해줘야한다.
		//자세한건 구글링
	}

	return S_OK;
}

void CBackGround::Tick(_float fTimeDelta)
{
	
}

void CBackGround::LateTick(_float fTimeDelta)
{

}

HRESULT CBackGround::Render()
{
	return S_OK;
}

CBackGround * CBackGround::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CBackGround*		pInstance = new CBackGround(pGraphic_Device);
	//객체 생성후 원형객체를 초기화해서 리턴해준다. 지금 쌤코드에선 작성을 안해서 실패할리가 없지만 예외처리를 해준다.
	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed To Created : CBackGround"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject * CBackGround::Clone(void* pArg)
{
	//사본 객체를 생성해주는 함수
	CBackGround*		pInstance = new CBackGround(*this);

	if (FAILED(pInstance->Initialize(pArg)))
	{
		MSG_BOX(TEXT("Failed To Created : CBackGround"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CBackGround::Free()
{
	__super::Free();
}

