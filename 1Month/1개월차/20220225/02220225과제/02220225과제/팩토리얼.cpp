//#include <iostream> 
//
//using namespace std;
//
////재귀함수로 5팩토리얼 구현 5 * 4 * 3 * 2 * 1
////재귀함수는 자기 자신을 호출하는 함수 조건이 없으면 무한루프 
//void rollback(int a);
//int sum = 1;
//
//void main(void)
//{
//	int iNum;
//	cout << "팩토리얼을 구할 정수 입력 : ";
//	cin >> iNum;
//	rollback(iNum);
//}
//
//void rollback(int a)
//{
//	
//	if (a != 0)
//	{
//		sum *= a;
//		a--;
//		if (a > 0)
//		{
//			rollback(a);
//		}
//		else if (a <= 1)
//		{
//			cout << sum << endl;
//			return;
//		}
//		
//
//	}
//
//	else if (a == 0)
//	{
//		cout << 1 << endl;
//		return;
//	}
//	
//	
//
//	
//	/*static int Check = a;
//
//	if (Check >= 2)
//	{
//		if (a >= 1)
//		{
//			int i = a;
//			--a;
//			int j = a;
//			int k = i*j;
//			--a;
//			sum *= k;
//			if (a == 1 || a == 0)
//			{
//				cout << sum << endl;
//			}
//		}
//		if (a < 0)
//		{
//			return;
//		}
//		rollback(a);
//	}
//	else if(Check <= 1)
//	{
//		cout << 1 << endl;
//		return;
//	}*/
//}
//	
	


#include <iostream>

using namespace std;

int   Fact(int iNumber);

void main(void)
{
	int      iInput = 0;
	cin >> iInput;
	cout << Fact(iInput) << endl;
}
int   Fact(int iNumber)
{
	if (0 == iNumber)

		return 1;

	return iNumber * Fact(iNumber - 1);

}
	

	
	
		
		
	
