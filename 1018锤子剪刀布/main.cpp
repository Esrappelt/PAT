#include <iostream>
#include <stdio.h>
using namespace std;
/*
�����1�и���������N��<=105������˫������Ĵ���
�����N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B����������
��1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��

�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ���
��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣

*/
int A[256],B[256];
int main()
{
	char a,b;
	int n,i,j;
	int awin = 0,ping = 0,afail = 0;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;//a�Ǽ�,//b����
		if(a == b)
		{
			ping++;
		}
		else
		{
			if(a == 'C')
			{
				if(b == 'J')
				{
					awin++;
					A[67]++;
				}
				else if(b == 'B')
				{
					afail++;
					B[66]++;		
				}
			}
			else if(a == 'J')
			{
				if(b == 'B')
				{
					awin++;
					A[74]++;
				}
				else if(b == 'C')
				{
					afail++;
					B[67]++;
				}
			}
			else if(a == 'B')
			{
				if(b == 'C')
				{
					awin++;
					A[66]++;
				}
				else if(b == 'J')
				{
					afail++;
					B[74]++;
				}
			}
		}
	}
	if(A[67] == A[74] && A[74] == A[66])
		i = 66;
	else
	{
		i = A[67] >= A[74] ? 67:74;
		i = A[i] > A[66] ? i : 66;
	}
	if(B[67] == B[74] && B[74] == B[66])
		j = 66;
	else
	{
		j = B[67] >= B[74] ? 67:74;
		j = B[j] > B[66] ? j : 66;
	}
	printf("%d %d %d\n",awin,ping,afail);
	printf("%d %d %d\n",afail,ping,awin);
	printf("%c %c\n",i,j);
	return 0;
}

