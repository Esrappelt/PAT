#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	char c;
	int a[1000];
	int carry = 0,len,i = 0,b;//carry�Ǳ�����һλ�������������µ���һλ
	while(( c = getchar() ) != '\n' )
		a[i++] = c - '0';//ֱ��ת��Ϊ��������
	len = i;
	scanf("%d", &b);//b�ǳ���
	for(i = 0; i < len; i++)
	{
		if(i != 0 || a[i] / b != 0)
		{
			printf("%d",(10 * carry + a[i]) / b);//10*����+��ǰ���ٳ���b������,carry== 0ʱ����a[i]/b
		}
		carry = (10 * carry + a[i]) % b;//ֱ��ȡ��õ�����
	}
	if(len == 1 || a[0] / b == 0)//ֻ��1��Ԫ��  �����ǵ�һ��Ԫ�س���bΪ0
		printf(" %d",carry);//ֱ���������	
	return 0;
}