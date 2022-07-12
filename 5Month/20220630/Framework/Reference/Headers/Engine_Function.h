#pragma once
namespace Engine
{
	//���ø� �𸣸� C++�����ϱ�
	//���ø� �Լ��� �����. 
	template<typename T>
	void Safe_Delete(T& Temp)
	{
		if (Temp)
		{
			delete Temp; //���ڷ� ���� �����Ͱ� ����Ű�� ��ü�� ��������
			Temp = nullptr; //��۸� ������ ���ؼ� ���ڷ� ���� �����͸� �������ͷ� �ʱ�ȭ����
		}
	}
	//���� ���� �迭�� ��������
	template<typename T>
	void Safe_Delete_Array(T& Temp)
	{
		if (Temp)
		{
			delete[] Temp;
			Temp = nullptr;
		}
	}
	//���۷��� ī��Ʈ�� ������Ű������ ���ø��Լ�
	template<typename T>
	unsigned long Safe_AddRef(T& Temp)
	{
		unsigned long dwRefCnt = 0; //���ڷι��� ��ü�� AddRef���ϰ��� �����ϱ����� ������ ������.
		if (Temp != nullptr) //���� ���ڷι��� �����Ͱ� nullptr�� �ƴ϶��
		{
			dwRefCnt = Temp->AddRef(); //���ڷι��� ��ü�� AddRef�Լ��� �����ϰ� �� ������� �����ص� dwRefCnt������ ����
		}
		return dwRefCnt; //������ ���� dwRefCnt�� ��������
	}
	//���۷��� ī��Ʈ�� ���ҽ�Ű�� ���� ���ø��Լ�
	template<typename T>
	unsigned long Safe_Release(T& Temp)
	{
		unsigned long dwRefCnt = 0; //AddRef�� ���� �帧
		if (Temp != nullptr)
		{
			dwRefCnt = Temp->Release(); //���ڷι��� ��ü�� Release�� ȣ���� �� ������ ����
			Temp = nullptr; //nullptr�� ���ִ� ������ Release�� ȣ��� ������ 
			//ȣ���� ��ü�� �����ϴ� �����̱� �����̴�.
			//�� ���̻� ȣ���� ��ü���� ������ ���� �ʱ� ������ ��۸� ������ ���� nullptr�� �ʱ�ȭ���ش�.
		}
		return dwRefCnt;	//������ ���۷���ī��Ʈ�� ����
	}
}