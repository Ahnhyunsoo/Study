#pragma once
#include "Component.h"

/*
ȭ�鿡 �׷������� ��ü���� �׷������� ������� �����Ѵ�.
�����ϰ��ִ� ��ü���� �����Լ��� ȣ�����ش�.
���ĺ����� ���� �������ϴ� ������ ���ؼ� �������ش�.
���⼭ ���ĺ����� ���� ��Ȯ�� ������ ¤�� �Ѿ��.
���ĺ����̶� API���� ���� ���� ���������� ���� �������� �˰��ִ� ����� ����.
������ �����̶�? ���´ٴ� �ǹ̷� �� �ΰ��� ������ ���� �۾��̴�.
������ ������� ���ü�� �ʿ��ϱ� ������ ���ĺ����� ���� �ʴ� ��ü���� ���� �����ϰ�
�״��� ���ĺ����� �ʿ��� ��ü���� �������ؼ� �������� �ʴ� ��ü�� ������ ������ ���ĺ����� �ϴ� �� �̴�.
������ �׸��� ������ �߿��ϴ�. ������ ���� ���δ� ���ĺ����� �ϴ� ��ü��� ��� �ؾ��ұ�?
���⼱ �ָ��ִ� ��ü���� �׸��� �ȴ�. ������ �ָ��ִ� ��ü���� �����Ϸ��� 
����������Ʈ�� �߰��� �� �ָ��ִ� ��ü���� �߰��ϰų� �������� �� ���̹��۸� üũ�ؼ� �����ϴ� ����� �ִµ�
�߰��� �� ���۾��� �ϸ� �ʹ� �����ϱ� ������ �������� �� ������ ���ش�. �̰� ���ļ��� �̶�� �Ѵ�.
���� ���õ��� ���̹��۰��� ���ΰ��� ��ü���� �ִٸ�? �̶� ���� ����� �ƴ� �ȵƴ� �����ư��鼭 ��µǴµ�
�̰� ZFighting �̶�� �ϸ� �̿� ���� �ذ���� �Ѱ�ü�� ���̹��۸� �ణ �аų� ���ܼ� �ذ��Ѵٰ� �Ѵ�.
UI�� ������Ʈ�� �������� �ȵǱ� ������ ���̹����׽�Ʈ�� �����ʴ´�. ��� ������ �� �������� ������ ���ش�.
*/


BEGIN(Engine) 

class ENGINE_DLL CRenderer final : public CComponent
{
public: //�׷����� ���������� ����ü�� �з��Ѵ�.
	enum RENDERGROUP {RENDER_PRIORITY, RENDER_NONALPHABLEND, RENDER_ALPHABLEND, RENDER_UI, RENDER_END };

private:
	CRenderer(LPDIRECT3DDEVICE9 pGraphic_Device);
	CRenderer(const CRenderer& rhs);
	virtual ~CRenderer() = default;

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg) override;

public:
	HRESULT Add_RenderGroup(RENDERGROUP eRenderGroup, class CGameObject* pGameObject); // ���ڷ� ���� ������Ʈ��
										//���ڷ� ���� RenderGroup�� �߰����ִ� �Լ�
	HRESULT Draw(); //�׷쳻�� �ִ� ������Ʈ���� ������ �׷������� ȣ�����ش�.

private:
	list<class CGameObject*> m_RenderObjects[RENDER_END]; //�׸��� �������� ������Ʈ�� �з��ؼ� ����Ʈ�� �����Ѵ�.
	typedef list<class CGameObject*> RENDEROBJECTS;

public:
	static CRenderer* Create(LPDIRECT3DDEVICE9 pGraphic_Device); // Renderer������Ʈ�� �������ִ� �Լ�
	virtual CComponent* Clone(void* pArgs) override; // ���� ������Ʈ�� �������ִ� �����ǵ� �Լ�
	virtual void Free() override; // �����ǵ� Free�Լ�
};

END