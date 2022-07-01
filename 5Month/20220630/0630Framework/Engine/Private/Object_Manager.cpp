#include "..\Public\Object_Manager.h"
#include "GameObject.h"
#include "Layer.h"

IMPLEMENT_SINGLETON(CObject_Manager)

CObject_Manager::CObject_Manager()
	:m_iNumLevels(0), m_pLayers(nullptr)
{
}


HRESULT CObject_Manager::Reserve_Container(_uint iNumLevels)
{
	if (m_pLayers != nullptr) //사본객체를 저장할map컨테이너가 이미 있다면
		return S_OK; //이미 있으니 성공했다고 리턴

	m_pLayers = new LAYERS[iNumLevels];//맵컨테이너를 동적배열로 구현한다. 인자로 받은 레벨의 갯수만큼 할당해줌

	m_iNumLevels = iNumLevels; //맴버변수에 인자로받은 레벨갯수를 저장해줌

	return S_OK; 
}

HRESULT CObject_Manager::Add_Prototype(const _tchar* pPrototypeTag, CGameObject* pPrototype)
{
	if (Find_Prototype(pPrototypeTag) != nullptr) //인자로 받은 태그를 통해 map에서 원형객체가 있는지 검색함
		return E_FAIL;					//원형 객체는 한개만 존재해야 하므로 검색되면 함수를 종료시킨다.

	m_Prototypes.emplace(pPrototypeTag, pPrototype); //만약 원형객체가 없다면 map컨테이너 인자로받은 원형객체를 추가한다.
	//모를리 없겠지만 혹시나해서 emplace는 map컨테이너의 여러종류의 원소추가방법중 하나인데 가장간편해서 많이씀

	return S_OK;
}

									//const를 붙히는이유 : 값이 복사되면 안되기 때문에 못바꾸게 상수화 시키는것 
									//예를 들어 검색할 key값인데 이걸 수정해버리면... 검색결과가 이상해진다.
HRESULT CObject_Manager::Add_GameObjectToLayer(const _tchar* pPrototypeTag, _uint iLevelIndex, const _tchar* pLayerTag, void* pArg)
{
	CGameObject* pPrototype = Find_Prototype(pPrototypeTag); //인자로 받은 태그로 원형객체를 탐색해서 얻은 결과를 변수에 저장

	if (pPrototype == nullptr) //만약 태그에 해당하는 원형객체가 없다면 함수종료
		return E_FAIL;

	CGameObject* pGameObject = pPrototype->Clone(pArg); //원형객체 클론함수의 리턴값을 나온결과를 변수에 저장
	//클론 함수 실행시 사본객체를 리턴해줌. 
	if (pGameObject == nullptr) // 만약 Clone함수가 제대로 진행되지 않았으면 함수를종료시킴
		return E_FAIL;

	CLayer* pLayer = Find_Layer(iLevelIndex, pLayerTag); //인자로 받은 레벨과 태그를 통해 레이어를 검색해서 변수에 저장

	if (pLayer == nullptr) // 만약 map에 인자로받은 값에 해당하는 레이어가 없다면
	{
		pLayer = CLayer::Create(); // 레이어를 새로 생성한다.
		if (pLayer == nullptr) // 만약 레이어생성에 실패했다면 함수종료
			return E_FAIL;

		pLayer->Add_GameObject(pGameObject); // 생성한 레이어에 위에서 저장해둔 사본객체를 레이어에 추가해준다.

		m_pLayers[iLevelIndex].emplace(pLayerTag, pLayer); // 그리고 Object_Manager동적배열map에 새로 생성한 레이어를 추가해준다.
	}
	else // 만약 레이어가 map내에 존재한다면
		pLayer->Add_GameObject(pGameObject); // 해당레이어에 저장해둔 사본객체를 레이어에 추가해준다.

	return S_OK;
}

void CObject_Manager::Tick(_float fTimeDelta)
{
	for (_uint i = 0; i < m_iNumLevels; ++i) //전체 레벨의 갯수만큼 for문을 반복한다.
	{
		for (auto& Pair : m_pLayers[i]) //동적할당한 map컨테이너의 i번째를 범위기반 for문을 실행한다. 		
		{								//	(map의 원소는 key값과 value를 갖는 Pair라는 객체)
			if (Pair.second != nullptr) //만약 Pair의 value 즉 오브젝트가 존재한다면
			{
				Pair.second->Tick(fTimeDelta); // 해당오브젝트의 Tick함수를 실행시켜준다.
			}
		}
	}
}

