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
�����ڵ�һ�и�������������N��<=1000����M��<=100�����ֱ���ѧ�������Ͷ�ѡ��ĸ�����
���M�У�ÿ��˳�θ���һ���������ֵ��������5������������
ѡ�������������2�Ҳ�����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�
ע��ÿ���ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ������N�У�ÿ�и���һ��ѧ���Ĵ��������
��ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)��������Ŀ˳�������ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ�
��������ѡ�е�ѡ��������ʵ��ѡ�����������

�����ʽ��

���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�У����С�����1λ��
���������������Ŀѡ�����Ϣ����ʽΪ����������� ��Ŀ��ţ���Ŀ���������˳���1��ʼ��ţ�-ѡ��š���
����в��У���ÿ��һ��ѡ�����Ŀ��ŵ���˳��������ٲ�����ѡ��ŵ���˳�����������β�����ж���ո�
���������Ŀ��û���˴��������һ�������Too simple����

��������1��
3 4

3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e

(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)

�������1��
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b

struct student{
    string select;
    int fullgrade;
    int allnum;
};

int count1[1000][1000];//��Ŵ�
int count2[1000];//���ѡ���

int main()
{
    char op;
    string judge;
    int N,M,i,j,k;//N��ѧ������,M�Ƕ�ѡ��ĸ���
    scanf("%d%d",&N,&M);
    vector<student> stu;
    vector<string> ans;//���ַ���
    student temp;
    for(i = 0; i < M; ++i)
    {
        cin >> temp.fullgrade >> temp.allnum >> temp.select;//select����ȷ�Ĵ�
        for(j = 0; j < temp.select.length(); ++j)
            count1[i][++temp.select[j]];
   //     ans.push_back(temp.select);
        stu.push_back(temp);
    }
    for(k = 0; k < N; ++k)//N��ѧ��
    {
        for(i = 0; i < M; ++i)//M����
        {
            scanf("%c",&op);
            if(op == '(')
            {
                getline(cin,judge,')');//��')'����������')',judge�������ַ���
                memset(count2,0,1000);//��ʼ��count2
                for(j = 0; j < stu[i].select.length(); ++j)
                {
                    if(--count1[i][judge[j]])
                    {
                        count2[judge[j]]++;//
                    }
                }

            }
        }
    }
}
*/
#define MAX_M 100
#define MAX_OPTIONS 5

int readanswer()
{
    char c;
    int answer = 0, count;
    scanf("%d", &count);
    for(int i = 0; i < count; i++)
    {
        while((c = getchar()) == ' ');
        answer |= 1 << (c - 'a');
    }
    return answer;
}

int main()
{
    int N, M, full_score[MAX_M] = {0}, correct_ans[MAX_M] = {0},
        wrong_ans[MAX_M] = {0}, wrong_count[MAX_M][5] = {{0}},
        wrong_count_max = 0;

    scanf("%d %d", &N, &M);
    /* Read M lines */
    int count_options;
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", full_score + i, &count_options);
        correct_ans[i] = readanswer();
    }

    /* Read N lines */
    for(int i = 0; i < N; i++)
    {
        float score = 0;
        int answer;
        for(int j = 0; j < M; j++)
        {
            while(getchar() != '(');
            answer = readanswer();
            wrong_ans[j] = answer ^ correct_ans[j];

            if(wrong_ans[j] == 0)               /* all correct */
                score += full_score[j];
            else if((wrong_ans[j] | correct_ans[j]) == correct_ans[j])
                score += 0.5 * full_score[j];   /* partially corrent */

            /* For every option, record the number of students got wrong */
            for(int k = 0; k < MAX_OPTIONS; k++)
            {
                wrong_count[j][k] += wrong_ans[j] >> k & 1; /* k-th bit */
                if(wrong_count[j][k] > wrong_count_max)
                    wrong_count_max = wrong_count[j][k];
            }

            while(getchar() != ')');
        }
        printf("%.1f\n", score);
    }

    if(wrong_count_max == 0)
        printf("Too simple");
    else
        for(int i = 0; i < M; i ++)
            for(int j = 0; j < MAX_OPTIONS; j++)
                if(wrong_count[i][j] == wrong_count_max)
                    printf("%d %d-%c\n", wrong_count_max, i + 1, j + 'a');

    return 0;
}










