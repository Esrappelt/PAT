#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*
����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ

  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
*/

typedef struct node
{
	char name[10000];
	char number[10000];
	int score;
	struct node *next;
}Listnode,*Linklist;
void InitList(Linklist &stu)
{
	stu = (Linklist)malloc(sizeof(Listnode));
	if(!stu)
		return;
	stu->next = NULL;
}
void CreateList(Linklist &stu,int n)
{
	char name[10000],number[10000];
	int score;
	Linklist q = NULL,p = stu;
	if(n < 0 || n > 100)
	{
		printf("��������!");
		return;
	}
	int i = 0;
	for(i = 1; i <= n; i++)
	{
		q = (Linklist)malloc(sizeof(Listnode));
		if(!q)
			return;
		scanf("%s%s%d",&name,&number,&score);
		strcpy(q->name,name);
		strcpy(q->number,number);
		q->score = score;
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void Traverse(Linklist stu)
{
	Linklist p = stu->next,q;
	printf("%s %s\n",p->name,p->number);
	while(p)
	{
		q = p;
		p = p->next;
	}
	printf("%s %s\n",q->name,q->number);
}
void Sort(Linklist &stu)
{
	Linklist p = stu->next->next,pre = NULL,q = NULL;
	stu->next->next = NULL;
	while(p)
	{
		q = p->next;
		pre = stu;
		while(pre->next && pre->next->score > p->score)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
	
}
int main()
{
	int n;
	Linklist stu;
	InitList(stu);
	scanf("%d",&n);
	CreateList(stu,n);
	Sort(stu);
	Traverse(stu);
	return 0;
}


