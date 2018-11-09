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

int cnt = 0;

bool judge(const string a)
{
    int i = 0,j = a.length() - 1;
    while(i < j)
    {
        if(a[i] != a[j])
            return false;
        ++i;
        --j;
    }
    return true;
}
void bigIntergerAdd(string &num)
{
    if(cnt == 10)
    {
        printf("Not found in 10 iterations.");
        return;
    }
    string ans(num);
    string add(num);
    reverse(add.begin(),add.end());
    int goBit = 0; // ��Ž�λ
    // ����string��+������
    for (int i = num.length() -1 ; i >= 0; --i)
    {
        int tmp =  ((num[i] - '0') + (add[i] - '0') + goBit) ;//�����������
        num[i] = tmp % 10 + '0';//Ȼ�����10��ֻ������������ת��Ϊ�ַ���
        goBit = tmp / 10;//��λ
    }
    // �����������
    if (goBit != 0)
        num.insert(0, "1");//��0��λ�ò���"1"
    cout << ans << " + " << add << " = " << num << endl;
    if( judge(num) )
        cout << num << " is a palindromic number." << endl;
    else
    {
        cnt++;
        bigIntergerAdd(num);
    }
}

int main()
{
    string a;
    getline(cin,a,'\n');
    if( judge(a) )
        cout << a << " is a palindromic number." << endl;
    else
        bigIntergerAdd(a);
	return 0;
}
