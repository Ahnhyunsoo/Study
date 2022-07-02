#pragma once

#include "Client_Defines.h"
#include "Base.h"
/*
�� Ŭ������ ���������� �ʿ��� ���ҽ�,��ü���� �������ְ�
�����带 �����ؼ� ������ �����忡�� �ε����߿� ȭ�鿡 ǥ������ �۾����� �Ѵ�.
�������? ���ϳ��� �����帧�̴�.
�����ϰ� �����帧�̶��ϸ� ���ذ� �߾ȵ��ٵ� ���� ����.
���α׷��̶� �帧�� �����ϰ� �ݵ�� �帧�� ���� ����Ǿ���Ѵ�.
������ ���� a~z��� �帧�� �ִµ� a��� �帧�� �����ϰ��ִµ� f��� �帧�� ���ÿ� �����ϰ�ʹٸ�
���ϳ��� �����帧�� �����带 �����ϰ� a��� �帧�� ������ �� ������ �����忡�� f��� �帧�� �����ϰ��ϸ� 
�ΰ��� ���ÿ� �����ϴ� ȿ���� ���� �� �ִ�.
�� LoaderŬ�������� ��ü�� ���ҽ����� �ҷ����̴� �۾��� �� ���� ȭ���� ������� �۾��� ���ÿ� �� �� ���⶧���� �����ִ�.
������ �� �� �����带 �ϳ� �����ؼ� �� �����忡�� �����۾��� �����ϰ��ϸ� �ҷ����̴��۾������ÿ� �����۾����� ���ÿ� �� �� �ִ�. 
*/

BEGIN(Client)

class CLoader final : public CBase
{
public:
	CLoader(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual ~CLoader() = default;

public:
	LEVEL Get_NextLevelID() const {
		return m_eNextLevelID;
	}

	const _tchar* Get_LoadingText() const { // 
		return m_szLoadingText;
	}

	_bool Get_Finished() const { //�ε��� �������� üũ���ִ� �Һ���
		return m_isFinished;
	}

	CRITICAL_SECTION Get_CS() const {
		return m_CriticalSection;
	}

public:
	HRESULT Initialize(LEVEL eNextLevelID);
	HRESULT Loading_ForLogoLevel();
	HRESULT Loading_ForGamePlayLevel();

private:
	LPDIRECT3DDEVICE9	m_pGraphic_Device = nullptr;

private:
	HANDLE				m_hThread = 0;
	CRITICAL_SECTION	m_CriticalSection;
	LEVEL				m_eNextLevelID = LEVEL_END;

private:
	_tchar				m_szLoadingText[MAX_PATH] = TEXT("");
	_bool				m_isFinished = false;

public:
	static CLoader* Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID);
	virtual void Free() override;
};

END