//#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
//using namespace std;

/*
�ɼ����ϻ��˼���������������һ�����ֵ�ʱ�򣬶�Ӧ���ַ��Ͳ�����֡����ڸ���Ӧ�������һ�����֡��Լ���������Щ��������Ľ�����ֻ���������

�����ʽ��

������2���зֱ������������Щ�����Լ�Ӧ����������֡����ж�ӦӢ����ĸ�Ļ����Դ�д������ÿ�������ǲ�����105���ַ��Ĵ���
���õ��ַ�������ĸ[a-z, A-Z]������0-9���Լ��»��ߡ�_��������ո񣩡���,������.������-������+���������ϵ�������
��Ŀ��֤��2����������ִ��ǿա�
ע�⣺����ϵ��������ˣ���ô��д��Ӣ����ĸ�޷��������
�����ʽ��
��һ��������ܹ�������Ľ�����֡����û��һ���ַ��ܱ��������������С�
����������
7+IE.
7_This_is_a_test.
���������
_hs_s_a_tst
*/

char str[100001],str2[100001];
char ans[100001];
char hash[256];//�����ĸ�ĸ���
int flag = 1;

void Delete(char *a,char *b)
{
	int ka = 0,kb = 0;
	char *start = b,*end = b;
	char *s = a;
	while(*s)
	{
		++hash[*s];
		s++;
	}
	if(flag)//��д��ĸ�ܴ����
	{
		while(*end)
		{
			if(hash[*end] == 0)
			{
				start[ka++] = *end;
			}
			end++;
		}
		start[ka] = '\0';//�ַ������һ��Ԫ��һ��Ҫ��Ϊ'\0'
		if(ka == 0)
			printf("\n");
		else
			puts(start);
	}
	else//���ܴ����
	{	
		while(*end)
		{
			if(*end >= 'A' && *end <= 'Z')
			{
				hash[*end] = 1;
			}
			if(hash[*end] == 0)
			{
				ans[kb++] = *end;
			}
			end++;
		}
		ans[kb] = '\0';//�ַ������һ��Ԫ��һ��Ҫ��Ϊ'\0'
		if(kb == 0)
			printf("\n");
		else
			puts(ans);
	}
}

int main()
{
	int i = 0;
	char c;
	while((c = getchar()) != '\n')
	{
		str[i++] = tolower(c);
		if(c == '+')
			flag = 0;
	}//Ҫɾ�����ַ�
	str[i] = '\0';
//	puts(str);
	gets(str2);
	Delete(str,str2);
	return 0;
}


/*
#include <stdio.h>
#include <ctype.h>

int main()
{
    int list[128] = {0}, bad_key = 0, input;

    while ((bad_key = getchar()) != '\n') {
        list[bad_key] = 1;
        list[tolower(bad_key)] = 1; // �����л�����ֵΪ1���������ĸ����Ӧ�Ĵ�Сд�ַ���Ҫ��ֵΪ1
    }
    if (list['+'] == 1) // ����ϵ���
        for (int i = 65; i < 91; i++)
            list[i] = 1;
    while ((input = getchar()) != '\n')
        if (list[input] == 0) // �����ַ������������
            printf("%c", input);

    return 0;
}
*/