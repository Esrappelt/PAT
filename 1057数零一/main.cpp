#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
����һ�����Ȳ�����105���ַ���������Ҫ���㽫��������Ӣ����ĸ����ţ���ĸa-z��Ӧ���1-26�����ִ�Сд����ӣ�
�õ�����N��Ȼ���ٷ���һ��N�Ķ����Ʊ�ʾ���ж���0������1����������ַ�����PAT (Basic)����
����ĸ���֮��Ϊ��16+1+20+2+1+19+9+3=71����71�Ķ�������1000111������3��0��4��1��
*/
char str[100000];
int count[100000];
int main()
{
	gets(str);
	int i,len = strlen(str),sum = 0,count0 = 0,count1 = 0,N;
	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a'&& str[i] <= 'z')
			sum += (int)str[i] - 96;
		else if(str[i] >= 'A' && str[i] <= 'Z')	
			sum += (int)str[i] - 64;
	}
	while(sum)
	{
		N = sum%2;
		sum /= 2;
		if(N == 0)
			count0++;
		else
			count1++;
	}
	cout << count0 << " " << count1;
	return 0;
}