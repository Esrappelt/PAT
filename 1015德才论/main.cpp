#include <cstdio>
#include <cmath>
#include<ctime>
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
�����1�и���3����������
�ֱ�Ϊ��N��<=105����������������L��>=60����Ϊ¼ȡ��ͷ����ߣ�


���·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��H��<100����
Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ�������
�ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮��
�²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮��
�����ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��


���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ�������²ŷ�Ϊ����[0, 100]�ڵ����������ּ��Կո�ָ���

�����ʽ��

�����1�����ȸ����ﵽ��ͷ����ߵĿ�������M�����M�У�ÿ�а��������ʽ���һλ��������Ϣ��
������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У����·�Ҳ���У���׼��֤�ŵ����������
*/
struct student{
    string id;
    int moral;
    int talent;
};

bool compare(const student s1,const student s2)//�ܽ᣺��Ҫ���������ʱ��  ֻ��Ҫ�Ƚ����������Ĵ�С����������
{
    if(s1.moral + s1.talent == s2.moral + s2.talent)//�ܷ���ͬ
    {
        if(s1.moral == s2.moral)
        {
            return s1.id < s2.id;//id����:���С���ұߴ�������
        }
        else
            return s1.moral > s2.moral;
    }
    return s1.moral + s1.talent > s2.moral + s2.talent;//��������:��ߴ����ұߴ�����
}
void show(const student &iter)
{
    printf("%s %d %d\n",iter.id.c_str(),iter.moral,iter.talent);
//    cout << iter.id << ' ' << iter.moral << ' ' << iter.talent << endl;//��ʱ
}

int main()
{
    vector<student> ans1,ans2,ans3,ans4;//�ṹ������
    int N,L,H;
    int RightPeople = 0;
    student temp;
//    cin >> N >> L >> H;//��ʱ
    scanf("%d%d%d",&N,&L,&H);
    int i;
    for(i = 1; i <= N; ++i)
    {
        cin >> temp.id;
        scanf("%d%d",&temp.moral,&temp.talent);
  //      cin >> temp.id >> temp.moral >> temp.talent;//��ʱ
        getchar();
        if(temp.moral >= L && temp.talent >= L)//��������ͷ�����
        {
            if(temp.moral >= H && temp.talent >= H)//��һ��:�ŵ�ȫ��
                ans1.push_back(temp);
            else if(temp.moral >= H && temp.talent < H)//�ڶ���:��ʤ��
                ans2.push_back(temp);
            else if(temp.moral < H && temp.talent < H && temp.moral >= temp.talent)//������:�ŵ¼�������ʤ��
                ans3.push_back(temp);
            else//�����ﵽ��ͷ����ߵ�
                ans4.push_back(temp);
            ++RightPeople;
        }
    }
    sort(ans1.begin(),ans1.end(),compare);
    sort(ans2.begin(),ans2.end(),compare);
    sort(ans3.begin(),ans3.end(),compare);
    sort(ans4.begin(),ans4.end(),compare);
    printf("%d\n",RightPeople);
    for_each(ans1.begin(),ans1.end(),show);//����
    for_each(ans2.begin(),ans2.end(),show);
    for_each(ans3.begin(),ans3.end(),show);
    for_each(ans4.begin(),ans4.end(),show);
	return 0;
}








