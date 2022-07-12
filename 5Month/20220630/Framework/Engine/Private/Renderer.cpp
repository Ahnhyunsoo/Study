#include "..\Public\Renderer.h"

#include "GameObject.h"

CRenderer::CRenderer(LPDIRECT3DDEVICE9 pGraphic_Device)
	:CComponent(pGraphic_Device) //장치를 인자로 받는 Renderer생성자 호출 시 부모인 CComponent의 생성자를 호출하면서
	//장치를 인자로 넘겨주고 부모안에서 래퍼런스카운트를 증가시키고 장치를 변수에 대입시켜준다.
{
}

HRESULT CRenderer::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CRenderer::Initialize(void * pArg)
{
	return S_OK;
}

			//1인자 : 어느 그룹에 추가할건지 정해주는 eNum값, 2인자 : 추가할 GameObject객체 
HRESULT CRenderer::Add_RenderGroup(RENDERGROUP eRenderGroup, CGameObject* pGameObject)
{
	if (pGameObject == nullptr) //GameObject가 nullptr이면 함수종료
		return E_FAIL;

	//만약 있다면 인자로받은 그룹에 인자로받은 객체를 추가해준다.
	m_RenderObjects[eRenderGroup].push_back(pGameObject);

	//리스트에 포인터를 저장했기 때문에 참조한 것이다. 때문에 GameObject의 래퍼런스카운터를 증가시켜준다.
	Safe_AddRef(pGameObject);

	return S_OK;
}

HRESULT CRenderer::Draw()
{
	for (_uint i = 0; i < RENDER_END; ++i)
	{
		for (auto& pRenderObject : m_RenderObjects[i])
		{
			if (pRenderObject != nullptr) //리스트내의 객체가 있다면
				pRenderObject->Render(); // 해당객체의 랜더를 호출해준다.

			Safe_Release(pRenderObject); // 이후 래퍼런스카운트를 감소시킨다. 즉 더이상 여기서 참조하지않는다는뜻
		}
		m_RenderObjects[i].clear();// 그 이후 리스트를 비워준다.
		// 이렇게 한번 랜더한 후 지워주는 이유는 유쌤 수업에서 배운 YSorting을 제대로 공부했다면 충분히 이해할수있다.
		//랜더타이밍마다 객체의 값이 갱신되기 때문에 랜더링 순서또한 매 프레임마다 갱신된 객체를 기준으로
		//바뀌어야 하기 때문에 한번 랜더할 때마다 삭제해주고 다시 추가해주고 하는식으로 작동한다.
	}
	return S_OK;
}

CRenderer* CRenderer::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CRenderer* pInstance = new CRenderer(pGraphic_Device);

	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed To Created : CRenderer"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent* CRenderer::Clone(void* pArg)
{
	AddRef(); //복사를 할 때 사본을 만드는것이 아닌 자기 자신을 리턴한다. 때문에 자기자신의 래퍼런스 카운트를 증가시킨다.
	return this;
}

void CRenderer::Free()
{
	__super::Free(); //부모의 Free함수를 호출한다. CRenderer의 부모는 CComponent
	//장치는 부모객체인 CComponent에 저장되어 있기 때문에 부모에 있는 장치를 Safe_Release해줘야하기때문에 부모의
	//Free를 호출해준다.

	for (auto& List : m_RenderObjects) //이후에 리스트배열에 있는 원소 즉 List = 리스트
	{
		for (auto& pGameObject : List) //리스트에 있는 원소 즉 pGameObject = 저장해둔 GameObject객체
		{
			Safe_Release(pGameObject); //GameObject 모두 Safe_Release 함수를 호출해준다.
		}
		List.clear(); // 그후 리스트를 클리어해준다. 이걸 배열 모두 반복하기때문에 리스트내의 객체가 모두 삭제되고
		//리스트를 클리어시킨다.
	}
}
