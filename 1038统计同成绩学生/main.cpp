#include <stdio.h>
#include <iostream>
using namespace std;

int count[101];//�ٷ���
int grade[100000];

int main()
{
	int N,k,i,score,cnt = 0;
	cin >> N;
	for(i = 0; i < N; i++)
	{
		scanf("%d",&score);
		count[score]++;
	}
	scanf("%d",&k);
	for(i = 0; i < k; i++)
	{
		scanf("%d",&grade[i]);
	}
	for(i = 0; i < k; i++)
	{
		if(i == k - 1)
			cout << count[grade[i]];
		else
			cout << count[grade[i]] << " ";
	}
	return 0;
}

/*
����Ҫ�����N��ѧ���ĳɼ��������ĳһ����������ѧ�����������

�����ʽ��

�����ڵ�1�и���������10^5��������N����ѧ����������
���1�и���N��ѧ���İٷ��������ɼ����м��Կո�ָ������1�и���Ҫ��ѯ�ķ�������K��������N�����������������K���������м��Կո�ָ���

�����ʽ��

��һ���а���ѯ˳������÷ֵ���ָ��������ѧ���������м��Կո�ָ�������ĩ�����ж���ո�
*/