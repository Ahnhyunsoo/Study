#include "stdafx.h"
#include "..\Public\MainApp.h"
#include "GameInstance.h"
#include "Level_Loading.h" //�������� ���� ���߿� Ŭ���� �ۼ��ϸ� �����



using namespace Client;

CMainApp::CMainApp()
	: m_pGameInstance(CGameInstance::Get_Instance())
{
	Safe_AddRef(m_pGameInstance);
}

HRESULT CMainApp::Initialize()
{
	GRAPHICDESC			GraphicDesc; //Engine_Struct�� �ִ� ����ü�� ����
	ZeroMemory(&GraphicDesc, sizeof(GRAPHICDESC)); // �����Ⱚ ������ ���� �޸� �ʱ�ȭ�� ����
	//���ڸ� ä���� �������̴� ���� ������ ���ϰ���
	GraphicDesc.hWnd = g_hWnd; 
	GraphicDesc.eWinMode = GRAPHICDESC::MODE_WIN;
	GraphicDesc.iWinSizeX = g_iWinSizeX;
	GraphicDesc.iWinSizeY = g_iWinSizeY;

	//1���� : �����ǰ��� END�� �־��� ������ STATIC�� ������ �����̱� �����̴�.
	//2���� : ������ ����ü
	//3���� : �����ϴ� �Լ������� ������ ����̽��� ������ ������
	if (FAILED(m_pGameInstance->Initialize_Engine(LEVEL_END, GraphicDesc, &m_pGraphic_Device)))
		return E_FAIL;

	//������ �����ϴ��Լ� ���ڷ� ������ ������ �־��ش�.
	if (FAILED(Open_Level(LEVEL_LOGO)))
		return E_FAIL;

	return S_OK;
}

void CMainApp::Tick(_float fTimeDelta)
{
	if (nullptr == m_pGameInstance)
		return;

	m_pGameInstance->Tick_Engine(fTimeDelta); //GameInstance�� Tick�� ȣ�� 
	//GameInstance������ Level_Manager�� Tick�� ȣ���ϰ� Level_Manager Tick������ �ش緹���� Tick�� ȣ�����ش�.
}

HRESULT CMainApp::Render()
{
	if (nullptr == m_pGameInstance)
		return E_FAIL;


	m_pGameInstance->Render_Begin();

	m_pGameInstance->Render_Level();

	m_pGameInstance->Render_End();

	return S_OK;
}

HRESULT CMainApp::Open_Level(LEVEL eLevelID)
{
	if (nullptr == m_pGameInstance)
		return E_FAIL;

	/* �Ҵ��� ������ �����Ŵ����� ������ �� �ֵ��� �Ѵ�. 
	�� GameInstance�� Open_Level�� �ش���� �ε����� ������ Level��ü�� ���ڷ� ȣ���ϸ�
	GameInstance���� ���� ���ڷ� Level_Manger�� Open_Level�� ȣ�����ش�.
	*/
	if (FAILED(m_pGameInstance->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, eLevelID))))
		return E_FAIL; //�������� ���� Ŭ���������� �����

	return S_OK;
}

CMainApp * CMainApp::Create()
{
	CMainApp*		pInstance = new CMainApp();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed To Created : CMainApp"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CMainApp::Free()
{
	Safe_Release(m_pGameInstance);

	CGameInstance::Release_Engine();

}

/*
������������ �ϳ��� ������Ÿ�������� ������ü�� �����صΰ�
�����س��� ������ü�� �޸𸮺����Ͽ� �纻��ü�� ������ �̿��ϴ� ����̴�.
�� ������ ������ ������ü�� ������ �� �޸𸮰� �Һ�ȴٴ� ������ ������
��ü�����ӵ��� ���� ������ �ִ�.
������� ���� ������ ������ ����ϴµ� ��ü�� �����Ϸ��� �������� ��ü�� ������ �޾ƿ;��Ѵ�.
��ü�� 10�� ������ ������ ������ ����ϸ� 10�� ����� �ؾ��ϱ⶧���� ��ü�����ӵ��� ������.
�ݸ鿡 ������Ÿ�������� �����Ͽ� ������ü�� ������ ����Ͽ� �����صΰ�
������9���� ��ü�� �����ص� ������ü�� �޸𸮺����Ͽ� �����ϸ� ������ ����� �� �ʿ䰡 ���� ������ �����ӵ��� ������.
�ش����� ���� ������ ���� ������ ��쿡�� ����������
�ᱹ�� �����ʹ� ������������� �����ϱ� ������ ������Ÿ�� ������ ����ϸ�
10���� ����������� 1���� ������������� �ٿ��ֱ� ������ ��ü�����ӵ��� ������.
��ü�����ӵ��� �� �ε��ӵ��� ����Ǳ� ������ �� ������ ����ϴ°��� ����.
*/