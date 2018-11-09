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
struct picture{
    string name;
    int height;
};

bool cmp(const picture &x,const picture &y){
    if(x.height == y.height)
        return x.name < y.name;
    else
        return y.height < x.height;
}

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    int row = N/K,lastrow = N/K + N%K;//�ܽ�:��������ȡ����,ֻ��ҪN/K �ټ�����������
    int i,c;
    vector<picture> pic(10000);//����һ��10000��С�Ľṹ������
    for(i = 0;i < N; ++i)
    {
        cin >> pic[i].name >> pic[i].height;//������Ϣ
    }
    sort(pic.begin(),pic.end(),cmp);//������������

    int mid,left,right;
    vector<string> ans(lastrow);//����һ��lastrow��С�Ľṹ������
    mid = (lastrow >> 1);
    left = mid - 1,right = mid + 1;
    ans[mid] = pic[0].name;
    for(i = 1; i < lastrow; i += 2)//�ܽ�:����������ֵ�,���Ƚ������򣬺��渳ֵ
        ans[left--] = pic[i].name;
    for(i = 2; i < lastrow; i += 2)
        ans[right++] = pic[i].name;
    for(i = 0; i < lastrow; ++i)
    {
        cout << ans[i];
        if(i < lastrow - 1)
            cout << ' ';
    }
    cout << endl;
    int temp = lastrow;
    for(c = 0;c < K - 1; ++c)//ʣ�µ�K-1��
    {
        mid = (row >> 1);
        left = mid - 1,right = mid + 1;
        vector<string> ans(row);
        ans[mid] = pic[temp].name;
        for(i = temp+1;i < temp + row; i +=2 )
            ans[left--] = pic[i].name;
        for(i = temp+2; i < temp+row; i +=2)
            ans[right++] = pic[i].name;
        for(i = 0; i < row; ++i)
        {
            cout << ans[i];
            if(i < row - 1)
               cout << ' ';
        }
        cout << endl;
        temp += row;
    }
    return 0;
}
