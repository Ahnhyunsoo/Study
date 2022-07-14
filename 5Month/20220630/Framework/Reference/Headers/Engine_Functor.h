#pragma once

namespace Engine
{
	//�Լ���ü���� �����Ѵ�. �Լ���ü�� �ӽð�ü�� �����ؼ� ��ü�� �Լ�ó�� ����ϴ¹��� �߿��ϴ� �𸣸� C++�����ϱ�
	class CTag_Finder //
	{
	private:
		const wchar_t* m_pStr;//���ڿ��� �����ϴº���

	public:
		CTag_Finder(const wchar_t* pStr)//���������ڷ� ���� ���ڿ��� ���� m_pStr�� ����
			: m_pStr(pStr)
		{

		}

	public:
		template<typename T>
		bool operator()(T& Pair)//������ �����ε� ()�� �����ε��� 
		{	//strcmp�� ������ false����ȯ �ٸ��� true�� �������� (���� ���������� �ణ �ٸ��� �����Ѵ�. �ñ��ϸ� ���۸�)
			if (!lstrcmp(m_pStr, Pair.first)) //��ü(Pair)�� ȣ������ �� �ӽð�ü �������� �� ���ڷ� �־��� �±׿�
				return true;	//()���ڷ� ���� pair�� first�� ���ؼ� ������ ��������

			return false;
		}
	};
}