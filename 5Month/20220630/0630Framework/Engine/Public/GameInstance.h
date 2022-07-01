#pragma once
#include "Graphic_Device.h"
#include "Level_Manager.h"
#include "Object_Manager.h"

/* Ŭ���̾�Ʈ�� �����ֱ����� ���� ��ǥ���� Ŭ�����̴�.  */
/* ���� �Ŵ���Ŭ�������� �ֿ��Լ��� Ŭ��� �����ش�.  */
/* �����ʱ�ȭ. */
/* ��������. */

BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)

private:
	CGameInstance();
	virtual ~CGameInstance() = default;

public:
	//������ �ʱ�ȭ���ִ� �Լ� 1���� : ������ ����, 2���� : Engine_Struct���� ������ ����ü, 3���� : Device�� ������ ������
	//IDirect3DDevice9** = LPDIRECT3DDEVICE9* IDirect3DDevice9*�� ���ο��� LPDIRECT3DDEVICE9���� �����ǵǾ�����
	HRESULT Initialize_Engine(_uint iNumLevel, const GRAPHICDESC& GraphicDesc, IDirect3DDevice9** pOut);
	void Tick_Engine(_float fTimeDelta);
	void Clear(_uint iLevelIndex);

public: 
	//Graphic_Device�� �ִ� �Լ��� ȣ���ϴ� ��������
	//�̷��� �ϸ� Graphic_Device�� ���̺귯��ȭ ��Ű���ʰ� �� GameInstance�� ���̺귯��ȭ ��Ű���. �ٸ�Ŭ������ ��������
	//��������� ���̺귯���� ���������� Ŭ���̾�Ʈ�� ���ʿ��� ��ɵ鸸 �� GameInstance�� ����
	//����� �� �ְԵ� �� GameInstance���� �Լ����� Ŭ�󿡼� �̿��ϴ� �Լ����� ȣ�����ִ� ����ٸ� ������ �Ѵ�.
	void Render_Begin(void);
	void Render_End(HWND hWnd = 0);

public: 
	//Level_Manager�� �ִ� �Լ����� ȣ���ϴ� ��������
	HRESULT Open_Level(_uint iLevelIndex, class CLevel* pNewLevel);
	HRESULT Render_Level();

public:
	//Object_Manager�� �ִ� �Լ����� ȣ���ϴ� ��������
	//�Լ� ���ڵ��̳� ���� ���۵��� Object_Manager�� ���������� Ȥ�� �𸣰����� �ѹ��� ������
	HRESULT Add_Prototype(const _tchar* pPrototypeTag, class CGameObject* pPrototype);
	HRESULT Add_GameObjectToLayer(const _tchar* pPrototypeTag, _uint iLevelIndex, const _tchar* pLayerTag, void* pArg = nullptr);

private:
	//Ŭ�������� �����ؼ� �Լ��� ȣ���ؾ��ϱ� ������ ��ü�� ������ �����ͺ����� ������.
	CGraphic_Device*				m_pGraphic_Device;
	CLevel_Manager*					m_pLevel_Manager;
	CObject_Manager*				m_pObject_Manager;

public:
	static void Release_Engine(); //�ſ� �߿��� cpp���� ����
	virtual void Free() override;
};

END