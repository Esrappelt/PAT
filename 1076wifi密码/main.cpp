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
�����һ�и���һ��������N��<= 100�������N�У�ÿ�а��ա����-�𰸡��ĸ�ʽ����һ�����4��ѡ���T����ʾ��ȷѡ���F����ʾ����ѡ�ѡ����ÿո�ָ���

�����ʽ��

��һ�������wifi���롣

����������
8
A-T B-F C-F D-F
C-T B-F A-F D-F
A-F D-F C-F B-T
B-T A-F C-F D-F
B-F D-T A-F C-F
A-T C-F B-F D-F
D-T B-F C-F A-F
C-T A-F B-F D-F
���������
13224143
*/

int main()
{
    int N,i,j,index = 0;
    char temp1,temp2;
    scanf("%d",&N);
    getchar();
    int a[1000];
    for(j = 1; j <= N; ++j)
    {
        for(i = 1; i <= 4; ++i)
        {
            scanf("%c-%c",&temp1,&temp2);
            getchar();
            if(temp2 == 'T')
                a[index++] = (int)temp1 - 64;
        }
    }
    for(i = 0; i < index; ++i)
        printf("%d",a[i]);
    printf("\n");
	return 0;
}
