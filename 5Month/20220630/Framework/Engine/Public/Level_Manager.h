#pragma once
#include "Base.h"
/*
Level은 API때 Scene과 매우 유사하다. 때문에 SceneManager와 유사하게
현재Level의 Tick(Update)과 Render를 계속 호출해주고 Level(Scene)변경 작업도 해준다..
이 Level_Manager를 통해 현재 Level의 작업과 Level변경을 해주는 함수를 구현해주자.
*/

BEGIN(Engine)

class CLevel_Manager final : public CBase
{
	DECLARE_SINGLETON(CLevel_Manager)
private:
	CLevel_Manager();
	virtual ~CLevel_Manager() = default;

public:
	HRESULT Open_Level(_uint iLevelIndex, class CLevel* pNewLevel);
	void Tick(_float fTimeDelta);
	HRESULT Render();

private:
	class CLevel*				m_pCurrentLevel; //현재 레벨의 주소를 저장하기 위한 변수
	_uint						m_iCurrentLevelIndex; //현재 레벨의 Map컨테이너배열의 인덱스를 저장하기위한 변수

public:
	virtual void Free() override;
};

END

