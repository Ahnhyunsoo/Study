#pragma once
#include "Base.h"
/*
Ŭ���̾�Ʈ�� ��� Object���� ��ӹ޴� �θ�Ŭ����
*/
BEGIN(Engine)

class ENGINE_DLL CGameObject abstract : public CBase
{
protected:
	CGameObject(LPDIRECT3DDEVICE9 pGraphic_Device); //��ġ�� �����ϴ� ������
	CGameObject(const CGameObject& rhs); //�纻��ü ������ ���� ���� ������
	virtual ~CGameObject() = default;

public:
	virtual HRESULT Initialize_Prototype(); //������ü�� �ʱ�ȭ�� ���ִ��Լ�
	virtual HRESULT Initialize(void* pArg); // �纻��ü�� �ʱ�ȭ�� ���ִ��Լ�
	virtual void Tick(_float fTimeDelta);
	virtual void LateTick(_float fTimeDelta);
	virtual HRESULT Render();

protected:
	LPDIRECT3DDEVICE9 m_pGraphic_Device;

public:
	virtual CGameObject* Clone(void* pArg) = 0; //������ü�� ���ڷ� �޾� �������ִ� �Լ�
	virtual void Free() override;
};

END