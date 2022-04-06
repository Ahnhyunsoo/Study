#pragma once

#include "Define.h"

class CStudent
{
private:
	INFO		m_tInfo;

public:
	const INFO&		Get_Info(void)const { return m_tInfo; }

public:
	void		Input_Data(void);
	void		Output_Data(void);

public:
	CStudent();
	~CStudent();
};

