/*
����һ��kλ����N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)��
���д����ͳ��ÿ�ֲ�ͬ�ĸ�λ���ֳ��ֵĴ��������磺����N = 100311������2��0��3��1����1��3��

�����ʽ��

ÿ���������1��������������һ��������1000λ��������N��

�����ʽ��

��N��ÿһ�ֲ�ͬ�ĸ�λ���֣���D:M�ĸ�ʽ��һ���������λ����D������N�г��ֵĴ���M��Ҫ��D�����������
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int count[10];
int main()
{
	char num[1000];
	gets(num);
	int i,len = strlen(num);
	for(i = 0; i < len; i++)
	    count[num[i] - '0']++;//ͳ��1-9֮����ж�������
	for(i = 0; i < 10; i++)
	{
		if(count[i] != 0)
			printf("%d:%d\n",i,count[i]);
	}
	return 0;
}