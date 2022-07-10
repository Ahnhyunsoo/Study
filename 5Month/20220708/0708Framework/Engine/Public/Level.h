#pragma once
//�� Ŭ������ Ŭ���̾�Ʈ���� ������ ��� �������� �ݵ�� ��ӹ޾ƾ��ϴ� �θ�Ŭ������.
//�� Ŭ������ ��ӹ޴´ٴ°� �� Base�� ��ӹ޴��ǹ��̱� ������ Ŭ���̾�Ʈ�� �������� �� LevelŬ������ ��ӹ����� �ȴ�.
#include "Base.h"

BEGIN(Engine)
/*CBase���� ���������� �߿��ϴ� �ѹ��� ������
ENGINE_DLL�� ���̺귯��ȭ ��Ű�� ��ũ���̴�. Engine_Macro�� ���ǵǾ����� 
� Ŭ������ ��ũ��ȭ ��ų�� �Ǵ��� �� �־���Ѵ�.
���÷� CBaseŬ������ ENGINE_DLL�� ���� ���̺귯��ȭ ��������
Graphic_Device�� ���̺귯��ȭ ��Ű�� �ʾҴ�.
�� ������ Ŭ���̾�Ʈ���� Graphic_Device�� �ʱ�ȭ�κ��� ����� �ʿ䰡 ������? �翬�� ����.
�ݸ鿡 Ŭ���̾�Ʈ���� CBase�� �Լ����� ��� ����ϰ� �� CBase�� ��ӹ޾ƾ��ϱ� ������ ���̺귯��ȭ�� �ʼ���.
�� ������ ���� Device�ʱ�ȭ�Լ��� �ٸ� �Լ����� ���̺귯��ȭ ��Ű�� ���̺귯���� �ʹ� ��������� ������
���߿� �ۼ��� GameInstanceŬ������ �� �ʿ��� �Լ��鸸 ȣ���ϴ½����� ������ �� �� GameInstance�� ���̺귯��ȭ ��Ų��.
GameInstance���� �ѹ��� �������״� �ϴ� �������� �˰���.
*/
class ENGINE_DLL CLevel abstract : public CBase //CBase�� ��ӹ޴� �߻�Ŭ����
{
protected:
	CLevel(LPDIRECT3DDEVICE9 pGraphic_Device); //������ �� ��ġ�� ���ڷ� �־���
	virtual ~CLevel() = default;

public:
	virtual HRESULT Initialize(); //�ʱ�ȭ �Լ�
	virtual void Tick(_float fTimeDelta); //_float �𸣸� Engine_Struct Ȯ���ϰ� �������� _���� �ڷ��� �򰥸�������
											//API�� Update�� ������ �Լ��̴�. ��ü�� ���¸� �������ִ� �Լ�
											//���ڷ� �޴� fTimeDelta�� �ð����̴�. �� �ð����� ���� �����ֱ⸦ ������ �� �ִ�.
	virtual HRESULT Render();	//�׳� �����Լ� API���� �ٸ����� �ڵ��� �ƴ� ����̽��� �����ϱ⶧���� ���ڰ� ����.

protected:
	LPDIRECT3DDEVICE9 m_pGraphic_Device;

public:
	virtual void Free() override; //override = �θ��� �����Լ��� ������ �ߴٰ� �˷��ִ� Ű���� 
								//���� �Ⱦ��� ����� �Ȱ����� ������ �����Ѵٸ� ���� ������ ������.
};

END