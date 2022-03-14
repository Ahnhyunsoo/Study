#include <iostream>
#include <random>

using namespace std;

void main(void)
{
	random_device random;
	mt19937 rd(random());
	uniform_int_distribution<int> range{1, 9};
	
	int a[3];
	int count = 0;
	int strike = 0;
	int ball = 0;

	for (int i = 0; i < 3; ++i)
	{		
		if (i == 0)
		{
			a[i] = range(random);
		}
		if (i != 0)
		{
			int c = range(random);
			int* p = &c;
			for (int j = i; j > 0;)
			{
				if (a[j - 1] != c)
				{
					--j;
				}
				else if (a[j - 1] == c)
				{
					int c = range(random);
					*p = c;
					j = i;
				}
			}
			a[i] = c;
		}
	}
	while (true)
	{
		int b[3];
		cout << a[0] << a[1] << a[2];
		system("cls");
		cout << "1~9사이 숫자 3개 입력 ex(1 2 4) : ";
		for (int i = 0; i < 3; ++i)
		{			
			cin >> b[i];			
		}		
		for (int i = 0; i < 3; ++i)
		{
			if (a[i] == b[i])
			{
				strike += 1;
			}
			for (int j = 0; j < 3; ++j)
			{
				if (a[i] != b[i] &&a[i] == b[j])
				{
					ball += 1;
				}
			}
		}
		if (strike == 3)
		{
			cout << "승리" << endl;
			break;
		}

		count += 1;

		if (count == 10)
		{
			cout << "패배" << endl;
			break;
		}
		cout << strike << "스트라이크 " << ball << "볼 " << endl;
		strike = 0;
		ball = 0;
	
		cout << count << "회" << endl;
		system("pause");
	}
}


