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
�����ļ����רҵ���У������л������鱨��������ڡ�
һ������̨�����Լ��Ĺ�������������̨��Ϊ��������֡���������Ļ����ɼ�����������ģ�
����������������У�ȥ��һ����߷ֺ�һ����ͷ֣�ʣ�µķ���ȡƽ���ּ�Ϊ G1����ʦ�����������ּ�Ϊ G2��
����÷�Ϊ (G1+G2)/2�����������������������֡������Ҫ����д�����������ʦ����ÿ����Ļ����ɼ���

�����ʽ��

�����һ�и�������������N��> 3����M��
�ֱ��Ƿ����������֣���������100��
���N�У�ÿ�и�������õ���N������������֤Ϊ���ͷ�Χ�ڵ���������
���е�1������ʦ���������֣����� N-1 ����������������֡�
�Ϸ�������Ӧ����[0, M]�����ڵ������������ںϷ������ڣ���÷����뱻���ԡ�
��Ŀ��֤��ʦ�����ֶ��ǺϷ��ģ�����ÿ�������ٻ���3������ͬѧ�ĺϷ����֡�

�����ʽ��

Ϊÿ������������յ÷֡�ÿ���÷�ռһ�С�

����������
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
���������
42
33
41
31
37
39
*/

int main()
{
    int N,M,i,j,grade,G2;
    scanf("%d %d",&N,&M);
    int a[N];//c++11��׼
    for(i = 0; i < N; ++i)
    {
        int index = 0,sum = 0,max = 0,min = 51,temp;
        double ave,ans;
        memset(a,0,N);
        scanf("%d",&G2);//G2������ʦ������
        for(j = 1; j < N; ++j)
        {
            scanf("%d",&grade);
            if(grade >= 0 && grade <= M)
            {
                if(max < grade)
                    max = grade;
                if(min > grade)
                    min = grade;
                a[index++] = grade;
                sum += grade;
            }
        }
        sum -= (max + min);//��ȥ��ߺ����
        ave = (double)sum / (index - 2);//ƽ��ֵ
        temp = (ave + G2) / 2;//intֵ
        ans = (ave + G2)/2;//doubleֵ
        if(ans >= (temp + 0.5))
        {
            printf("%d\n",temp + 1);
        }
        else
            printf("%d\n",temp);
    }
	return 0;
}
