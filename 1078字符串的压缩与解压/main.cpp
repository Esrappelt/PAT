#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <malloc.h>
#include <memory.h>
using namespace std;
/*
�ı�ѹ���кܶ��ַ�������������ֻ������򵥵�һ�֣�������ͬ�ַ���ɵ�һ��������Ƭ��������ַ���Ƭ���к�������ַ��ĸ�������ʾ������ ccccc ���� 5c ����ʾ������ַ�û���ظ�����ԭ����������� aba ѹ������Ȼ�� aba��

��ѹ�������Ƿ������������� 5c �����ı�ʾ�ָ�Ϊ ccccc��

������Ҫ�����ѹ�����ѹ��Ҫ�󣬶Ը����ַ������д����������Ǽ򵥵ؼ���ԭʼ�ַ�������ȫ��Ӣ����ĸ�Ϳո���ɵķǿ��ַ�����

�����ʽ��

�����һ�и���һ���ַ�������� C �ͱ�ʾ������ַ�����Ҫ��ѹ��������� D �ͱ�ʾ������ַ�����Ҫ����ѹ���ڶ��и�����Ҫ��ѹ�����ѹ�Ĳ�����1000���ַ����ַ������Իس���β����Ŀ��֤�ַ��ظ����������ͷ�Χ�ڣ�������ļ�������1MB��

�����ʽ��

����Ҫ��ѹ�����ѹ�ַ���������һ������������

�������� 1��
C
TTTTThhiiiis isssss a   tesssst CAaaa as
������� 1��
5T2h4is i5s a3 te4st CA3a as
�������� 2��
D
5T2h4is i5s a3 te4st CA3a as10Z
������� 2��
TTTTThhiiiis isssss a   tesssst CAaaa asZZZZZZZZZZ
*/
void change1(string a)
{
    char temp;
    int i,j,cnt;
    for(i = 0; i < a.length(); ++i)
    {
        temp = a[i];
        cnt = 1;
        while(a[i+1] == temp)
        {
            cnt++;
            i++;
        }
        if(cnt == 1)
            printf("%c",temp);
        else
            printf("%d%c",cnt,temp);
    }
}

void change2(string a)
{
    int i,j,cnt = 0,c = 0,k = 0;
    for(i = 0; i < a.length(); ++i)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            c = cnt = 0,k = i;
            while(a[i] >= '0' && a[i] <= '9')
            {
                i++;
                c++;//��cλ��
            }
            for(j = k; j <= k + c - 1; ++j)
                cnt += (a[j] - '0') * pow(10,c+k-j-1);
            for(j = 0; j < cnt; ++j)
                printf("%c",a[i]);
        }
        else
            printf("%c",a[i]);
    }
}


int main()
{
    int i,j,k;
    char c;
    string a;
    scanf("%c",&c);
    getchar();
    getline(cin,a,'\n');
    if(c == 'C')
        change1(a);
    else
        change2(a);
    printf("\n");
	return 0;
}
