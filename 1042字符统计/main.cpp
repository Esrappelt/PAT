#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>

/*
���д�����ҳ�һ�θ��������г�����Ƶ�����Ǹ�Ӣ����ĸ��

�����ʽ��

������һ���и���һ�����Ȳ�����1000���ַ������ַ�����ASCII���������ɼ��ַ����ո���ɣ����ٰ���1��Ӣ����ĸ���Իس��������س��������ڣ���

�����ʽ��

��һ�����������Ƶ����ߵ��Ǹ�Ӣ����ĸ������ִ���������Կո�ָ�������в��У����������ĸ����С���Ǹ���ĸ��ͳ��ʱ�����ִ�Сд�����Сд��ĸ��

����������
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
���������
e 7
*/

int count[200];
int a[1000];


char* _strlwr(char* src)  
{  
    while (*src != '\0')  
    {  
        if (*src > 'A' && *src <= 'Z'){  
            *src += 32;  
        }  
        src++;  
    }  
    return src;  
}  



int main()
{
	char str[1000],b[1000],max2;
	gets(str);
	int i,len = strlen(str),k = 0,max1,flag = 0;
	_strlwr(str);
	for(i = 0; i < len; i++)
		count[(int)str[i]]++;//ֱ����ascll����±����
	for(i = 0; i < len; i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			flag = 1;
		}
	}
	if(flag)
	{
		printf("0");
		return 0;
	}
	for(i = 97; i <= 122; i++)
	{
		if(count[i] != 0)
		{
			a[k] = count[i];
			b[k++] = (char)(i);
		}
	}
	max1 = a[0];
	max2 = b[0];
	for(i = 0; i < k; i++)
	{
		if(a[i] > max1)
		{
			max1 = a[i];
			if(b[i] > max2)
				max2 = b[i];
		}
	}
	cout << max2 << " " << max1 ;
	return 0;
}