//위와 동일
void CObject_Manager::LateTick(_float fTimeDelta)
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pLayers[i])
		{
			if (nullptr != Pair.second)
				Pair.second->LateTick(fTimeDelta);
		}
	}
}

void CObject_Manager::Clear(_uint iLevelIndex)
{
	for (auto& Pair : m_pLayers[iLevelIndex])//인자로받은 레벨의 레이어를 순회
	{
		Safe_Release(Pair.second); // 해당 레이어의 객체들을 삭제해줌
	}
	m_pLayers[iLevelIndex].clear(); // 이후 다시 해당레벨로 돌아올 수 있으니 맵을 삭제하는것이 아닌 clear만 해준다.
}

CGameObject* CObject_Manager::Find_Prototype(const _tchar* pPrototypeTag)
{
	auto iter = find_if(m_Prototypes.begin(), m_Prototypes.end(), CTag_Finder(pPrototypeTag));
	/*find_if함수를 통해 리턴받은 결과값을 iter에 저장

	★이 부분이 굉장히 복잡한데 집중해서 잘 보길 바랍니다!★

	우선 Engine_Functor를 가보면 CTag_Finder라는 함수객체가 만들어져있습니다. 한번 보고오세요
	함수객체란 객체를 메모리에 할당하지 않고 임시메모리에 올려서 함수처럼 사용하는 문법
	즉 3번째 인자에 CTag_Finder(pPrototypeTag)를 한순간 
	pPrototypetag를 인자로 받는 CTag_Finder의 생성자가 호출되어 임시메모리에 올라간다.
	그리고 이 임시메모리에 생성된 함수객체를 find_if의 인자로 넣어준다.
	이 find_if는 F12를 타고들어가도 이해하기 힘든데 대충 설명하자면
	find_if함수는 3번째 들어온 인자에 순회하고있는 원소를 넣어 그 값이 True라면 해당 원소를 반환한다.
	CTag_Finder에는 ()연산자가 오버로딩되어있고 인자로받은 Piar.first와 
	저장해놓은 문자열을 비교해서 True or false를 리턴하는데
	때문에 m_Prototypes의 처음부터 끝까지 존재하는 원소들을 전부 CTag_Finder라는 함수객체에 인자로 넣어서
	CTag_Finder안에 연산자오버로딩된 함수를 실행하고 그값이 True일 경우에 원소를 반환해준다.
	한번더 정리하자면
	즉 find_if에서 3번째 인자로 CTag_Finder(pPrototypeTag)를 하는순간 생성자가호출되어
	인자로 받은 pPrototypeTag를 CTag_Finder객체안에있는 변수에 저장한 후 임시메모리에 올라가고
	임시메모리에 있는 이 태그를 저장한 객체를 find_if내에서 m_Prototypes를 처음부터 끝까지 순회하면서
	순회하고있는 원소(Pair)를 CTag_Finder(Pair)를 호출하여 이 결과값이 True인 경우에 인자로 넣은 Pair를 리턴해준다.
	*/

	if (iter == m_Prototypes.end())//만약 저장한 값이 map의 end를 가르킨다면 해당태그로 탐색한 값이 없다는것
		return nullptr; //nullptr을 반환

	return iter->second; // iter의 second 즉 원형객체를 반환
}


CLayer* CObject_Manager::Find_Layer(_uint iLevelIndex, const _tchar * pLayerTag)
{
	//인자로 받은 레벨인덱스와 태그에 해당하는 레이어를 검색
	auto	iter = find_if(m_pLayers[iLevelIndex].begin(), m_pLayers[iLevelIndex].end(), CTag_Finder(pLayerTag));
	//위함수와 동일
	if (iter == m_pLayers[iLevelIndex].end())
		return nullptr;

	return iter->second;
}

void CObject_Manager::Free()
{
	for (_uint i = 0; i < m_iNumLevels; ++i) //레벨의 갯수만큼 순회한다
	{
		for (auto& Pair : m_pLayers[i]) 
			Safe_Release(Pair.second); // 해당하는 레벨의 객체를 제거한다.

		m_pLayers[i].clear(); // 이후 맵 컨테이너를 clear해준다.
	}

	Safe_Delete_Array(m_pLayers); // 이후 배열을 삭제해준다. 동적배열 했기 때문에 삭제해줘야한다.

	for (auto& Pair : m_Prototypes)	 
		Safe_Release(Pair.second); // 객체를 삭제해준다.

	m_Prototypes.clear(); //map컨테이너를 clear해준다.
	
}