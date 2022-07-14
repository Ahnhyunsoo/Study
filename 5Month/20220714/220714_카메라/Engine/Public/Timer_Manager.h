#pragma once

#include "Timer.h"

BEGIN(Engine)

class CTimer_Manager final : public CBase
{
	DECLARE_SINGLETON(CTimer_Manager);
private:
	CTimer_Manager();
	virtual ~CTimer_Manager() = default;

public:
	_float Get_TimeDelta(const _tchar* pTimerTag); // 타임델타 가져오는 함수

public:
	HRESULT Add_Timer(const _tchar* pTimerTag); // 타이머 생성함수
	HRESULT Update_Timer(const _tchar* pTimerTag); // 타이머 업데이트

private:
	map<const _tchar*, class CTimer*>			m_Timers; //타이머가 여러개일수도있으니 맵에 저장
	typedef map<const _tchar*, class CTimer*>	TIMERS;

private:
	class CTimer* Find_Timer(const _tchar* pTimerTag); // 타이머를 검색해주는 함수

public:	
	virtual void Free() override;
};

END