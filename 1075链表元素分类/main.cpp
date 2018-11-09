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

struct element{
    int address;
    int data;
    int nextaddress;
};

int main()
{
    int N,K,adr,i,j,first;
    vector<int> a(100000),next(100000);
    scanf("%05d%d%d",&first,&N,&K);//N������,K�ǻ�׼,first���׵�ַ
    int tmp = first;
    vector<element> ans(N);
    for(i = 0; i < N; ++i)
    {
        scanf("%05d",&adr);
        scanf("%d %05d",&a[adr],&next[adr]);//a����װ����adr�����ַ��ֵ,b����װ�������ֵ����һ����ַ
    }
    if(N == 1)
    {
        printf("%05d %d -1\n",first,a[first]);
        return 0;
    }
    int temp = tmp,index = 0;
    for(j = 1; j <= 3; ++j)
    {
        temp = tmp;
        while(temp != -1)
        {
            if(a[temp] < 0 && j == 1)
            {
                ans[index].data = a[temp];
                ans[index].address = temp;
                index++;
            }
            else if(j == 2 && a[temp] >= 0 && a[temp] <= K)
            {
                ans[index].data = a[temp];
                ans[index].address = temp;
                index++;
            }
            else if(j == 3 && a[temp] > K)
            {
                ans[index].data = a[temp];
                ans[index].address = temp;
                index++;
            }
            temp = next[temp];
        }
    }
    for(i = 0; i < index; ++i)
    {
        if(i < index - 1)
            printf("%05d %d %05d\n",ans[i].address,ans[i].data,ans[i+1].address);
        else
            printf("%05d %d %d\n",ans[i].address,ans[i].data,-1);
    }
    return 0;
}
/*
�����ʽ��

ÿ���������1������������
ÿ������������1�и�������1�����ĵ�ַ������ܸ�������������N (<= 105)���Լ�������K (<=1000)��
���ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣������ݣ�Ϊ[-105, 105]�����ڵ�������Next����һ���ĵ�ַ����Ŀ��֤����������Ϊ�ա�

�����ʽ��

��ÿ�������������������ͷ��β��˳��������ź�Ľ����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
���������
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

*/
