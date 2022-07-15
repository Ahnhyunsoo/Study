#pragma once

/* Ŭ�󿡼� ������ ī�޶���� �θ�. */
/* ��� ī�޶� �������� �⺻���� ����� �����Ѵ�. */
#include "GameObject.h"
#include "Transform.h"

BEGIN(Engine)

class ENGINE_DLL CCamera abstract : public CGameObject //���ӿ�����Ʈ�� ��ӹ޴� �߻�Ŭ����
{
public:
	typedef struct tagCameraDesc //ī�޶� �������� �������� �����ϴ� ����ü
	{
		_float3		vEye, vAt; //vEye = ��ġ, vAt = �ٶ󺸴��� 
		_float		fFovy, fAspect, fNear, fFar; //fFovy = ī�޶󰢵�, fAspect = ������Ʈ, �Ͼ� = z���ּҹ���, far = z���ִ����

		CTransform::TRANSFORMDESC		TransformDesc; //���ڷ� �����ϱ� ���� Ʈ�������� ����ü�� �����س��´�.
	}CAMERADESC;

protected:
	CCamera(LPDIRECT3DDEVICE9 pGraphic_Device);//���� ���� �� ��ġ�� �����Ѵ�.
	CCamera(const CCamera& rhs, CTransform::TRANSFORMDESC* pArg); 
	// 1���� = ������ ���� 
	// 2���� = ��������ڿ��� Transform������Ʈ�� �����ؼ� ������ �������ִµ� ������ �� �ʿ��� Ʈ������ ����ü
	virtual ~CCamera() = default;

public:
	virtual HRESULT Initialize_Prototype(); //������ü �ʱ�ȭ�Լ�
	virtual HRESULT Initialize(void* pArg); //�纻��ü �ʱ�ȭ�Լ�
	virtual void Tick(_float fTimeDelta); 
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

protected:
	class CTransform*			m_pTransformCom = nullptr; //���������ϱ� ������ �����Ӱ��� ����� �����Ǿ��ִ� Transform������Ʈ�� �������ش�.
	CAMERADESC					m_CameraDesc; //ī�޶� ����ü


public:
	virtual CGameObject* Clone(void* pArg) = 0; // ���� �Լ�
	virtual void Free();
};

END