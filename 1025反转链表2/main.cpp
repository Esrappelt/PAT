#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <memory.h>
#include <string>
using namespace std;

int n,k;

typedef struct node
{
	int data;
	string address;
	string Nextaddress;
	struct node *next;
}Linknode,*Linklist;

void Init(Linklist &L)
{
	L = new Linknode;
	if(!L)
		return;
	L->next = NULL;
//	cout << "����ͷ���ĵ�ַ:" << endl;
	char ch[6];
	scanf("%s %d%d",&ch,&n,&k);
	L->address = ch;
	L->Nextaddress = "";
}
void create(Linklist &L)
{
	Init(L);
	Linklist p = L,q;
	int i;
	char ad[6],next[6];
	q = new Linknode;
	if(!q)
		return;
	for(i = 0; i < n; i++)
	{	
		q = new Linknode;
		if(!q)
			return;
//		cout << "����ý��ĵ�ַ���ý���ֵ����һ�����ĵ�ַ:" << endl;
		scanf("%s %d %s",&ad,&q->data,&next);
		q->address = ad;
		q->Nextaddress = next;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void Traverse(Linklist L)
{
	Linklist p = L->next;
	while(p)
	{
		cout << p->address << " " << p->data << " " << p->Nextaddress << endl;
		p = p->next;
	}
}

//��������
void Sort(Linklist &L)
{
	Linklist p = L->next->next,q,pre;
	L->next->next = NULL;
	while(p)
	{
		q = p->next;
		pre = L;
		while(pre->next && pre->next->data < p->data)//�ҵ���һ����p->data���ֵ Ȼ�����
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
	p = L;
	while(p->next)
		p = p->next;
	p->Nextaddress = "-1";
}

//��ת��������
void Reverseall(Linklist &L)
{
	Linklist p = L->next,q;
	L->next = NULL;
	while(p)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

//��ת����
void Reverse(Linklist &L)
{
	Linklist p = L->next,q,pre,r,temp;
	int t = k;
	if(t == 0 || t == 1 )//0��1����㲻�÷�ת
		return;
	while( (t--) && p)
	{
		pre = p;
		p = p->next;
	}
	q = p;
	//pre��p��ǰ��,q������p�ĺ��
	pre->next = NULL;//pre�Ƿ�ת�����һ�����
	p = temp = L->next;//temp�����һ�����
	L->next = NULL;
	while(p)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	temp->next = q;//q�Ƿ�ת��k�����֮��Ĳ���ת�Ľ��
//	cout<< "û�Ľ��ֵ֮ǰ:" << endl;
//	Traverse(L);
	Linklist m = L->next,h;
	if(q == NULL)
	{
		while(m->next != q)
		{
			h = m;
			m = m->next;
			h->Nextaddress = m->address;
		}
		Linklist g = L->next;
		while(g->next)
			g = g->next;
		g->Nextaddress = "-1";
	}
	else
	{
		while(m != q)
		{
			h = m;
			m = m->next;
			h->Nextaddress = m->address;
		}
		h->Nextaddress = m->address;
	}
//	cout << "�ı��ַ֮��:" << endl;
	Traverse(L);

}









int main()
{
	Linklist L;
	create(L);
//	cout << endl;
//	Traverse(L);
	Sort(L);
//	cout << endl;
//	Traverse(L);
	Reverse(L);
	return 0;
}


/*
����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת��
���磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)���Լ�������K(<=N)����Ҫ��ת���������ĸ�����
���ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/





/*

  //�ⷨ��:����Ľⷨ 
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int first,n,k,temp,i,j,l;
    int data[100005];
    int next[100005];
    int list[100005];
    int final[100005];
    scanf("%d %d %d", &first, &n, &k);
    for(i=0; i<n; i++)
    {
        scanf("%d", &temp);
        scanf("%d %d",&data[temp],&next[temp]);
    }
    l=0;
    while(first!=-1)
    {
        list[l] = first;
        l++;
        first = next[first];
    }
    for(i=0;i<l;i++)
    {
        final[i] = list[i];
    }
    for(i=0;i<(l-l%k);i++)
    {
        final[i] = list[(i/k)*k+k-i%k-1];
    }
    for(i=0;i<l-1;i++)
    {
        printf("%05d %d %05d\n",final[i],data[final[i]],final[i+1]);
    }
    printf("%05d %d %d\n",final[l-1],data[final[l-1]],-1);
    system("pause");
    return 0;
}
*/