#include <iostream>
#include <random>

using namespace std;

void Game();
int Input();
void Check(int a, int* p);
int Bingo(int* p);

void main(void)
{
	Game();	
}

void Game()
{
	random_device random;
	mt19937 rd(random());
	uniform_int_distribution<int> range(0, 24);
	
	int iArray[25]{ 0 };
	int* p = &iArray[0];
	int turn = 0;

	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
	}
	
	int iTemp = 0, iDest = 0, iSour = 0;

	for (int i = 0; i < 500; ++i)
	{
		iDest = range(random);	// 20
		iSour = range(random);	// 36

		iTemp = iArray[iDest];
		iArray[iDest] = iArray[iSour];
		iArray[iSour] = iTemp;
	}
	
	
	while (true)
	{
		system("cls");		
		if (Bingo(p) == 5)
		{
			cout << "승리!!" << endl;
			break;
		}
		int count = 0;
		cout << turn <<"회"<< endl;
		cout << Bingo(p) <<"빙고" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iArray[count] != 0)
				{
					cout << iArray[count] << "\t";
				}
				else if (iArray[count] == 0)
				{
					cout << "*" << "\t";
				}
				count++;
			}
			cout << endl;
			cout << endl;
			
		}
		
		Check(Input(), p);		
		
		turn++;
	}
}

int Input()
{
	int a = 0;
	cout << "1~25사이의 숫자 입력 : ";
	cin >> a;
	return a;
}

void Check(int a, int* p)
{
	for (int i = 0; i < 25; ++i)
	{
		if (a == *p)
		{
			*p = 0;
		}
		else
		{
			p++;
		}
	}
}

int Bingo(int* p)
{
	int bingo = 0;

	for (int i = 0; i < 5; ++i) // 가로 빙고
	{
		int count = 0;
		for (int j = i * 5; j < (i*5) + 5; ++j)
		{
			if (*p == 0)
			{
				count++;			
			}
			if (count == 5)
			{
				if (bingo < 5)
				{
					bingo += 1;
				}
				else
				{
					return bingo;
				}
			}
			p++;
		}
	}
	for (int i = 0; i < 25; ++i) // 인덱스 초기화
	{
		--p;
	}
	//0  1  2  3  4			4 8 12 16 20 % 4 = 0
	//5  6  7  8  9			0 6 12 18 24  % 6 = 0 || 0
	//10 11 12 13 14		i = 1씩 j는 5씩 증가한 인덱스
	//15 16 17 18 19
	//20 21 22 23 24

	for (int i = 0; i < 5; ++i) // 세로 빙고
	{
		int count = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (p[(j*5)+i] == 0)
			{
				count++;
			}
			if (count == 5)
			{
				if (bingo < 5)
				{
					bingo += 1;
				}
				else
				{
					return bingo;
				}
			}
			
		}
	}

	int diagonal1 = 0;  //대각선
	for (int i = 0; i < 25; ++i)
	{
		if (i != 0 && i != 24 && i % 4 == 0 && *p == 0)
		{
			diagonal1++;
		}
		if (diagonal1 == 5)
		{
			if (bingo < 5)
			{
				bingo += 1;
				diagonal1 = 0;
			}
			else
			{
				return bingo;
			}
		}
		p++;
	}
	

	for (int i = 0; i < 25; ++i) //인덱스 초기화
	{
		--p;
	}

	int diagonal2 = 0;  //대각선
	for (int i = 0; i < 25; ++i)
	{
		if (i == 0 && *p == 0 || i % 6 == 0 && *p == 0)
		{
			diagonal2++;
		}
		if (diagonal2 == 5)
		{
			if (bingo < 5)
			{
				bingo += 1;
				diagonal2 = 0;
			}
			else
			{
				return bingo;
			}
		}
		p++;
	}
	return bingo;
}


//0  1  2  3  4			4 8 12 16 20 % 4 = 0
//5  6  7  8  9			0 6 12 18 24  % 6 = 0 || 0
//10 11 12 13 14		i = 1씩 j는 5씩 증가한 인덱스
//15 16 17 18 19
//20 21 22 23 24

//0~ 4   5 ~ 9 10~ 14 15~ 19 20 ~ 24
//2. 빙고 게임(편한대로) - 5x5 배열을 이용하여 1부터 25까지수를 랜덤하게 출력,
//숫자를 선택해서 입력하면 일치하는 숫자는 *로 치환하여 출력
//*로 표시된 숫자가 가로 세로 대각선으로 5개가 될때마다 빙고가 하나 증가,
//5빙고가 되면 승리로 종료 - 가능하면 AI 추가도 해보는거 권장




