#include "stdafx.h"

void main(void)
{

	// list �����̳�
	
	// �������� ������ ���� ����
	// ��� ����� �����̳� ������ ���� ����

	// vector�� ������

	// �迭 ���(���� ������ ������ �ݺ��� ���) vs ��� ���(����� ������ �ݺ��� ���)
	// Ž���� ���� vs �߰� ���� ������ ����
	
	// �߰� ���� ���� ��, ���ʹ� �迭�� Ư���� �޸� ���Ҵ� �Ǵ� �ε��� ���ġ�� �߻��Ͽ� ����
	// ����Ʈ�� ��� ����� ������ ��ũ�� ��ü�ϸ� �Ǳ� ������ ������� ������ ���� ���� �ӵ��� ������.

#pragma region ����Ʈ �⺻ ����
	/*list<int>		ListInt;

	ListInt.push_back(10);
	ListInt.push_back(20);
	ListInt.push_back(30);

	/ *for (size_t i = 0; i < ListInt.size(); ++i)
	{
	cout << ListInt[i] << endl;		// �迭 ��� �����̳ʸ� ��밡���� ����
	}* /

	list<int>::iterator iter = ListInt.begin();

	// iter += 2;		// ���� ���� ����� list �����̳ʴ� ����� �� ����.
	++iter;
	++iter;

	cout << (*iter) << endl;*/

	/*for( iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	{
	cout << (*iter) << endl;
	}*/

	/*ListInt.push_front(10);
	ListInt.push_front(20);
	ListInt.push_front(30);

	ListInt.pop_front();

	for (list<int>::iterator iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	{
	cout << (*iter) << endl;
	}*/

	// ����Ʈ ���� size, clear, empty, swap, erase ��� �Լ� ��� ���ϰ� �ִ�.
#pragma endregion ����Ʈ �⺻ ����

#pragma region �߰� ������ ��


	/*list<int>		ListInt;

	ListInt.push_back(10);
	ListInt.push_back(20);
	ListInt.push_back(30);
	ListInt.push_back(40);
	ListInt.push_back(50);

	list<int>::iterator	iter = ListInt.begin();

	++iter;
	++iter;
	++iter;

	//ListInt.insert(iter, 600);

	iter = ListInt.erase(iter);
	cout << (*iter) << endl;
*/

	/*for (iter = ListInt.begin(); iter != ListInt.end(); ++iter)
		cout << (*iter) << endl;*/



#pragma endregion �߰� ������ ��

#pragma region ����Ʈ�� ����


	/*vector<int>		vecInt;

	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);
	vecInt.push_back(rand() % 100);

	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;

	cout << "=============after============" << endl;
	
	sort(vecInt.begin(), vecInt.end());
	
	for (size_t i = 0; i < vecInt.size(); ++i)
		cout << vecInt[i] << endl;*/

	/*list<int>		listInt;

	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);
	listInt.push_back(rand() % 100);

	for (list<int>::iterator iter = listInt.begin();
		iter != listInt.end(); ++iter)
		cout << (*iter) << endl;

	cout << "=============after============" << endl;

	// sort(listInt.begin(), listInt.end()); // �� ���ķ� ����, �迭 ������� ����

	listInt.sort(greater<int>());	// ������ ���, ��������� ����� ����Լ�

	for (list<int>::iterator iter = listInt.begin();
		iter != listInt.end(); ++iter)
		cout << (*iter) << endl;*/


list<int>		ListInt;

ListInt.push_back(10);
ListInt.push_back(20);
ListInt.push_back(30);
ListInt.push_back(40);
ListInt.push_back(50);


for (list<int>::iterator iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	cout << (*iter) << endl;

cout << "---------------after==================" << endl;


ListInt.reverse();

for (list<int>::iterator iter = ListInt.begin();
	iter != ListInt.end(); ++iter)
	cout << (*iter) << endl;

#pragma endregion ����Ʈ�� ����

}