#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

/*
����Ļ���Ҫ��ǳ��򵥣�����N��ʵ�����������ǵ�ƽ��ֵ��
�����ӵ�����Щ�������ݿ����ǷǷ��ġ�
һ�����Ϸ�����������[-1000��1000]�����ڵ�ʵ����������ྫȷ��С�����2λ���������ƽ��ֵ��ʱ�򣬲��ܰ���Щ�Ƿ������������ڡ�

�����ʽ��

�����һ�и���������N��<=100�������һ�и���N��ʵ�������ּ���һ���ո�ָ���

�����ʽ��

��ÿ���Ƿ����룬��һ���������ERROR: X is not a legal number��������X�����롣
�����һ��������������The average of K numbers is Y��������K�ǺϷ�����ĸ�����Y�����ǵ�ƽ��ֵ����ȷ��С�����2λ��
���ƽ��ֵ�޷����㣬���á�Undefined���滻Y�����KΪ1���������The average of 1 number is Y����

��������1��
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
�������1��
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
*/

int main()
{
	int N,flag,cnt = 0,i,j;
	char str1[10000],str2[10000];
	double sum = 0,temp;
//	gets(str);
//	sscanf(str,"%lf",&sum);//��str����ַ���,�Զ���ȡstr��Ķ�������sum
//	sprintf(str2,"%.2lf",sum);//����.2lf��ʽ����str2��
//	puts(str2);//Ȼ�����str2
	scanf("%d",&N);
	fflush(stdin);
	for(i = 0; i < N; i++)
	{
		scanf("%s ",&str1);
		sscanf(str1,"%lf",&temp);//��str1����ַ���,�Զ���ȡstr��Ķ�������temp
		sprintf(str2,"%.2lf",temp);//����.2lf��ʽ����str2��
		flag = 0;
		for(j = 0; j < strlen(str1); j++)
		{
			if(str1[j] != str2[j])
				flag = 1;
		}
		if(flag || temp < -1000 || temp > 1000)
		{
			printf("ERROR: %s is not a legal number\n",str1);
		}
		else
		{
			sum += temp;
			cnt++;
		}
	}
	if(cnt == 1)
	{
		printf("The average of 1 number is %.2lf\n",sum);
	}
	else if(cnt > 1)
	{
		printf("The average of %d numbers is %.2lf\n",cnt,sum / cnt);
	}
	else
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	return 0;
}
