#include <iostream>
#include <stdio.h>

using namespace std;

/*
������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����Ȼ���õ�1�����ּ���2�����֣����õ�һ���µ����֡�һֱ�ظ������������Ǻܿ��ͣ���С����ֺڶ���֮�Ƶ�6174��������������Ҳ��Kaprekar������

���磬���Ǵ�6767��ʼ�����õ�

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

�ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�

�����ʽ��

�������һ��(0, 10000)�����ڵ�������N��
*/

int Sort(int *a)
{
	int i,j;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return (a[0]*1000 + a[1]*100 + a[2]*10 + a[3]);
}


int Swap(int *a)
{
	int n,m,k,p;
	k = a[0];
	m = a[1];
	n = a[2];
	p = a[3];
	a[0] = p;
	a[1] = n;
	a[2] = m;
	a[3] = k;
	return (a[0]*1000 + a[1]*100 + a[2]*10 + a[3]);
}




void HeiDong(int n)
{
	int num[4],N = n,a,b,c,d;
	int k1,k2,cnt = 0;
	a = N % 10;
	b = N / 10 % 10;
	c = N /100 % 10;
	d = N / 1000;
	if(a == b && b == c && a == d)
	{
		printf("%04d - %04d = 0000",n,n);
		exit(0);
	}
	while(1)
	{
		cnt++;
		num[0] = N % 10;
		num[1] = N /10 % 10;
		num[2] = N /100 % 10;
		num[3] = N / 1000;
		k1 = Sort(num);
		k2 = Swap(num);
		N = k1 - k2;
		if(k2 < 1000)
		{
			printf("%04d - %04d = %04d\n",k1,k2,N);
		}
		else
			printf("%04d - %04d = %04d\n",k1,k2,N);
		if(k1 - k2 == 6174)
			break;
	}

//	printf("%d",cnt);printf("%02d - %02d = %d\n",k1,k2,N);
}


int main()
{
	int N;
	cin >> N;
	HeiDong(N);
	return 0;
}