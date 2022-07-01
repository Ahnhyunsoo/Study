#pragma once
#include "Engine_Defines.h" //�ۼ��� Engine_Defines������������ش�. CBaseŬ������
		//��� Ŭ������ ��ӹ޴� �ֻ��� �θ�Ŭ�����̱⶧���� CBase�� ��ӹ����� Engine_Defines�� ���ǵǾ��ִ°ų� �ٸ�����.

BEGIN(Engine)
//ENGINE_DLL = DLLŬ������ ���̺귯��ȭ ��Ű������ ��� ( Engine_Macro�� ���ǵǾ����� )
class ENGINE_DLL CBase abstract 		//��� Ŭ�������� ��ӹ޴� �ֻ��� �θ�Ŭ���� ���۷���ī��Ʈ�� �������� 
									//Free�� ���簡���Լ��̴� abstractŰ���带 �ٿ� �߻�Ŭ����ȭ ������.(���������Լ��� 1���� ������ �� Ŭ������ �߻�Ŭ����ȭ ���Ѿ��Ѵ�.)
									//�߻�Ŭ������ ��ü�� ������ �� ����.
{
protected: // ������ �����ڿ� �Ҹ��ڴ� Create�� ���ؼ� �����ϱ� ������ public���� �������� ����
	CBase();
	virtual ~CBase() = default;   // (= default) = {}�� ����
								//�� �ƹ���ɾ��� ��ü�� �����Ÿ� cpp�� �ۼ����� �ʰ� ����� = default�� ������
public:
	unsigned long AddRef(); //���۷��� ī��Ʈ�� ������Ű�� �Լ�
	unsigned long Release(); // ���ǿ� ���� ���۷��� ī��Ʈ�� ����, ���۷���ī��Ʈ�� ���� ��Ű�� �Լ�

protected:
	unsigned long dwRefCnt; //���۷��� ī��Ʈ�� �����ϴ� ����

public:
	virtual void Free() = 0; //Free�� ������ �帧�� �����ϱ����� �ڵ��̱� ������ ���������Լ��� �����.
							//�� ���������Լ��̱� ������ �ڽĿ��� �� ��ü�� ����������Ѵ�.

};

END

