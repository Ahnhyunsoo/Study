#include "..\Public\Level_Manager.h"
#include "Level.h"
#include "GameInstance.h" //만약 진행과정이 대로 따라했다면 처음엔 오류가나지만 이후에 GameInstance클래스를
							//구현해주면 사라지기 때문에 신경쓰지말자!

IMPLEMENT_SINGLETON(CLevel_Manager)


CLevel_Manager::CLevel_Manager()
	:m_pCurrentLevel(nullptr),m_iCurrentLevelIndex(0)
	//초기화는 헤더가 아닌 생성자에서 해주자. 대입연산을 안해서 더 빠름
	//사실 이렇게 해주면 우리 반장이 좋아함
{
}

HRESULT CLevel_Manager::Open_Level(_uint iLevelIndex, CLevel* pNewLevel)
{
	if (m_pCurrentLevel == nullptr) //m_pCurrentLevel = 현재 레벨의 주소를저장 그런데 nullptr이라면?
	{								// 즉 맨처음 초기단계 라는 뜻 만들어진 Level이 없기 때문이다. 
		CGameInstance* pGameInstance = CGameInstance::Get_Instance();
		//쌤코드에선 Safe_AddRef와 Safe_Release가 있지만 설명했듯이 참조가 아니기때문에 안해줘도됨
		//pGameInstance의 변수에 저장했는데 라고 생각할수도있지만 여긴 함수다. 즉 스택영역이기때문에 함수끝나면 삭제됨
		pGameInstance->Clear(m_iCurrentLevelIndex);//나중에 GameInstance를 구현할 때 설명하겠음
	}
	Safe_Release(m_pCurrentLevel); //현재레벨의 Safe_Release를 호출해줌 래퍼런스카운터가 0이니 삭제될 것 이다.

	m_pCurrentLevel = pNewLevel; //기존 레벨을 삭제한 후 인자로 받은 변경할 레벨을 대입

	m_iCurrentLevelIndex = iLevelIndex; // 위와 동일

	return S_OK; //Graphic_Device에서 설명한 HRESULT의 재정의된 리턴값. S_OK는 성공을 의미
}

void CLevel_Manager::Tick(_float fTimeDelta)
{
	if (m_pCurrentLevel == nullptr) //만약 현재 레벨이 없다면 함수를 종료시킨다.
		return;
	//현재 레벨이 있다면 현재레벨의 Tick함수를 호출한다.
	m_pCurrentLevel->Tick(fTimeDelta);
	//여기서 인자로받은 fTimeDelta는 MainApp에서 얻어온 fTimeDelta이다.
	//한시점에서 얻은 시간값을 인자로 넘겨주면서 사용하기 때문에 모든 Tick함수에서 
	//같은시간값을 사용할 수 있다. 때문에 비교적 안전하다.

}

HRESULT CLevel_Manager::Render()
{
	if (m_pCurrentLevel == nullptr)
		return E_FAIL; // E_FAIL	작업을 수행할 수 없습니다.

	return m_pCurrentLevel->Render(); 
}

void CLevel_Manager::Free()
{
	Safe_Release(m_pCurrentLevel);
	//삭제할 때 현재 레벨의 Release를 호출해줌
}


