#include "..\Public\Component_Manager.h"
#include "Component.h"

IMPLEMENT_SINGLETON(CComponent_Manager)


CComponent_Manager::CComponent_Manager()
	:m_iNumLevels(0)
{
}

HRESULT CComponent_Manager::Reserve_Container(_uint iNumLevels)
{
	if (m_pPrototypes != nullptr) //nullptr이 아니라면 이미 할당됐다는 것
		return S_OK;

	m_iNumLevels = iNumLevels;

	m_pPrototypes = new PROTOTYPES[iNumLevels]; //없다면 동적할당

	return S_OK;
}

HRESULT CComponent_Manager::Add_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag, CComponent * pPrototype)
{
	if (iLevelIndex >= m_iNumLevels) //인자로 들어온 iLevelIndex이 m_iNumLevels 이상이라면 함수종료 
		//m_iNumLevels은 인덱스기때문에 사실상 1이 더적고 iLevelIndex가 m_iNumLevels이상이라는건 1더크다는뜻 즉 범위가벗어남
		return E_FAIL; 

	if (Find_Component(iLevelIndex, pPrototypeTag) != nullptr) //해당하는 컴포넌트를 찾지못했다면 함수종료
		return E_FAIL;

	m_pPrototypes[iLevelIndex].emplace(pPrototypeTag, pPrototype); // 찾았다면 map에 해당태그와 컴포넌트를 추가
	return S_OK;
}

CComponent * CComponent_Manager::Clone_Component(_uint iLevelIndex, const _tchar * pPrototypeTag, void * pArg)
{
	CComponent* pPrototype = Find_Component(iLevelIndex, pPrototypeTag);// 컴포넌트를 찾는함수를통해 받은 컴포넌트를 저장
	if (pPrototype == nullptr)
		return nullptr;

	return pPrototype->Clone(pArg); //만약 컴포넌트가 있다면 해당 컴포넌트의 Clone함수를 실행해 나온 결과값을 리턴
}

CComponent * CComponent_Manager::Find_Component(_uint iLevelIndex, const _tchar * pPrototypeTag)
{
	auto iter = find_if(m_pPrototypes[iLevelIndex].begin(), m_pPrototypes[iLevelIndex].end(), CTag_Finder(pPrototypeTag));
	//Tag_Finder를 통해 객체를 찾고 찾았다면 iter에 저장 iter = Pair

	if (iter == m_pPrototypes[iLevelIndex].end()) //Pair가 가르키는게 map의 end라면 즉 컴포넌트를 찾지못했다면
		return nullptr; // nullptr 리턴

	return iter->second; // 찾았다면 찾은 객체의 value값을 리턴 여기서 value값은 컴포넌트객체이다.
}

void CComponent_Manager::Free()
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pPrototypes[i])
			Safe_Release(Pair.second); //리스트내의 컴포넌트 객체들의 래퍼런스카운터를 감소

		m_pPrototypes[i].clear(); // 이후 map을 클리어해준다. Pair.First 즉 태그가 남아있기 때문.
	}

	Safe_Delete_Array(m_pPrototypes); //모든 작업을 마친 후 동적배열이기 때문에 리스트를 삭제
}
