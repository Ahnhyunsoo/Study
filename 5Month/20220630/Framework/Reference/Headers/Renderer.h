#pragma once
#include "Component.h"

/*
화면에 그려져야할 객체들을 그려져야할 순서대로 보관한다.
보관하고있는 객체들의 랜덤함수를 호출해준다.
알파블랜딩에 따라 랜더링하는 순서를 정해서 저장해준다.
여기서 알파블랜딩에 대한 정확한 개념을 짚고 넘어가자.
알파블랜딩이란 API에선 보통 그저 투명도조절에 대한 개념으로 알고있는 사람이 많다.
하지만 블랜딩이란? 섞는다는 의미로 즉 두가지 색상을 섞는 작업이다.
때문에 섞어야할 대상객체가 필요하기 때문에 알파블랜딩을 하지 않는 객체들을 먼저 랜더하고
그다음 알파블랜딩이 필요한 객체들을 랜더링해서 블랜딩하지 않는 객체의 색상을 가지고 알파블랜딩을 하는 것 이다.
때문에 그리는 순서가 중요하다. 하지만 만약 전부다 알파블랜딩을 하는 객체라면 어떻게 해야할까?
여기선 멀리있는 객체부터 그리면 된다. 하지만 멀리있는 객체부터 랜더하려면 
랜더러리스트에 추가할 때 멀리있는 객체부터 추가하거나 랜더링할 때 깊이버퍼를 체크해서 소팅하는 방법이 있는데
추가할 때 이작업을 하면 너무 복잡하기 때문에 랜더링할 때 정렬을 해준다. 이걸 알파소팅 이라고 한다.
만약 소팅도중 깊이버퍼값이 서로같은 객체들이 있다면? 이땐 서로 출력이 됐다 안됐다 번갈아가면서 출력되는데
이걸 ZFighting 이라고 하며 이에 대한 해결법은 한객체의 깊이버퍼를 약간 밀거나 땡겨서 해결한다고 한다.
UI는 오브젝트에 가려지면 안되기 때문에 깊이버퍼테스트를 하지않는다. 대신 무조건 맨 마지막에 랜더를 해준다.
*/


BEGIN(Engine) 

class ENGINE_DLL CRenderer final : public CComponent
{
public: //그려지는 순서에따라 열거체로 분류한다.
	enum RENDERGROUP {RENDER_PRIORITY, RENDER_NONALPHABLEND, RENDER_ALPHABLEND, RENDER_UI, RENDER_END };

private:
	CRenderer(LPDIRECT3DDEVICE9 pGraphic_Device);
	CRenderer(const CRenderer& rhs);
	virtual ~CRenderer() = default;

public:
	virtual HRESULT Initialize_Prototype() override;
	virtual HRESULT Initialize(void* pArg) override;

public:
	HRESULT Add_RenderGroup(RENDERGROUP eRenderGroup, class CGameObject* pGameObject); // 인자로 받은 오브젝트를
										//인자로 받은 RenderGroup에 추가해주는 함수
	HRESULT Draw(); //그룹내에 있는 오브젝트들의 랜더를 그룹순서대로 호출해준다.

private:
	list<class CGameObject*> m_RenderObjects[RENDER_END]; //그리는 순서별로 오브젝트를 분류해서 리스트에 저장한다.
	typedef list<class CGameObject*> RENDEROBJECTS;

public:
	static CRenderer* Create(LPDIRECT3DDEVICE9 pGraphic_Device); // Renderer컴포넌트를 생성해주는 함수
	virtual CComponent* Clone(void* pArgs) override; // 원형 컴포넌트를 복사해주는 재정의된 함수
	virtual void Free() override; // 재정의된 Free함수
};

END