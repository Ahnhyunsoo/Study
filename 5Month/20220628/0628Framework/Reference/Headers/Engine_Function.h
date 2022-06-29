#pragma once
namespace Engine
{
	template<typename T> //���ø� �Լ�
	void Safe_Delete(T& Temp) // ��ü�� �������ִ� �Լ� ��ü������ �������ͷ� ä���ش�.(��۸�����)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}

	template<typename T>
	void Safe_Delete_Array(T& Temp) // �迭��ü�� �������ִ� ���ø��Լ�
	{
		if (Temp)
		{
			delete[] Temp;
			Temp = nullptr;
		}
	}

	template<typename T> 
	unsigned long Safe_AddRef(T& Temp) // ���۷��� ī���͸� �÷��ִ� ���ø��Լ�
	{
		unsigned long dwRefCnt = 0;
		if (Temp != nullptr) // ��ü�� nullptr�� �ƴ϶��
		{
			dwRefCnt = Temp->AddRef(); // �ش簴ü�� AddRef�Լ��� �����ϰ� ���� ���ϰ��� dwRefCnt�� ����
		}
		return dwRefCnt;		// �׸��� �������ش�.	
	}

	template<typename T>
	unsigned long Safe_Release(T& Temp)
	{
		unsigned long dwRefCnt = 0;
		if (Temp != nullptr)
		{
			dwRefCnt = Temp->Release();
			Temp = nullptr;
		}

			return dwRefCnt;
		
	}
}