
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
����Ҫ��ʵ��һ�����ּ��ܷ�����
���ȹ̶�һ��������������A������һ������B������ÿ1λ������A�Ķ�Ӧλ���ϵ����ֽ����������㣺
������λ����Ӧλ��������Ӻ��13ȡ�ࡪ��������J����10��Q����11��K����12��
��ż��λ����B�����ּ�ȥA�����֣������Ϊ���������ټ�10���������λΪ��1λ��

�����ʽ��

������һ�������θ���A��B����Ϊ������100λ��������������Կո�ָ���

�����ʽ��

��һ����������ܺ�Ľ����
*/



int main()
{	
	char str1[101],str2[101],ans[101];
	scanf("%s %s",&str1,&str2);
	int A[100],B[100],sum = 0;
	int lenA = strlen(str1),lenB = strlen(str2),m = 0;
	int i,j,k = 0;
	for(i = lenA - 1,j = 0; i >= 0; i--,j++)
		A[j] = str1[i] - '0';
	for(i = lenB - 1,j = 0; i >= 0; i--,j++)
		B[j] = str2[i] - '0';

/*	for(i = 0; i < lenA; i++)
		cout << A[i] << " ";
	cout << endl;
	for(i = 0; i < lenB; i++)
		cout << B[i] << " ";
	cout << endl;
*/

	i = j = 0;
	while(i < lenA && j < lenB)
	{
		if( (i + 1) % 2 == 1)//���������λ
		{
			sum = A[i] + B[j];
			sum %= 13;
			if(sum >= 10 && sum < 13)
			{
				if(sum == 10)
					ans[k++] = 'J';
				else if(sum == 11)
					ans[k++] = 'Q';
				else if(sum == 12)
					ans[k++] = 'K';
			}
			else
				ans[k++] = sum + '0';
		}
		else if( (i + 1) % 2 == 0)
		{
			sum = B[i] - A[j];
			if(sum >= 0)
				ans[k++] = sum + '0';
			else
				ans[k++] = sum + 10 + '0';
		}
		i++;
		j++;
	}
	if(i < lenA)
	{
		for(m = i; m < lenA; m++)
		{
			
			if((m + 1) % 2 == 1)//����
			{
				ans[k++] = A[m] % 13 + '0';
			}
			else//ż��
			{
				sum = A[m];
				if(sum == 0)
					ans[k++] = '0';
				else
				ans[k++] = -sum + 10 + '0';
			}
		}
	}
	else if(j < lenB)
	{
		for(m = j; m < lenB; m++)
			ans[k++] = B[m] + '0';
	}
	ans[k] = '\0';
	for(i = k - 1; i >= 0; i--)
		cout << ans[i];
	cout << endl;
	return 0;
}