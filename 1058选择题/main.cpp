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
�����ڵ�һ�и�������������N��<=1000����M��<=100�����ֱ���ѧ�������Ͷ�ѡ��ĸ��������M�У�ÿ��˳�θ���һ���������ֵ��������5������������ѡ�������������2�Ҳ�����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ���ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ������N�У�ÿ�и���һ��ѧ���Ĵ����������ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)��������Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������

�����ʽ��

���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�С�ע������ʱֻ��ѡ��ȫ����ȷ���ܵõ�����ķ��������һ��������������Ŀ�Ĵ�������ͱ�ţ���Ŀ���������˳���1��ʼ��ţ�������в��У��򰴱�ŵ���˳����������ּ��ÿո�ָ�������β�����ж���ո����������Ŀ��û���˴��������һ�������Too simple����

����������
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (2 b d) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (2 b c) (4 a b c d)
���������
3
6
5
2 2 3 4
*/
int count_all[100];

void show(const int &s)
{
    cout << s << endl;
}
int main()
{
    char op;
    int i,k,stu_num,pro_num;
 //   cout << "����ѧ�������Ͷ�ѡ����:" << endl;
    cin >> stu_num >> pro_num;
    cin.get();
    vector<string> temp(pro_num);
    vector<string> a(pro_num);
    vector<int> ans(stu_num);
    vector<int> allansnum(pro_num);
    vector<int> lastans(pro_num);
    vector<int> selectnum(pro_num);
 //   cout << "������������ֵ��ѡ���������ȷѡ���������ȷ��ѡ��:" << endl;
    for(i = 0; i < pro_num; i++)
    {
      //  cout << "��������ֵ��ѡ�����:";
        cin >> allansnum[i] >> selectnum[i];
        getchar();//����
      //  cout << "��ȷѡ���������ȷѡ��(�ַ���):" << endl;
        getline(cin,a[i]);//�𰸸����Ӵ�ѡ��
    }
    int sum,num;
    for(k = 0; k < stu_num; ++k){
            sum = 0;
        for(i = 0; i < pro_num; ++i){
            num = 0;
            scanf("%c",&op);
            if(op == '(')
            {
                getline(cin,temp[i],')');
                if(temp[i] == a[i])
                {
                    sum += allansnum[i];
                }
                else
                {
                    count_all[i]++;
                }
            }
            getchar();//����
        }
        ans[k] = sum;
    }
    int max = -1,flag = 0,m = 0,l = 0,flag2 = 0;
    k = 0;
    for(i = 0; i < pro_num; ++i)
    {
        if(max < count_all[i])
        {
            max = count_all[i];
            m = i;
        }
    }
    for_each(ans.begin(),ans.end(),show);

    for(i = 0; i < pro_num; i++)
    {
        if(count_all[i] == max && max)
            k++;
    }
    if(k == 0)
        cout << "Too simple" << endl;
    else if(k == 1)//ֻ��һ�����ֵ
    {
        cout << max << " " << m + 1 << endl;
    }
    else
    {
        cout << max << " ";
        for(i = 0; i < pro_num; ++i)
        {
            if(count_all[i] == max && count_all[i])
            {
                if(k == 1)
                    cout << i + 1 << endl;
                else
                    cout << i + 1 << " ";
                --k;
            }
            else if(!count_all[i])
                flag = 1;
        }
        if(flag)
            cout << "Too simple" << endl;
    }
	return 0;
}









