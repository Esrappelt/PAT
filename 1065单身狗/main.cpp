#include <iostream>
//#include <algorithm>
#include <stdio.h>
using namespace std;
/*
�����һ�и���һ��������N��<=50000��������֪����/���µĶ���
�����N�У�ÿ�и���һ�Է���/���¡���Ϊ���������ÿ�˶�Ӧһ��ID�ţ�Ϊ5λ���֣���00000��99999����ID���Կո�ָ���
֮�����һ��������M��<=10000����Ϊ�μ��ɶԵ������������һ�и�����Mλ���˵�ID���Կո�ָ�����Ŀ��֤�����ػ��Ų���������

�����ʽ��

���ȵ�һ������䵥���˵������������ڶ��а�ID����˳���г��䵥�Ŀ��ˡ�ID����1���ո�ָ����е���β�����ж���ո�

����������
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
���������
5
10000 23333 44444 55555 88888

*/

typedef struct 
{
	int id;
	int wifeid;
}People;

int flag[99999];
int count[99999];//ȫ��Ϊ0
People p[99999];

int main()
{
	int N,i,M,id[10001],tag,temp,cnt = 0,j,k = 0,ans[10001];
	cin >> N;
	for(i = 0; i < N; i++)
	{
		scanf("%d%d",&p[i].id,&p[i].wifeid);
		count[p[i].id] = count[p[i].wifeid] = i + 1;//���޺��ɷ��ֵ��ͬ
	}
	cin >> M;
	for(i = 0; i < M; i++)
	{
		scanf("%d",&id[i]);//����Ҫ������
	}
	for(i = 0; i < M; i++)
	{
		if(flag[id[i]] == 1)
    		continue;
		temp = count[id[i]];//temp����count[���޻����ɷ�]��ֵ,��һ����count[55555] = 3
		tag = 1;
		if(temp == 0)//û�з���
		{
			flag[id[i]] = 1;
			ans[k++] = id[i];
			cnt++;
		}
		else	
		{
			for(j = i + 1; j < M; j++)//id[i+1]��44444
			{
				if(flag[id[j]] == 0)//flag[44444] = 0,count[44444] = 2
				{
					if(count[id[j]] == temp)//�ҵ��˷���
					{
						flag[id[j]] = 1;
						tag = 0;
						break;
					}
				}
				
			}
			if(tag)//û�ҵ�
			{
				cnt++;
				ans[k++] = id[i];
			}
		}	
	}
    for (j = 0; j < k - 1; j++)
	{
		for (i = 0; i < k - 1 - j; i++)
        {
            if(ans[i] > ans[i + 1])
            {
                temp = ans[i];
                ans[i] = ans[i + 1];
                ans[i + 1] = temp;
            }
        }
	}
	cout << cnt << endl;
	for(i = 0; i < k; i++)
	{
		if(i == k - 1)
			printf("%05d\n",ans[i]);
		else
			printf("%05d ",ans[i]);
	}
	return 0;
}