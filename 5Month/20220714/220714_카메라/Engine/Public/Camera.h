#pragma once

/* 클라에서 정의할 카메라들의 부모. */
/* 모든 카메라가 가져야할 기본적인 기능을 보유한다. */
#include "GameObject.h"
#include "Transform.h"

BEGIN(Engine)

class ENGINE_DLL CCamera abstract : public CGameObject //게임오브젝트를 상속받는 추상클래스
{
public:
	typedef struct tagCameraDesc //카메라가 가져야할 정보들을 저장하는 구조체
	{
		_float3		vEye, vAt; //vEye = 위치, vAt = 바라보는점 
		_float		fFovy, fAspect, fNear, fFar; //fFovy = 카메라각도, fAspect = 에스팩트, 니어 = z축최소범위, far = z축최대범위

		CTransform::TRANSFORMDESC		TransformDesc; //인자로 전달하기 위해 트랜스폼의 구조체를 저장해놓는다.
	}CAMERADESC;

protected:
	CCamera(LPDIRECT3DDEVICE9 pGraphic_Device);//원형 생성 시 장치를 저장한다.
	CCamera(const CCamera& rhs, CTransform::TRANSFORMDESC* pArg); 
	// 1인자 = 복사할 원형 
	// 2인자 = 복사생성자에서 Transform컴포넌트를 복사해서 변수에 대입해주는데 복사할 때 필요한 트랜스폼 구조체
	virtual ~CCamera() = default;

public:
	virtual HRESULT Initialize_Prototype(); //원형객체 초기화함수
	virtual HRESULT Initialize(void* pArg); //사본객체 초기화함수
	virtual void Tick(_float fTimeDelta); 
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

protected:
	class CTransform*			m_pTransformCom = nullptr; //움직여야하기 때문에 움직임관련 기능이 구현되어있는 Transform컴포넌트를 포함해준다.
	CAMERADESC					m_CameraDesc; //카메라 구조체


public:
	virtual CGameObject* Clone(void* pArg) = 0; // 복사 함수
	virtual void Free();
};

END