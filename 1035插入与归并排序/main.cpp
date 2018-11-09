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

//��ʾ����
void show(const vector<int> a)
{
    int i,n = a.size();
    for(i = 0; i < n; ++i)
    {
        cout << a[i];
        if(i < n - 1)
            cout << ' ';
    }
    cout << endl;
}
//�жϺ���
bool judge(const vector<int> a,const vector<int> b)
{
    int i,n = a.size();
    for(i = 0; i < n; ++i)
    {
        if(a[i] != b[i])
            return false;//�ȶ�ʧ��
    }
    return true;//�ȶԳɹ�
}
//���ڲ�������
bool Insert(const vector<int> x,const vector<int> y)
{
    int i,j,temp;
    vector<int> a(x),b(y);
    int n = a.size();
    for(i = 1; i < n; ++i)
    {
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j+1] = a[j];
        a[j+1] = temp;
        //��ʼ�ȶ�
        if(judge(a,b))//�ȶԳɹ�,�ٶ�b����һ�ֲ�������
        {
            sort(b.begin(),b.begin()+ i + 2);
            cout << "Insertion Sort" << endl;
            show(b);
            return true;
        }
    }
    return false;
}

//���ڹ鲢����
void Merge(const vector<int> x,const vector<int> y)
{
    vector<int> a(x),b(y);
    int i,n = a.size(),cnt = 1,flag = 1;
    while(flag)//�ȶԳɹ����˳�
    {
        flag = 0;
        if(!judge(a,b))//���бȶ�
            flag = 1;
        cnt  = cnt * 2;
        for(i = 0; i < n / cnt; ++i)//���������ż������պ���ż���ԵĹ鲢��������һ��,�����һ�������ᴦ��
            sort(a.begin()+ i * cnt,a.begin() + i * cnt + cnt);
        //Ȼ�������������������Ҫ����һ�����һ����
        for( i = cnt * ( n / cnt); i < n; i++ ) // �� ��ż�����н�������
            sort( a.begin()+ cnt * (n / cnt ), a.begin() + n );
    }
    cout << "Merge Sort" << endl;
    show(a);
}
//������
int main()
{
    int N,i,temp,tag = 0;
    vector<int> a,b;//a��ԭ����,b���м��������������
    cin >> N;
    for(i = 0; i < N; ++i)
    {
        cin >> temp;
        a.push_back(temp);
    }
    cin.clear();
    for(i = 0; i < N; ++i)
    {
        cin >> temp;
        b.push_back(temp);
    }
    if(Insert(a,b))
        tag = 1;
    if(!tag)
        Merge(a,b);//���ֱ�����������������ָ������
	return 0;
}
//ע��
/*
���������ǵ����㷨����һ����������ݣ��𲽲��������������С�ÿ�������У��㷨������������ȡ��һԪ�أ���֮����������������ȷ��λ�á���˵���ֱ��ȫ��Ԫ������

�鲢����������µ������������Ƚ�ԭʼ���п���N��ֻ����1��Ԫ�ص����������У�Ȼ��ÿ�ε����鲢�������ڵ����������У�ֱ�����ֻʣ��1����������С�

�ָ���ԭʼ���к���ĳ�����㷨�������м����У������жϸ��㷨���������������㷨��

�����ʽ��

�����ڵ�һ�и���������N (<=100)��
���һ�и���ԭʼ���е�N�����������һ�и�����ĳ�����㷨�������м����С�������������Ŀ���������������ּ��Կո�ָ���

�����ʽ��

�����ڵ�1���������Insertion Sort����ʾ�������򡢻�Merge Sort����ʾ�鲢����
Ȼ���ڵ�2��������ø������㷨�ٵ���һ�ֵĽ�����С���Ŀ��֤ÿ����ԵĽ����Ψһ�ġ����ּ��Կո�ָ�������ĩ�����ж���ո�
��������1��
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
�������1��
Insertion Sort
1 2 3 5 7 8 9 4 6 0
��������2��
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
�������2��
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
