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

bool cmp(const int &x,const int &y)
{
    return x > y;
}

int main()
{
    int i,j,N,temp,cnt = 0;//�ﳵ������
    vector<int> dis(100000);//�ﳵ�ľ���
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
    {
        scanf("%d", &temp);
        dis.push_back(temp);
    }
    sort(dis.begin(),dis.end(),cmp);//��������
    for(i = 0; i < N; ++i)//����
    {
        if(dis[i] > i + 1)
            cnt++;
        else
            break;
    }
    printf("%d",cnt);
    dis.clear();
    return 0;
}





