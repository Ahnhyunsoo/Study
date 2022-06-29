#pragma once
#include "Client_Defines.h"
#include "Base.h"

BEGIN(Engine)
class CGameInstance;
END

BEGIN(Client)

class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Initialize(); //�ʱ�ȭ�۾�
	void Tick(_float fTimeDelta); // API�� ������Ʈ�� �����ϴ�. ���ڷι��� ��ŸŸ�ӿ� ���� Update�� ���ش�.
	HRESULT Render();  //�����Լ� ����̽��� ���� �������Ѵ�.

private:
	CGameInstance* m_pGameInstance = nullptr; //�����ν��Ͻ� Ŭ������ ��ü�����͸� ������ �����ͺ���

private:
	LPDIRECT3DDEVICE9		m_pGraphic_Device = nullptr; //����̽���ü�� ������ ���� LPDIRECT3DDEVICE9�� �����������̴�.

private:
	HRESULT Open_Level(LEVEL eLevelID); //���� enum���� ���ڷ� �޾Ƽ� LevelManager�� Open_Level�Լ��� ��������ֱ����� �Լ�

public:
	static CMainApp* Create(); // Create�Լ� API���ʹ� �ٸ��� new�� ��ü�� ���������ʰ� �� �����Լ��� Create�� �̿��� �����Ѵ�.
	virtual void Free(); //�����Լ� �θ�Ŭ������ BaseŬ�������� ���������Լ��̱⶧���� �ݵ�� ���Ǻθ� ����������Ѵ�.
};

END
