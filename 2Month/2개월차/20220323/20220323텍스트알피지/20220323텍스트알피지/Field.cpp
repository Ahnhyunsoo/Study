#include "stdafx.h"
#include "Field.h"
#include "Define.h"

int Field::PrintMenu(int place)
{
	int Input = 0;
	switch (place)
	{
	case ĳ���ͻ���:
		cout << "1. ����, 2. ������, 3. ����, 4. �ҷ�����, 5. ���� : ";
		cin >> Input;
		break;

	case ����:
		cout << "1.����� , 2. ����, 3. ���� : ";
		cin >> Input;
		break;

	case �����Ա�:
		cout << "1.�ʱ� , 2. �߱�, 3. ��� , 4. ���ܰ� : ";
		cin >> Input;
		break;

	case ����:
		cout << "1. ����, 2.Hpȸ�� , 3. Mpȸ��, 4. �������� : ";
		cin >> Input;
		break;
	}
	return Input;
}

void Field::SetPlace(int pl)
{
	Place = pl;
}

int Field::GetPlace()
{
	return Place;
}

Field* Field::GetFp()
{
	return fp;
}

Field::Field()
{
	
}



Field::~Field()
{
}
