#include "..\Public\Timer_Manager.h"
#include "Timer.h"

IMPLEMENT_SINGLETON(CTimer_Manager)

CTimer_Manager::CTimer_Manager()
{
}

_float CTimer_Manager::Get_TimeDelta(const _tchar * pTimerTag)
{
	CTimer*		pTimer = Find_Timer(pTimerTag); // ���ڷ� ���� Ÿ�̸� �˻�
	if (nullptr == pTimer)
		return 0.0f;

	return pTimer->Get_TimeDelta();	// �˻��� Ÿ�̸��� Ÿ�ӵ�Ÿ�� ����
}

HRESULT CTimer_Manager::Add_Timer(const _tchar * pTimerTag)
{
	if (nullptr != Find_Timer(pTimerTag)) //�˻��ؼ� ���� �ƴ϶�� �ش��±��� Ÿ�̸Ӱ� �̹� �����Ƿ� �Լ����� 
		return E_FAIL;

	CTimer*		pTimer = CTimer::Create();//���̶�� Ÿ�̸Ӹ� �������ش�.
	if (nullptr == pTimer)
		return E_FAIL;

	m_Timers.emplace(pTimerTag, pTimer); // �������� Ÿ�̸Ӹ� �ʿ� �߰�

	return S_OK;
}

HRESULT CTimer_Manager::Update_Timer(const _tchar * pTimerTag)
{
	CTimer*		pTimer = Find_Timer(pTimerTag);
	if (nullptr == pTimer)
		return E_FAIL;

	pTimer->Update();	//�˻��� Ÿ�̸��� ������Ʈ�� ȣ��

	return S_OK;
}

CTimer * CTimer_Manager::Find_Timer(const _tchar * pTimerTag)
{
	auto	iter = find_if(m_Timers.begin(), m_Timers.end(), CTag_Finder(pTimerTag)); // �±׷� �ʿ��� Ÿ�̸Ӹ� �˻�

	if (iter == m_Timers.end())
		return nullptr;

	return iter->second;
}

void CTimer_Manager::Free()
{
	for (auto& Pair : m_Timers)
		Safe_Release(Pair.second);

	m_Timers.clear();
}
