#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//�ⷨһ
int a[10000][10000];
int ans[10000];
int num = 1, m, n, N;
int dx[4] = { 0, 1, 0, -1 };	// �ң��£�����
int dy[4] = { 1, 0, -1, 0 };

int check(int x, int y)
{
	return (x <= m && y <= n && (!a[x][y]) && x > 0 && y > 0);//С��m��С��n��
}
int cmp(int x,int y)
{return x >y;}

void dfs(int x, int y, int di)
{
	if(num == N)
		return;
	int xx, yy, i;
	for (i = di; i < di + 4; i++)	// ����ÿ�ζ�ѭ��4�μ�Ѱ���ĸ���λ
	{
		xx = x + dx[i % 4];
		yy = y + dy[i % 4];
		printf("(x = %d + dx= %d) ,(y = %d + dy = %d) ,xx = %d, yy = %d ",x,dx[i%4],y,dy[i%4],xx,yy);
		if (check(xx, yy))//û�з��ʹ���(û��������)���Ҳ����Ե�
		{	
			a[xx][yy] = ans[++num];
			printf("a[%d][%d]=%d \n",xx,yy,a[xx][yy]);
			dfs(xx, yy, i % 4);
			num--;
		}
		else
			printf("������������Ѿ����ʹ���!\n");
	}
}

int main()
{
	int i, j, k = 0, min = 10001;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &ans[i]);
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i >= j && i * j == N)
			{
				if (abs(i - j) < min)
				{
					min = abs(i - j);
					m = i;
					n = j;
				}
				break;
			}
		}
	}
    sort(ans +1,ans + N +1,cmp);
	for (i = 0; i <= N + 1; i++)
	{
		a[i][0] = -1;
		a[0][i] = -1;
		a[i][N + 1] = -1;
		a[N + 1][i] = -1;
	}// Ϊ���ı߽���ı�ǽ
	
	a[1][1] = ans[1];
	for(i = 0; i <= N + 1; ++i)
	{
		for(j = 0; j <= N + 1; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	dfs(1, 1, 0);
	cout << endl;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; ++j)
		{
			if(j == n)
				printf("%d", a[i][j]);
			else
				printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*

//�ⷨ��:
#include <iostream> 
#include <algorithm>
#include <cmath> 
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std; 

int compare(int a,int b) { return a > b; }


int A[10000];
int T[10000][10000];

void solve()
{
	int i,j,k,N;
	cin >> N; 
	for(i = 0; i < N; i++)
	{ 
		cin >> A[i]; 
	}
	sort(A, A + N, compare); //��sqrt��n������Ѱ������n 
	int m, n = sqrt(N);
	while(N % n)
		n --; 
	m = N / n; 
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, di = 0; 
	i = 0;
	j = 0;
	k = 0; 
	do
	{ 
		T[i][j] = A[k++]; //�൱����Ϊ����,�������
		int ni = i + dx[di], nj = j + dy[di];//������1.x����(y+1) 2.x+1 Ȼ�� y ����  3.x ���� y-1 4.���(x-1)  y����    
		if(ni < 0 || ni >= m || nj < 0 || nj >= n || T[ni][nj])//�����������  �����Ѿ����������  �Ǿͼ�������һ����λ
			di = (di + 1) % 4;//��4����λ
		i += dx[di];//
		j += dy[di];//
	}while(k < N); 

	for(i = 0; i < m; i ++)
	{	
		for(int j = 0; j < n; j ++)
		{	
			cout << T[i][j];
			if(j + 1 < n) cout << " "; 
		} 
		cout << endl;
	} 
} 
int main() 
{
	solve(); 
	return 0; 
}
*/