#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
ĳ��������˿��ղ飬�õ���ȫ���������ա�������д�������ҳ��������곤����������ˡ�

����ȷ��ÿ����������ڶ��ǺϷ��ģ�����һ���Ǻ���ġ���������֪����û�г���200������ˣ�
��������2014��9��6�գ����Գ���200������պ�δ���������ն��ǲ�����ģ�Ӧ�ñ����˵���

�����ʽ��

�����ڵ�һ�и���������N��ȡֵ��(0, 10^5]�����N�У�ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ�������
�Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա���Ŀ��֤���곤�����������û�в��С�

�����ʽ��

��һ����˳�������Ч���յĸ��������곤�˺��������˵�����������Կո�ָ���
*/


bool bigger(char *a,char *b)//�ж�a��b�����¹�ϵ:a�󷵻��棬b�󷵻ؼ�
{
	int i;
	for(i = 0; i < 10; i++)
	{
		if(a[i] > b[i])
			return true;
		else if(a[i] < b[i])
			return false;
	}
	return false;
}
//�ܽ�:�ж����·ݿ���ֱ����Ӧ���********

int main()
{
	char a[20],b[20],old[20],young[20],small[20] = "1814/09/05",bigyear[20] = "2014/09/07";//young����ʱ����С���ˣ�old��ʱ������
	int N,valid = 0,i,cnt = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		scanf("%s %s",&a,&b);//����������
		if(bigger(b,"1814/09/05") && bigger("2014/09/07",b))
		{
			cnt++;//ֱ�ӿ����Ƿ�������ĿҪ��
			if(bigger(b,small))//b��small��
			{
				strcpy(small,b);
				strcpy(old,a);//��������
			}
			if(bigger(bigyear,b))//b��bigyearС
			{
				strcpy(bigyear,b);
				strcpy(young,a);
			}
		}
	}
	if(cnt)
	{
		cout << cnt << " " << young << " " << old;
	}
	else
		cout << "0";
	return 0;
}