#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
������ϰ��ʹ��ʮ������������Ĭ��һ�����ֵ�ÿһλ����ʮ���Ƶġ�
����PAT���˿��ҵ������ÿ�����ֵ�ÿһλ���ǲ�ͬ���Ƶģ�������������ֳ�Ϊ��PAT������
ÿ��PAT���˶�������Ǹ�λ���ֵĽ��Ʊ����硰����0527���ͱ�ʾ���λ��7����������2λ��2����������3λ��5����������4λ��10���������ȵȡ�
ÿһλ�Ľ���d������0����ʾʮ���ƣ���������[2��9]�����ڵ�������
������������Ʊ�Ӧ�ð��������λ���֣�����ʵ��Ӧ�ó�����PAT����ͨ��ֻ��Ҫ��סǰ20λ�͹����ˣ��Ժ��λĬ��Ϊ10���ơ�

������������ϵͳ�У���ʹ�Ǽ򵥵ļӷ�����Ҳ��ò��򵥡������Ӧ���Ʊ�0527��������μ��㡰6203+415���أ�
���ǵ����ȼ������λ��3+5=8����Ϊ���λ��7���Ƶģ��������ǵõ�1��1����λ����2λ�ǣ�0+1+1����λ��=2��
��Ϊ��λ��2���Ƶģ��������ǵõ�0��1����λ����3λ�ǣ�2+4+1����λ��=7����Ϊ��λ��5���Ƶģ��������ǵõ�2��1����λ��
��4λ�ǣ�6+1����λ��=7����Ϊ��λ��10���Ƶģ��������Ǿ͵õ�7��������ǵõ���6203+415=7201��
���������ڵ�һ�и���һ��Nλ�Ľ��Ʊ�0 < N <=20�����Իس������� ������У�ÿ�и���һ��������Nλ������PAT����

*/

void change(int *a,int len)
{
	int i = 0,j = len - 1;
	while(i < j)
	{
		swap(a[i],a[j]);
		i++;
		j--;
	}
}


void Sum(int dec[],int pat1[],int pat2[],int len)
{
	int i,sum = 0,decimal = 0;
	int k = 0,ans[25];
	for(i = 0; i < len; i++)
	{
		sum = pat1[i] + pat2[i] + decimal;
		if(dec[i] != 0)
		{
			ans[k++] = sum % dec[i];//ת���Ľ���
			decimal = sum / dec[i];//��λ
		}
		else
		{
			ans[k++] = sum % 10;
			decimal = sum / 10;
		}
	}
	change(ans,k);
	for(i = 0; i < k; i++)
		if(ans[i] != 0)
			break;
	if(i == k)
	{
		printf("0\n");
		return;
	}
	while(i < k)
	{	
		printf("%d",ans[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int i,j,N,dec[20],pat1[20],pat2[20],len2,len3;
	char str1[20],str2[20],str3[20];
	gets(str1);
	N = strlen(str1);
	fflush(stdin);
	gets(str2);
	len2 = strlen(str2);
	gets(str3);
	len3 = strlen(str3);
	
	for(i = len2 - 1,j = 0; i >= 0; i--,j++)
		dec[j] = str1[i] - '0';
	for(i = len2 - 1,j = 0; i >= 0; i--,j++)
		pat1[j] = str2[i] - '0';
	for(i = len3 - 1,j = 0; i >= 0; i--,j++)
		pat2[j] = str3[i] - '0';
	for(i = len2; i < N; i++)
		pat1[i] = 0;
	for(i = len3; i < N; i++)
		pat2[i] = 0;
	if(N == 1)
	{
		if((pat1[0] + pat2[0]) / dec[0] != 0)
			printf("%d%d\n",(pat1[0] + pat2[0]) % dec[0],(pat1[0] + pat2[0]) / dec[0]);
		else
			printf("%d\n",(pat1[0] + pat2[0]) % dec[0]);
	}
	else
		Sum(dec,pat1,pat2,N);
	return 0;
}