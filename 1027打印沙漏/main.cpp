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

int main()
{
    char c;
    int N,i,j;//ɳ©����
    cin >> N >> c;
    int n = 2 * sqrt((N + 1)/2) - 1;//�����ɳ©��������
 //   cout << n  << endl;
    int uprow =  (n - 1)/2 + 1;//���沿������Ҫ������
    int downrow = (n - 1)/2;//���沿������Ҫ������
    if(N == 0)
    {
        cout << "1";
        return 0;
    }
    for(i = uprow; i >= 1; --i)
    {
        for(j = 1; j <= (uprow - i); ++j)
            cout << " ";
        for(j = 1; j <= 2 * i - 1; ++j)
            cout << c;
        for(j = 1; j <= (uprow - i); ++j)
            cout << " ";
        cout << endl;
    }
    for(i = 1; i <= downrow; ++i)
    {
        for(j = 1; j <= downrow - i; ++j)
            cout << " ";
        for(j = 1; j <= 2 * i + 1; ++j)
            cout << c;
        for(j = 1; j <= downrow - i; ++j)
            cout << " ";
        cout << endl;
    }
    cout << N + 1 - 2 * uprow * uprow;
	return 0;
}

/*
����Ҫ����д������Ѹ����ķ��Ŵ�ӡ��ɳ©����״���������17����*����Ҫ�����и�ʽ��ӡ

*****
 ***
  *
 ***
*****
��ν��ɳ©��״������ָÿ��������������ţ����з������Ķ��룻�������з�������2��
�������ȴӴ�С˳��ݼ���1���ٴ�С����˳���������β��������ȡ�

��������N�����ţ���һ�����������һ��ɳ©��Ҫ���ӡ����ɳ©���õ������ܶ�ķ��š�

�����ʽ��

������һ�и���1��������N��<=1000����һ�����ţ��м��Կո�ָ���

�����ʽ��

���ȴ�ӡ���ɸ���������ɵ�����ɳ©��״�������һ�������ʣ��û�õ��ķ�������

����������
19 *
���������
*****
 ***
  *
 ***
*****
2

*/
