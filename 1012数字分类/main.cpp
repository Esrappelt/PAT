/*
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���

�����ʽ��

�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N��
*/

#include<stdio.h>
#define Maxsize 10000
int main()
{
	int n,i,j;
	int cnt = 0,sum1 = 0,max = 0,b1 = 0,d1 = 0,sum2 = 0,c1 = 0;
	int a[Maxsize],sum = 0,b[Maxsize];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 0;i < n; i++)
	{
		j =a[i];
		if(j % 5 == 0 && j % 2 == 0 && j != 0)
		{
			sum +=j;
		}
		else if(j % 5 == 1 )
		{
			c1++;
			if(c1 % 2 != 0)
				sum2 += j;
			else
				sum2 -= j;
		}
		else if(j % 5 == 2)
			cnt++;
		else if(j % 5 == 3)
		{
			sum1 += j;
            d1++;
        }
		else if(j % 5 == 4)
		{
			b[b1++] = j;
		}
	}
	max = b[0];
	for(i = 0; i < b1; i++)
	{
		if(b[i] > max)
			max = b[i];
	}
	if(sum == 0)
		printf("N ");
	else
		printf("%d ",sum);
	if(sum2 == 0)
		printf("N ");
	else
		printf("%d ",sum2);
	if(cnt == 0)
		printf("N ");
	else
		printf("%d ",cnt);
	if(sum1 == 0)
		printf("N ");
	else
		printf("%.1f ",(double)(sum1 / d1));
	if(b1 == 0)
		printf("N");
	else
		printf("%d",max);
	return 0;
}


/*
�������ü��Ũ [�༭����] [�ǳ�]
��ҳ
��Ŀ��
������Ϣ
��Ŀ�б�
�ύ�б�
����
����
�鿴Դ����

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
#include <stdio.h>
#include <stdlib.h>
int main()
{
   // freopen("data1.txt","r",stdin);
    int cnt;
    scanf("%d",&cnt);

    int array[5] = {0};

    int i;
    int num,temp,temp1=1,cnt3=0,max = 0;
    int flag1 = 0, flag2 = 0, flag3= 0,flag4 = 0, flag5 = 0;
    for(i = 1; i <= cnt; i++){
        scanf("%d",&num);
        temp = num % 5;
        if(temp == 0 && num % 2 == 0)
            {flag1 = 1; array[0] += num;}
        if(temp == 1) {
            flag2 = 1;
            array[1] += ((temp1 % 2 != 0)? num:(-1*num));
            temp1++;
        }
        if( temp == 2){
            flag3 = 1;
            array[2]++;
        }
        if( temp == 3){
            flag4 = 1;
            cnt3++;
            array[3]+=num;
        }
        if( temp == 4){
            flag5 = 1;
            if(num > max) max = num;
        }
    }

    int h;
    if(flag1) printf("%d ",array[0]); else printf("%c ",'N');
    if(flag2) printf("%d ",array[1]); else printf("%c ",'N');
    if(flag3) printf("%d ",array[2]); else printf("%c ",'N');
    if(flag4) printf("%.1f ",1.0*array[3]/cnt3); else printf("%c ",'N');
    if(flag5) printf("%d",max);else printf("%c",'N');


    return 0;
}
˫������������Բ鿴δ��ʽ����ԭʼ����


�鿴�ύ*/