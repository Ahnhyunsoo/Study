// 20220406.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//�Ʊ�� �Լ� ��ü

//�Լ� ���ø�

template <typename T>
bool Num(T num)
{
	if (0 != num % 2)
		return true;

	return false;
}

template<typename T>
bool Less(T left, T right)
{
	return left < right;
}

int main()
{
#pragma region �޸� Ȯ���� ���� vector�� �Լ���

	//vector<int> vecTemp;
	////vecTemp.resize(50);
	////resize(); ������ ������ �ٽ� �����ϴ� �Լ�, ��, �̹� Ȯ���� �޸� ������ �پ���� �ʴ´�.

	//vecTemp.push_back(10);
	//vecTemp.push_back(20);
	//vecTemp.push_back(30);
	//vecTemp.push_back(40);

	//vecTemp.reserve(10); // ������ �޸� ������ �̸� �������ִ� �Լ� ������� ���ؾ��Ѵ�. ���Ҵ��ϸ� �ӵ��� ���� �پ���.
	////�̸� ������ ��Ƶδ°��� ���Ҵ��ϴ°ͺ��� �ν� ������.


	//cout << "Size : " << vecTemp.size() << "\tCapacity : " << vecTemp.capacity() << endl;


#pragma endregion �޸� Ȯ���� ���� vector�� �Լ���



#pragma region �˰���� ������

	// ������ : bool Ÿ���� ��ȯ�ϴ� �Լ� �Ǵ� �Լ� ��ü�� stl �˰����� �����ϱ� ���� ����

	//int iArray[5] = { 3, 4 , 1 , 5 , 2 };
	
	//sort(iArray, iArray + 5, Less<int>); // sort��� �˰����� ����Ʈ�����ڰ� ���������̴�.

	/*for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << endl;
	}*/
	//count_if �����̳� ���Ҹ� ��ȸ�ϸ鼭 �������� ��ȯ ����� true�� �� ������ ��ȯ�ϴ� �Լ�
	//int iCount = count_if(iArray, iArray + 5, Num<int>);
	//cout << iCount << endl;

	//�˰���( ���� ���� ������)
	find();
	<char*, >
		"jusin" = ���ڿ� ��� 
		����޸𸮿� �ö󰡰�
		ĳ���������Ϳ� �� ����޸��� �ּڰ��� �־��ִ°��̴�
	find_if();

#pragma endregion �˰���� ������

    return 0;
}

//���� : �κ��丮 ũ��� 5ĭ
//���͸� �̿��� �ؽ�Ʈ������ ����

/*		vec.begin(),vec.end(), �Լ��� �Լ���ü�� �����ڿ����ε��� ���� �ܺε����͸� ������ �� �ִ�.(�׸��� �Լ���ü�� �޸��Ҵ��� �ƴ� �ӽø޸��̱� ������ �ӵ��� ������).
for_each(������,������,�Լ�������or�Լ���ü)

erase ���ۿ���
iterator�� �̿��� �����ڸ� for each�� �ٲ㺸�� �˰��� ���� ������

�ݺ����� ����
1. ��� �ݺ��� 2. �Է� �ݺ��� 3. ������ �ݺ��� 4. ����� �ݺ��� 5. ���� ���� �ݺ���
����� �ݺ���, ���� ���� �ݺ��� �ַ� �����
1~5������ ������ ������ 5���� ���� ���� �ݺ���
�������� �ݺ��ڸ� ����ϴ� �����̳� = ���� ��ũ
����Ʈ���� �����̳ʵ��� ����� �ݺ��ڸ� ����Ѵ�.

insert�Լ� �߰��� �������ִ� �Լ�
vec.insert(iter, data);
insert�ÿ� ���� ũ�Ⱑ ������ �� ���Ҵ�� ���ҵ��� ���ġ�� �Ͼ�� ������ ����Ʈ�� ���ؼ� ���ո����̴�.
iterator �� ���Ҹ� ����Ű�� ���� ��ü
iterator�� �������� ��ü��
iterator�� �ּҿ� iterator�� ���� ���� �ٸ���.
iterator�� �޸𸮸� ����Ű�°� �ƴ� ���Ҹ� ����Ű�°��̴�.







*/



