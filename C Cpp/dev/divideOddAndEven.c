/*��һ�����ֵΪ��Ȼ���ĵ�������Ϊ����������ԭ���б���ֵΪż��
�Ľ�㣬��ֵΪ�����Ľ�㰴������ԭ���е���Դ������һ���µĵ�����*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print(node *head)
{
	node *p = head->next;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

void divide(node *head, node *odd)
{
	node *p = head->next;
	node *pre = head;	
	node *q;
	int flag = 1; /*�жϽ���Ƿ�����������head��ָ��*/
	while(p)
	{
		if(p->info % 2)
		{
			p = p->next;
			if(flag)
			{
				odd->next = pre->next;
				pre->next = pre->next->next;
				odd->next->next = NULL;
				q = odd->next;
				flag = 0;
			}
			else
			{
				q->next = pre->next;
				pre->next = pre->next->next;
			 	q->next->next = NULL;
				q = q->next;
			}
		}
		pre = p; 
		p = p->next; 
	}
}

int main()
{
	node *head = (node*)malloc(sizeof(node));
	node *odd = (node*)malloc(sizeof(node));
	node *p = (node*)malloc(sizeof(node));
	node *curr = p, *q;
	head->next = p;
	p->info = 1;
	int i;
	for(i = 2; i <= 20; i++)
	{
		q = (node*)malloc(sizeof(node));
		q->info = i;
		q->next = NULL;
		curr->next = q;
		curr = q;
	}
	print(head);
	divide(head, odd);
	printf("even number :\n");
	print(head);
	printf("odd number :\n");
	print(odd);
	return 0;	
} 
