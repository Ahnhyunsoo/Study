#include "..\Public\Layer.h"
#include "GameObject.h"


CLayer::CLayer()
{
}

HRESULT CLayer::Add_GameObject(CGameObject* pGameObject)
{
	if (pGameObject == nullptr)
		return E_FAIL;

	m_GameObjects.push_back(pGameObject);

	return S_OK;
}

HRESULT CLayer::Initialize()
{

	return S_OK;
}

void CLayer::Tick(_float fTimeDelta)
{
	//범위기반 for문 기존 for문과 달리 시작점과 끝부분을 알려주지않아도 처음부터 끝까지 순회해주는 for문
	//1인자 순회한원소를 저장할 변수 , 2인자 순회할 컨테이너 vector 또는 list등등 여기선 list이다.
	//auto = 어떤자료형이든 컴파일러가 알아서 판단해줌
	//auto에 &(래퍼런스)를 붙힌 이유 = 래퍼런스를 안붙히면 계속 복사가 일어남 그리고 원본의 값을 변경할 수 없음
	//포인터 맨처음 배웠을 때 Swap하면서 배운 개념과 비슷 복사본에 무슨짓을해도 원본값은안변함
	for (auto& pGameObject : m_GameObjects)
	{
		if (nullptr != pGameObject) //만약 원소가 있다면
			pGameObject->Tick(fTimeDelta); //해당 원소의 Tick을 호출 
		//우리는 m_GameObjects라는 리스트에 오브젝트를 저장했기때문에 오브젝트는 Tick함수를 갖고있음
	}
}
//위와 동일
void CLayer::LateTick(_float fTimeDelta)
{
	for (auto& pGameObject : m_GameObjects)
	{
		if (nullptr != pGameObject)
			pGameObject->LateTick(fTimeDelta);
	}
}

CLayer* CLayer::Create()
{
	CLayer* pInstance = new CLayer();
	
	if (FAILED(pInstance->Initialize())) //예외처리를 위해 만약 초기화가 실패했다면 이라는 조건을 걸고
	{
		MSG_BOX(TEXT("Failed To Created : CLayer")); // 매크로로 정의해준 메세지박스를 통해 어떤작업이 실패했는지 알려준다.
		Safe_Release(pInstance); //그리고 할당한 객체의 초기화를 실패했으니 삭제해준다.
	}
	return pInstance; //문제없이 초기화 했으면 리턴
}

void CLayer::Free()
{
	for (auto& pGameObject : m_GameObjects)
		Safe_Release(pGameObject); //원소들을 전부 삭제해줌
	m_GameObjects.clear(); //리스트의 원소들을 비워줌
}