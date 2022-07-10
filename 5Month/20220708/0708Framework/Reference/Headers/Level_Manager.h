#pragma once
#include "Base.h"
/*
Level�� API�� Scene�� �ſ� �����ϴ�. ������ SceneManager�� �����ϰ�
����Level�� Tick(Update)�� Render�� ��� ȣ�����ְ� Level(Scene)���� �۾��� ���ش�..
�� Level_Manager�� ���� ���� Level�� �۾��� Level������ ���ִ� �Լ��� ����������.
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
	class CLevel*				m_pCurrentLevel; //���� ������ �ּҸ� �����ϱ� ���� ����
	_uint						m_iCurrentLevelIndex; //���� ������ Map�����̳ʹ迭�� �ε����� �����ϱ����� ����

public:
	virtual void Free() override;
};

END

