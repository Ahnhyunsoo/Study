#pragma once
/*
Ư�� �������� ���Ǵ� ������Ʈ���� �����ϴ� Ŭ����
�����ϰ� �ִ� ��ü���� �۾��� ��������ش�.
���� �κ� ����� �����ϴ� �����ؼ� ���� �ٶ��ϴ�!
*/
#include "Base.h"

BEGIN(Engine)

class CObject_Manager final : public CBase
{
	DECLARE_SINGLETON(CObject_Manager)
private:
	CObject_Manager();
	virtual ~CObject_Manager() = default;

public:
	HRESULT Reserve_Container(_uint iNumLevels); //�纻��ü�� ������ map�� �迭�� �������ִ� �Լ� ���ڷ� ������ ������ �޴´�.
	
	HRESULT Add_Prototype(const _tchar* pPrototypeTag, class CGameObject* pPrototype); 
	//������ü�� map�����̳ʿ� �߰����ִ� �Լ�
	//1���� = map�����̳ʿ� ������ �±�(���ڿ�key��), 2���� = ������ ������ü

	HRESULT Add_GameObjectToLayer(const _tchar* pPrototypeTag, _uint iLevelIndex, const _tchar* pLayerTag, void* pArg = nullptr);
	//�纻��ü�� map�����̳ʿ� �������ִ� �Լ�
	//1���� = ������ü�� �±�(���ڿ�key��), 2���� : ���������, 3���� : �纻��ü�� ������ �±�(���ڿ�key��), 4���� = ������ü�� ������� ������

public:
	void Tick(_float fTimeDelta); //�纻��ü���� Tick�� ȣ���ϴ��Լ�
	void LateTick(_float fTimeDelta); //�纻��ü���� LateTIck�� ȣ���ϴ��Լ�
	void Clear(_uint iLevelIndex); //���ڷ� ���� ������ ��ü���� �������ִ� �Լ�

private: 
	map<const _tchar*, class CGameObject*>			m_Prototypes; //���� ��ü�� ������ map�����̳�
	typedef map<const _tchar*, class CGameObject*>	PROTOTYPES; //typedef�� ���� ������


private: 
	_uint											m_iNumLevels; //������ ����
	map<const _tchar*, class CLayer*>*				m_pLayers; //�纻 ��ü�� ������ map�����̳�
	/*���⼭ *>*���� ���� �Ҽ��� �ִµ� �����غ��� �����ϴ�. 
	�׳� map�����̳��� �������̴�. �� map�����̳��� �����͸� �ɹ��� �����ұ�?
	�����迭�� �����߱� �����̴�.
	�������� ���̾ �����ϰ� ������ �ʿ��� ������ ���̾�� �����ϱ� ������
	������ ������ ���� �迭�� ũ�⵵ ����Ǿ�� �ϴµ� �����迭�� �ƴ� �Ϲݹ迭�� �����ϸ� �迭�� ũ�⸦
	������ �� ���� ������ ������ ������ ���� �迭�� ũ�⸦ �����ϱ� ���� �����迭�� �����Ѵ�.
	�����迭�� �𸣸�... C++�� ��������
	*/
	typedef map<const _tchar*, class CLayer*>		LAYERS; //typedef�� ���� ������

private:
	class CGameObject* Find_Prototype(const _tchar* pPrototypeTag); //���ڷι��� �±׸� ���� ������ü�� �˻�
	class CLayer* Find_Layer(_uint iLevelIndex, const _tchar* pLayerTag); //���ڸ� ���� ���̾ �����ϴ��� �˻�

public:
	virtual void Free() override;
};

END