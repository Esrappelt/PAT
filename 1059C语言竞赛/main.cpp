#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int check[10009] = {0};//�ж�

int Isprime(int n)
{
	if(n <= 1)
		return 0;
	int i;
	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int find;
	int N,K;
	int i;
	cin >> N;
	for(i = 1; i <= N; i++)
	{
		scanf("%d",&find);
		check[find] = i;//check��ֵ��������
	}
	fflush(stdin);
//	cout << check[8888] << endl;
	scanf("%d",&K);
	for(i = 0; i < K; i++)
	{
		scanf("%d",&find);//�����ѯ
		if(check[find] == 0)//û�������
		{
			printf("%04d: Are you kidding?\n",find);
	//		continue;
		}
		else if(check[find] == 999)//���ʹ���
		{
			printf("%04d: Checked\n",find);
	//		continue;
		}
		else if(Isprime(check[find]))//������
		{
			check[find] = 999;//��־�ѷ���
			printf("%04d: Minion\n",find);
	//		continue;
		}
		else if(check[find] == 1)
		{
			check[find] = 999;
			printf("%04d: Mystery Award\n",find);
	//		continue;
		}
		else if(!Isprime(check[find]))
		{
			check[find] = 999;
			printf("%04d: Chocolate\n",find);
	//		continue;
		}
	}
	return 0;
}



