// 220408.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


class CTag_Finder
{
private:
	char*		m_pTag;

public:
	CTag_Finder(char* pTag)
		: m_pTag(pTag) {	}

public:
	template<typename T>
	bool	operator()(T& Pair)
	{
		if (!strcmp(Pair.first, m_pTag))
			return true;

		return false;
	}
};

int main()
{
	// map : ���� �����̳�(�� ������), �ڰ� ���� ���� Ž�� Ʈ��(����-�� Ʈ��)�� ����
	// ���� ��ȸ ������� ���ҵ��� �����ϴ� Ʈ�� ������ �����̳�

	// Ž���� ������ �����̳��̱� ������ : ���ҽ� Ž��

	// Ư¡
	// 1. map�� key, value��� �� ���� �����͸� ���ҷ� ��´�.
	// 2. map�� key �� �������� �ڵ� ������ �Ͼ��.����� ����, ������ �߻��� ��� �ӵ��� �ſ� ������.
	// 3. map�� key ���� ���� ������ �Ǿ��ֱ� ������ �ݺ��ڸ� ���� Ž���� �����ϴ�.
	// 4. map�� ��� ��� �����̳� �� �����ϰ�[]�����ڰ� �����ε� �Ǿ� �־� 'key������' ���� ������ �����ϴ�.
	// 5. map�� ����� �ݺ��ڸ� ���� �ִ�.
	// 6. map�� �ߺ� key ���� ������� �ʴ´�.

#pragma region map �����̳��� �⺻ ����

	//map<key���� �ڷ���, value���� �ڷ���, ������>

	//map<int, int>		MapInt;
	//map<char*, CObj*>
	//map<string, list<CObj*>>

	// pair��ü : �� ���� �̷�� ���Ҹ� ���ø�ȭ �Ͽ� ������ �� �ִ� �������� ����� ��

	// Ŭ���� ���ø�

	// 1. pair ��ü�� ���� ���Ҹ� �����ϴ� ���
	//pair<int, int>		MyPair;
	// ���ҿ� �����Ͽ� �� ���� ����, ���� �ϰ� �ʱ�ȭ���� �ʴ´ٸ� �ڵ� 0 �ʱ�ȭ
	/*
	MyPair.first = 2;
	MyPair.second = 200;*/

	//MapInt.insert(MyPair);		// Ű���� �ش��ϴ� ��尡 �������� �ʴ´ٸ� �ش� Ű�� value�� ������ ��带 �����Ͽ� �����ϴ� �Լ�

	// 2. �ӽ� pair ��ü�� ���� ���Ҹ� �����ϴ� ���
	//MapInt.insert(pair<int, int>(1, 100));

	// 3. []�����ڸ� ���� ���� ����
	//MapInt[2] = 200;			// �ش� �ε��� ���� ��尡 ���� ��� ��带 �����Ͽ� value�� ���� ����
								// �ش� �ε��� ���� ��尡 �ִ� ��� value ���� ������ ����

	// 4. make_pair�Լ��� �̿��Ͽ� ���Ҹ� �����ϴ� ���(pair ��ü�� ���� �����ϴ� �ͺ��� �۵��ӵ��� ��������)
	//MapInt.insert(make_pair(3, 300));

	// 5. ������ ������ ���� ���� value_type�� �̿��Ͽ� ���Ҹ� �����ϴ� ���
	//map<int, int>::value_type	MyMap(4, 400);	// namespace�� ���ǵǾ� �־ ::������ ����ؾ� ��, ���� �ϰ� �ʱ�ȭ���� ���� ��� �ڵ� 0���� �ʱ�ȭ�ȴ�.
	//MapInt.insert(MyMap);

	// MyMap.first = 5;			key���� �ڵ� const�� ����
	// MyMap.second = 500;		value�� ���� ����

	// 6. value_type �ӽ� ��ü�� �̿��Ͽ� ���Ҹ� �����ϴ� ���
	//MapInt.insert(map<int, int>::value_type(5, 500));

	// 7. c++11���� �߻��� emplace �Լ��� �̿��� ���� ���� ���
	//MapInt.emplace(6, 600);

	// 8. c++11���� �߻��� ������ �ʱ�ȭ�� �̿��� ���� ���� ���
	//MapInt.insert({7, 700});

	/*map<int, int>::iterator		iter = MapInt.begin();

	for( ; iter != MapInt.end(); ++iter)
		cout << "key �� ��� : " << iter->first <<"\tvalue �� ��� : " << iter->second << endl;*/

#pragma endregion map �����̳��� �⺻ ����

#pragma region map �����̳��� ���� ��� �Լ�

		// size(), clear(), empty(), begin(), end()

	/*map<int, int, greater<int>>		MapInt;

	MapInt.insert({ 1, 100 });
	MapInt.insert({ 2, 200 });
	MapInt.insert({ 3, 300 });
	MapInt.insert({ 4, 400 });
	MapInt.insert({ 5, 500 });

	map<int, int>::iterator		iter = MapInt.begin();*/

	// iter += 3;		// map �����̳ʴ� ���� ������ �Ұ����� ����� �ݺ��ڸ� ���� �ִ�.

	//++iter;
	//++iter;

	//MapInt.insert(iter, { 6, 600 });		// map�� �ڵ������� �Ͼ�� ������ �߰� ������ �ϴ��� ū �ǹ̰� ����.
											// �߰� �����ص� �ݺ����� ��ȿȭ�� �Ͼ�� �ʾ� �߰� ������ �ǹ̰� ����.												

	// iter = MapInt.erase(iter);				// erase�� ���� ���� �ÿ��� �ݺ����� ��ȿȭ�� �Ͼ�� ������ �ݵ�� ���� �ݺ��ڸ� ��ȯ���ְų� begin ��ġ�� �ʱ�ȭ �ؾ��Ѵ�.
	// cout << iter->first << "\t" << iter->second << endl;

	/*for(iter = MapInt.begin(); iter != MapInt.end(); ++iter)
		cout << iter->first << "\t" << iter->second << endl;*/


#pragma endregion map �����̳��� ���� ��� �Լ�

#pragma region map �����̳��� Ű�� ���ڿ�

		/*
		map<char*, int>		MapChar;

		MapChar.insert({ "AAA", 100 });
		MapChar.insert({ "BBB", 200 });
		MapChar.insert({ "CCC", 300 });

		map<char*, int>::iterator		iter = MapChar.begin();

		/ *for (iter = MapChar.begin(); iter != MapChar.end(); ++iter)
		cout << iter->first << "\t" << iter->second << endl;* /

		// iter = MapChar.find("AAA");	// 0x16 , 0x27

		iter = find_if(MapChar.begin(), MapChar.end(), CTag_Finder("AAA"));

		// ��Ƽ ������ ����� ���α׷���, dll����� ���� ������Ʈ
		cout << iter->first << "\t" << iter->second << endl;*/

// ���ڿ��� Ű ���� �� ������ ��� �Ǵ°�
/*
1. key ���� char ���� ��� �ƽ�Ű�ڵ� ��, �� ���ĺ� ������ ������ �Ͼ��.
2. key ���� char* ���� ��� 16���� �ּ�(���� ��) �������� ������ �Ͼ��.
3. key �� ������ ���ڿ� �������� �ϰ��� �Ѵٸ� char* ���� �ƴ϶� string�� ����ؾ� �Ѵ�.(string �����̳ʴ� ���������� ���ڿ� ��Һ� ����� �����ε� �Ǿ�����)
4. char* ���� ���� �����ϰ� �ʹٸ� �����ڸ� ���� ���� �� �Լ��� ������ �Ѵ�.*/

#pragma endregion map �����̳��� Ű�� ���ڿ�

	return 0;
}

