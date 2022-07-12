#pragma once
#include "Base.h"

/*
������Ʈ��?
��ü���� �ʿ��� ��ɵ��� �������� ������ Is a ��Ӱ��谡 �ƴ� Has a ��Ӱ���� ��ӹް��Ͽ� 
������Ʈ�� �ִ� ��ɵ��� ��ӹ��� ��ü���� ��밡���ϰ� �ϴ� ��
�� ��ü�� �ʿ��� ����� �̸� ����� ���� �׸� (Ŭ������ ��������� ������ �ٸ�)

Is a ���� �� Has a �����?
Is a �� ����
Class Object : public CBase <<< �̰� Is a �����̴�. �� ������Ʈ�� CBase�� ������ӹ޴´ٴ� ��
Has a �� ����
Class Object
{
private:
	CBase* Component; <<< �̰� Has a �����̴�. �� ������Ʈ�� CBase��� ������Ʈ�� �����ϰ� �ִ´ٴ� ��
}

���⼭ ����� ������ Ȯ���� ��� �����ϴµ�
����̶�? ��ӹ��� Ŭ������ �޸𸮻��� �ּҸ� ���� �ִ°� ����̴�.
�� ������ Has a ����� ��ӹ޾Ƶ� �Ҵ縸 ���ָ� ��ӹ��� �� �̴�.
is a �� ����̶�θ��� has a �� �����̶� �θ�����
�Ѵ� ����� ����̴�. ����̶� �ڽ��� �޸𸮾ȿ� ��ӹ��� Ŭ������ �Ҵ��ϴ� �����̴�.
*/

//�� Ŭ������ ��� ������Ʈ���� ��ӹ޾ƾ��ϴ� Ŭ�����̴�.

BEGIN(Engine)

class ENGINE_DLL CComponent abstract : public CBase
{
protected:
	CComponent(LPDIRECT3DDEVICE9 pGraphic_Device); //��ġ�� �����ϱ����� ������
	CComponent(const CComponent& rhs); // �纻�� �����ϱ����� ������
	virtual ~CComponent() = default;

public:
	virtual HRESULT Initialize_Prototype(); // ������ü�� �ʱ�ȭ�Լ�
	virtual HRESULT Initialize(void* pArg); //�纻��ü�� �ʱ�ȭ�Լ�

protected:
	LPDIRECT3DDEVICE9 m_pGraphic_Device; // ��ġ�� ������ ����

public:
	virtual CComponent* Clone(void* pArg) = 0; // ������Ʈ�� �����Լ� ���������Լ��� �����д�.
	virtual void Free() override;
};

END