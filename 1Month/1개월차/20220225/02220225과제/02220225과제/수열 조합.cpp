#include <iostream>

using namespace std;

void johap(int n, int r);

void main(void)
{
	johap(9, 3); //84
}

void johap(int n, int 
	r)
{
	if (n != 0)
	{
		johap(n, r);
	}
	else
	{
		cout << 1 << endl;
		return;
	}
}

//nCr  n!/ r!(n - r)!
//nCn - r


//9C3 9!/ 3!(9 - 3)!

//9C6 9!/ 6!(9 - 6)!
