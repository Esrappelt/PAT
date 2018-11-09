#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
/*
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�

�õ�������ȷ���������ǣ�

1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ����������ǽ�����ĸ A ��ɵ��ַ�����

���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�
�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�

�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��
*/
#define Maxsize 100
bool flagall[Maxsize] = {true};

int main()
{
	int n,k,i;
	scanf("%d",&n);
	char str[Maxsize];
	getchar();
	for(k = 0; k < n; k++)
	{
		int lenstr,numP = 0,numA = 0,numT = 0;
		int loca = 0,locp = 0,loct = 0;
		gets(str);
		lenstr = strlen(str);
		for(i = 0; i < lenstr; i++)
		{
			if(str[i] == 'P')
			{
				locp = i;
				numP++;
			}
			if(str[i] == 'A')
			{
				loca = i;
				numA++;
			}
			if(str[i] == 'T')
			{
				loct = i;
				numT++;
			}
		}
		if( (numA + numP + numT) != lenstr || numP > 1 || numT > 1 || loct - locp <= 1 || (lenstr - loct - 1) != locp * ( loct - locp - 1) )
		//  1.P A T�����ַ�����������Ҫ�����ַ�������
		//  2.P��T���ַ��м������һ��A,����P��λ��ֻ����T��λ��֮ǰ
		//  3.(loct - locp - 1)����P-T֮��ĳ���,��P-T�м�A�ĸ���,locp����Pǰ���ж��ٸ������������⼴ΪA�ĸ���
		//	4.Ȼ�� (lenstr - loct - 1)����T-lenstr֮��ĳ���,�������⼴ΪT�����A�ĸ���
		//  5.���ݹ��ɿ�֪:P-T֮��ÿ��һ��A,Pǰ���T����Ҳͬʱ����һ��A,Ҳ������������P,��Pǰ���A�ĸ�������P-T֮���A�ĸ�������T�����A�ĸ���
			flagall[k] = false;
		else
			flagall[k] = true;
	}
	for(i = 0; i < n; i++)
	{
		if(flagall[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
