// 220412.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Temp.h"
#include "Test.h"

#pragma region R-Value ���۷���
/*
void	Add(int&& a, int&& b)
{
	//a += 10;
	//b += 20;

	// cout << a << "\t" << b << endl;

	//Add(a, b);	// ���ѷ���
}

int main()
{


	// L - value : �����ڸ� �������� ����, ������ ��� ������ �� �ִ� ��
	// R - value : �����ڸ� �������� �����ʿ��� ������ �� �ִ� ��

	// ������ ���� ����� �ּ�ȭ �ϱ� ���� ���� ����ϴ� ����


	// int	iTemp = 10;
	// int	iDest = iTemp;

	// ex) iTemp �� ���� ������ �������� ����, ������ ��� ��ġ�� �� �ֱ� ������ l-value�� �ݸ�,
	// ���� 10�� �����ʿ��� ���� �� �ֱ� ������ r-value��� �Ѵ�.

	//int		iTemp = 20;

	//const int&	r = 10;		// �Ϲ����� ���۷����� l-value�� ������ �� �ִ�.
	
	//int&& r2 = 10;		// R-value�� ���� �ּҰ� ���� ����
	//r2 = iTemp;			// R-value ���۷��� �ڷ����� l-value �� ���Ե� ����

	//r = 20;

	//cout << r2 << endl;

	//int iA = 10;
	//int	iB = 20;

	//Add(iA, iB);
	//Add(10, 20);

#pragma endregion R-Value ���۷���
    return 0;


}*/

#pragma region �̵� ������

/*
class CObj
{
public:
	CObj() : m_pArray(nullptr), m_iSize(0) 
	{
	}
	CObj(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) 
	{
	}

	CObj(CObj& rObj)
	{
		m_pArray = new int[rObj.m_iSize];
		memcpy(m_pArray, rObj.m_pArray, sizeof(int) * rObj.m_iSize);
		m_iSize = rObj.m_iSize;
	}

	// �̵� ������
	CObj(CObj&& rObj)
	{
		m_pArray = rObj.m_pArray;		// ������ ����
		m_iSize = rObj.m_iSize;

		// ������ ���� ���� ��۸� �����Ͱ� ���� �ʵ��� null�� �ʱ�ȭ
		rObj.m_pArray = nullptr;
	}

	~CObj()
	{
		if (m_pArray)
		{
			delete[]m_pArray;
			m_pArray = nullptr;
		}		
	}

private:
	int*			m_pArray;
	int				m_iSize;
};

void main(void)
{
	/ *CObj		Obj(100000000);

	DWORD		dwTime = GetTickCount();

	//CObj		Temp(Obj);

	CObj		Temp(std::move(Obj));

	//std::move : �Ű������� ���޹��� ����� R-Value ���۷����� ĳ�������ִ� �Լ�
	//move �Լ��� ����Ͽ� �̵������ڸ� ȣ���� �� �ƴϸ� ���� �����ڸ� ȣ������ �����ϰ� ��

	cout << (GetTickCount() - dwTime) << endl;* /

	//vector<CObj>		vec;
	//vec.push_back(CObj(100000000));

	// 1. �ӽ� ��ü ���� �� �Ҵ�
	// 2. �Ҵ� �������� ���� ��� �Ҵ�
	// 3. ���� ���� ������ ȣ��, ���� ���� ��, 1�￡ �ش��ϴ� ������ ���� ��� �Ҹ�
	// 4. ���� ���� �� �ӽ� ��ü �Ҹ��� ȣ��
	// 5. �ӽ� ��ü ��� ����
	// 6. �ӽ� ��ü �Ҹ�
	
	//vec.push_back(std::move(CObj(100000000)));

	// 1. �ӽ� ��ü�� �Ҵ�
	// 2. �Ҵ� �������� ���� ��� �Ҵ�
	// 3. �̵������ڸ� ���� ������ ����(1�� �׸��� �ּҸ� �̵�)
	// 4. ������ ���� ��, �ӽ� ��ü �Ҹ��� ȣ��
	// 5. �ӽ� ��ü �Ҹ�


#pragma region ���Ϳ� ���� ���� �̵�


	vector<int>		vec1(100000000);

	DWORD	dwTime = GetTickCount();

	cout << "vec1.capacity  : " << vec1.capacity() << endl;

	vector<int> vec2 = std::move(vec1);
	cout << "vec2.capacity  : " << vec2.capacity() << endl;
	cout << "�ð� : " << (GetTickCount() - dwTime) << endl;
	

#pragma endregion ���Ϳ� ���� ���� �̵�


}*/

#pragma endregion �̵� ������

int		g_iNum = 100;

void main()
{
	//Add();
	//cout << g_iNum << endl;

	//CTest	Test;

	//Test.Render();
	//Test.Render();
	//Test.Render();

	//cout << CTest::m_iTest << endl;

	CTest::Print();
}

