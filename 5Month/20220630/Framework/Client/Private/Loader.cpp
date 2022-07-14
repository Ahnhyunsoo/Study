#include "stdafx.h"
#include "..\Public\Loader.h"

#include "GameInstance.h"
#include "BackGround.h"

CLoader::CLoader(LPDIRECT3DDEVICE9 pGraphic_Device)
	: m_pGraphic_Device(pGraphic_Device)
{
	Safe_AddRef(m_pGraphic_Device);
}

_uint APIENTRY LoadingMain(void* pArg) //�����忡�� �۾����� �ڵ�
{
	CLoader*		pLoader = (CLoader*)pArg;

	EnterCriticalSection(&pLoader->Get_CS()); 
	/* ���⼭ CriticalSection �̶�
	�Ӱ豸���� �ǹ��Ѵ�. �̰� ������ �дٴ� �ǹ��ε�
	����ġ���� ����� �����ϱ����� ����ó���� ���ִ°��̴�.
	������� 10���� �����尡 �ִµ� 10���� �����尡 ���ÿ� ���� �Լ��� �����Ѵٰ� ��������.
	�׷��� ���� ���ϴ� ����� 1�ʿ� 1�� �����ϴ°��ε� ���ÿ� 10���� �����尡 �����ϱ⶧����
	1�ʿ� 10�� �����ϴ� ����� �ʷ��� �� �ִ�.
	������ �ϳ��� �����尡 �۾����̸� �ٸ������尡 �������� ���ϰ� ����ó���ϴ°��� �Ӱ豸��(Critical Section�̶���Ѵ�)
	�̰� ������ ��������(DeadLock)��� ������ �߻��ϴµ� �ñ��ϸ� ���۸� �ϱ� �ٶ��ϴ�.
	*/
	switch (pLoader->Get_NextLevelID()) //����ġ���� ���� �Լ�����
	{
	case LEVEL_LOGO:
		pLoader->Loading_ForLogoLevel();
		break;
	case LEVEL_GAMEPLAY:
		pLoader->Loading_ForGamePlayLevel();
		break;
	}

	LeaveCriticalSection(&pLoader->Get_CS());

	return 0;
}

HRESULT CLoader::Initialize(LEVEL eNextLevelID)
{
	m_eNextLevelID = eNextLevelID;

	InitializeCriticalSection(&m_CriticalSection);

	m_hThread = (HANDLE)_beginthreadex(nullptr, 0, LoadingMain, this, 0, nullptr); 
	//_beginthreadex�����带 �ʱ�ȭ �� �������ִ� �Լ�

	if (0 == m_hThread)
		return E_FAIL;

	return S_OK;
}

HRESULT CLoader::Loading_ForLogoLevel()
{
	lstrcpy(m_szLoadingText, TEXT("��ü������ �ε����Դϴ�. "));

	CGameInstance*		pGameInstance = CGameInstance::Get_Instance();
	Safe_AddRef(pGameInstance);

	/* ��ü������ �߰��Ѵ�. */
	if (FAILED(pGameInstance->Add_Prototype(TEXT("Prototype_GameObject_BackGround"), CBackGround::Create(m_pGraphic_Device))))
		return E_FAIL;

	lstrcpy(m_szLoadingText, TEXT("�ؽ��ĸ� �ε����Դϴ�. "));
	/* �ؽ��ĸ� �ε��Ѵ�. */
	for (_uint i = 0; i < 999999999; ++i) //�ε��� �ʹ� ª�⶧���� �׽�Ʈ������ �����ص� �ڵ�
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("���� �ε����Դϴ�. "));
	/* �𵨸� �ε��Ѵ�. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("�ε��� �Ϸ�Ǿ����ϴ�.  "));

	Safe_Release(pGameInstance);

	m_isFinished = true;

	return S_OK;
}

HRESULT CLoader::Loading_ForGamePlayLevel()
{
	lstrcpy(m_szLoadingText, TEXT("��ü������ �ε����Դϴ�. "));
	/* ������ü���� �ε��Ѵ�. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;


	lstrcpy(m_szLoadingText, TEXT("�ؽ��ĸ� �ε����Դϴ�. "));
	/* �ؽ��ĸ� �ε��Ѵ�. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("���� �ε����Դϴ�. "));
	/* �𵨸� �ε��Ѵ�. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("�ε��� �Ϸ�Ǿ����Ϥ���.  "));

	m_isFinished = true;

	return S_OK;
}

CLoader * CLoader::Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID)
{
	CLoader*		pInstance = new CLoader(pGraphic_Device);

	if (FAILED(pInstance->Initialize(eNextLevelID)))
	{
		MSG_BOX(TEXT("Failed To Created : CLoader"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLoader::Free()
{
	//�����带 �������ִ� �Լ���
	WaitForSingleObject(m_hThread, INFINITE);

	DeleteCriticalSection(&m_CriticalSection);

	CloseHandle(m_hThread);

	Safe_Release(m_pGraphic_Device);


}
