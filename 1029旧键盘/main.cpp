#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡�
���ڸ���Ӧ�������һ�����֡��Լ�ʵ�ʱ���������֣������г��϶���������Щ����

�����ʽ��

������2���зֱ����Ӧ����������֡��Լ�ʵ�ʱ���������֡�
ÿ�������ǲ�����80���ַ��Ĵ�������ĸA-Z��������Сд��������0-9���Լ��»��ߡ�_��������ո���ɡ���Ŀ��֤2���ַ������ǿա�

�����ʽ��

���շ���˳����һ������������ļ�������Ӣ����ĸֻ�����д��ÿ������ֻ���һ�Ρ���Ŀ��֤������1��������

����������
7_This_is_a_test
_hs_s_a_es
���������
7TI
*/

void Change(char ans[],int k,char *out,int &m)
{
	int i,j,flag = 1;
	for(i = 0; i < k; i++)
	{
		flag = 1;
		for(j = 0; j < i; j++)
		{
			if(toupper(ans[i]) == toupper(ans[j]))
				flag = 0;//�������ǰ������ͬ��Ԫ�أ���ʼȥ��
		}
		if(flag)//���ǰ��û���ظ���Ԫ��,�Ž�������
		{
			out[m++] = toupper(ans[i]);
		}
	}
	out[m] = '\0';//�ǵ����һ��Ԫ��Ҫ��Ϊ'\0'
}

int main()
{
	char str1[80];
	char str2[80];
	char ans[80];
	char out1[80],out2[80];
	gets(str1);
	gets(str2);
	int i = 0,j = 0,len1,len2,k = 0,m1 = 0,m2 = 0;
	int flag = 1;
	len1 = strlen(str1);
	len2 = strlen(str2);
	Change(str1,len1,out1,m1);
	Change(str2,len2,out2,m2);
	while(i < m1 && j < m2)
	{
		if(out1[i] == out2[j])
		{
			i++;
			j++;
		}
		else
		{
			ans[k++] = out1[i];
			i++;
		}
	}
	while(i < len1)
	{
		ans[k++] = out1[i];
		i++;
	}
	ans[k] = '\0';
	puts(ans);
	return 0;
}


