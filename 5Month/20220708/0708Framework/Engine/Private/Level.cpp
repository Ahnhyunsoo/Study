#include "..\Public\Level.h"



CLevel::CLevel(LPDIRECT3DDEVICE9 pGraphic_Device)
	:m_pGraphic_Device(pGraphic_Device)
{	
	Safe_AddRef(m_pGraphic_Device); //Graphic_DeviceŬ������ �����ϰ� �������� ���۷���ī��Ʈ�� ���������ش�.
	//���⼭ ������? 
	//������ ������ ���� �ٸ� ��ü�� �����ϴ� ������ ������� �Ѵ�.
	//�� ������ ������ �ٸ� ��ü�ּҸ� �����ϸ� �̰� �����ϴ°��̴�. ������ �����ϸ� ���۷��� ī��Ʈ�� �������Ѿ��Ѵ�.
	//�̱����� Get_Instance�� ���� ������ ��ü�ּҸ� �����ϴ°��� �ƴ� ��븸 �ϴ°��̱� ������ 
	//���� ���۷��� ī��Ʈ�� ������Ű�� �ʾƵ� �ȴ�.
	//��������� ������ �ٸ���ü�� �ּҸ� "����"��Ű�� ������°� ���ϰ� �;���...
}

HRESULT CLevel::Initialize()
{
	return S_OK;
}

void CLevel::Tick(_float fTimeDelta)
{
}

HRESULT CLevel::Render()
{
	return S_OK;
}

void CLevel::Free()
{
	Safe_Release(m_pGraphic_Device); //�����ߴ� ��ü�� ���۷���ī��Ʈ�� ���ҽ����ش�.
}
	
