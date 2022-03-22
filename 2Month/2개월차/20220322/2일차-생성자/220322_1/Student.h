#pragma once

#include "Define.h"

class CStudent
{
private:
	INFO*		m_pInfo;
	int			m_iSize;

public:
	void		Initialize(void);
	void		Release(void);

public:
	void		Input_Data(void);
	void		Output_Data(void);

public:
	CStudent();					// ������ : ��ü�� �����Ǵ� ������ �ݵ�� ȣ��
	CStudent(int _iSize);		// �Ű����� �ִ� ������
	~CStudent();
};


// ��ü�� ������ �� ���������� �ڵ������Ǵ� �� ����

// default ������, �Ҹ���, default ���� ������, default ���� ������

// default �����ڴ� ���α׷��Ӱ� ���������� ������ �����ڰ� �� �Ѱ�� �����ϸ� ����, ȣ����� �ʴ´�.

// �Ҹ��ڸ� ���������� ���� ��� �ڵ� default �Ҹ��ڰ� ȣ��ȴ�.
// �Ҹ��ڴ� �ݵ�� �⺻Ÿ�� �ϳ� �ۿ� ����.(�����ε��� �Ұ���)

// ��ü ���������� ������ ����.
// 1. �޸� �Ҵ� -> 2. ������ ȣ��

// ��ü �Ҹ������ ������ ����.
// 1. �Ҹ��� ȣ�� 2. �޸� ��ȯ