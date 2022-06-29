#pragma once
#include "Base.h"

BEGIN(Engine)

class CLevel_Manager final : public CBase
{
	DECLARE_SINGLETON(CLevel_Manager)
private:
	CLevel_Manager();
	virtual ~CLevel_Manager() = default;

public:
	HRESULT Open_Level(class CLevel* pNewLevel); // 인자로 레벨객체를받아 해당객체로 레벨을 교체해주는 함수
	void Tick(_float fTimeDelta);
	HRESULT Render();

private:
	class CLevel* m_pCurrentLevel = nullptr; //현재 레벨을 저장할 변수

public:
	virtual void Free() override;
};

END

