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
	_float Get_TimeDelta(const _tchar* pTimerTag); // Ÿ�ӵ�Ÿ �������� �Լ�

public:
	HRESULT Add_Timer(const _tchar* pTimerTag); // Ÿ�̸� �����Լ�
	HRESULT Update_Timer(const _tchar* pTimerTag); // Ÿ�̸� ������Ʈ

private:
	map<const _tchar*, class CTimer*>			m_Timers; //Ÿ�̸Ӱ� �������ϼ��������� �ʿ� ����
	typedef map<const _tchar*, class CTimer*>	TIMERS;

private:
	class CTimer* Find_Timer(const _tchar* pTimerTag); // Ÿ�̸Ӹ� �˻����ִ� �Լ�

public:	
	virtual void Free() override;
};

END