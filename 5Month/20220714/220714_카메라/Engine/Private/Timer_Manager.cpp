#include "..\Public\Timer_Manager.h"
#include "Timer.h"

IMPLEMENT_SINGLETON(CTimer_Manager)

CTimer_Manager::CTimer_Manager()
{
}

_float CTimer_Manager::Get_TimeDelta(const _tchar * pTimerTag)
{
	CTimer*		pTimer = Find_Timer(pTimerTag); // 인자로 들어온 타이머 검색
	if (nullptr == pTimer)
		return 0.0f;

	return pTimer->Get_TimeDelta();	// 검색한 타이머의 타임델타를 리턴
}

HRESULT CTimer_Manager::Add_Timer(const _tchar * pTimerTag)
{
	if (nullptr != Find_Timer(pTimerTag)) //검색해서 널이 아니라면 해당태그의 타이머가 이미 있으므로 함수종료 
		return E_FAIL;

	CTimer*		pTimer = CTimer::Create();//널이라면 타이머를 생성해준다.
	if (nullptr == pTimer)
		return E_FAIL;

	m_Timers.emplace(pTimerTag, pTimer); // 생성해준 타이머를 맵에 추가

	return S_OK;
}

HRESULT CTimer_Manager::Update_Timer(const _tchar * pTimerTag)
{
	CTimer*		pTimer = Find_Timer(pTimerTag);
	if (nullptr == pTimer)
		return E_FAIL;

	pTimer->Update();	//검색한 타이머의 업데이트를 호출

	return S_OK;
}

CTimer * CTimer_Manager::Find_Timer(const _tchar * pTimerTag)
{
	auto	iter = find_if(m_Timers.begin(), m_Timers.end(), CTag_Finder(pTimerTag)); // 태그로 맵에서 타이머를 검색

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
