#include "stdafx.h"

// �Լ� ���ø�
template<typename T>
bool	 Less(T Left, T Right)
{
	return Left < Right;
}

template<typename T>
bool	 Greater(T Left, T Right)
{
	return Left > Right;
}

template<typename T>
bool	IsOddNum(T Number)
{
	if (0 != Number % 2)
		return true;

	return false;
}


void main(void)
{
	// �ݺ����� ����

	// 1. ��� �ݺ��� 2. �Է� �ݺ��� 3. ������ �ݺ��� 4. ����� �ݺ��� 5. ���� ���� �ݺ���

	/*vector<int>		vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);

	vector<int>::iterator		iter = vecInt.begin();

	iter += 3;		// ���� ���� �ݺ����̱� ������ �����ϴ�.

	// vecInt.insert(iter, 60000);	// �߰� ���� �Լ�
	// iter = vecInt.erase(iter);		// ���� �Լ�

	cout << (*iter) << endl;*/

	/*for( iter = vecInt.begin(); iter != vecInt.end(); ++iter)
		cout << (*iter) << endl;*/


/*
	list<int>		ListInt;

	ListInt.push_back(10);
	ListInt.push_back(20);
	ListInt.push_back(30);
	ListInt.push_back(40);
	ListInt.push_back(50);

	list<int>::iterator		iter = ListInt.begin();

	iter += 3;		// ����� �ݺ����̱� ������ ����� �Ұ����ϴ�.

	cout << (*iter) << endl;*/


#pragma region �޸� Ȯ���� ���� vector�� �Լ���

	/*vector<int>		vecTemp;

	for (size_t i = 0; i < 10; ++i)
	{
		cout << "Size : " << vecTemp.size() << "\tCapacity : " << vecTemp.capacity() << endl;
		vecTemp.push_back(10);		
	}*/
	
	/*vector<int>		vecInt(10);		// ���� ������ ���� ���� 0���� �ʱ�ȭ�� ���·� ������� ī�Ľ�Ƽ�� �̸� 10�� ������ִ� ����
									// ���� 10�� �̻��� �߻��ϴ� ���� �ٽ� ī�Ľ�Ƽ ��å�� ���� ���Ҵ��� ���۵ȴ�.
	
	cout << "Size : " << vecInt.size() << "\tCapacity : " << vecInt.capacity() << endl;
	
	//vecInt.push_back(10);
	
	vecInt.resize(20);		// ������ ������ �ٽ� �����ϴ� �Լ�, ��, �̹� Ȯ���� �޸� ������ �پ���� �ʴ´�.
	cout << "Size : " << vecInt.size() << "\tCapacity : " << vecInt.capacity() << endl;*/


	/*vector<int>		vecInt;
	vecInt.reserve(10);	// ���� ���� ���� ���� ������ �޸� ������ �̸� Ȯ���ϴ� �Լ�
	cout << "Size : " << vecInt.size() << "\tCapacity : " << vecInt.capacity() << endl;
*/



#pragma endregion �޸� Ȯ���� ���� vector�� �Լ���

#pragma region �˰���� ������

	// ������ : bool Ÿ���� ��ȯ�ϴ� �Լ� �Ǵ� �Լ� ��ü�� stl �˰����� �����ϱ� ���� ������ �����ϴ� ����� �ǹ��Ѵ�.

	//int	iArray[5] = { 3, 4, 1 , 5, 2 };

	/*sort(iArray, iArray + 5, Less<int>);

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << endl;*/

	// count_if : �����̳� ���Ҹ� ��ȸ�ϸ鼭 �������� ��ȯ ����� true�϶��� ������ ��ȯ�ϴ� �Լ� ���ø�
	//int	iCount = count_if(iArray, iArray + 5, IsOddNum<int>);

	//cout << iCount << endl;

	//find("jusin");

	//find_if();

#pragma endregion �˰���� ������
}