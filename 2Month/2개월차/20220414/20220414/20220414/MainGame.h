#pragma once
#include "include.h"
class CMainGame
{
public: //������ �Ҹ��ڴ� ������
	CMainGame();
	~CMainGame();

public:
	void Initialize(void); //�ʱ�ȭ �Լ�
	void Update(void);	//�� �����Ӹ��� ���ŵǴ� �����͸� ����� �Լ�
	void Render(void);	//�� �����Ӹ��� ����ϴ� �Լ�
	void Release(void);	//�����Ҵ��� �����͸� �����ϴ� �Լ�
};

//public,protected,private �Լ�

//public,protected,private ����

