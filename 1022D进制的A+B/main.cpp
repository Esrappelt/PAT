#include <iostream>
#include <stdio.h>
using namespace std;

void Decimal(long n,long d)
{
	if(n == 0 || d <= 0)
		return;
	else
	{
		Decimal(n / d,d);
		if(d > 1 && d <= 10)
			cout << n % d;
		else
		{
			if(n % d < 10)
				cout << n % d;
			else
				return;
		}
	}
}

int main()
{

	long A,B,C;
	int d;
	cin >> A >> B >> d;
	C = A + B;
	if(C == 0)//���AB�����Ҫ����A+B�Ƿ���ڵ���0
		cout << "0";
	else
		Decimal(C,d);
	return 0;
}