#include <stdio.h>
#define Maxsize 1 << 20
#define INF 1000000
int count = 0;
int prime[Maxsize];
int p[Maxsize];
void Prime(int n)
{
	int i,j,count = 0,flag = 1,top = 0;
	for(i = 2; i <= n; i++)
	{
		if(p[i] == 0)//�������ж��ǲ�������
		{
			prime[top++] = i;
		}
		for(j = 0; j < top && i * prime[j] <= n; j++)
		{
			p[i*prime[j]] = 1;//�Ѿ�����������
			if(i % prime[j] == 0)//�ܹ������Ͳ��������ˣ�һ����ס������ſ�ʼ�ж��ǲ�������,�ڽ���ɸѡ
				break;
		}
	}
}
int main()
{
	int m,n,i;
	scanf("%d%d",&m,&n);
	Prime(INF);
	for(i = m; i <= n; i++)
	{
		printf("%d",prime[i-1]);
        if ((i - m + 1) % 10 == 0 || i == n)
            printf("\n");
		else
            printf(" ");
    }
	return 0;
}