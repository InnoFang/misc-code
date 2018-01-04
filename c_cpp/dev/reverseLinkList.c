/*���õ�����ԭ���Ľ��ռ���תһ��������*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print_list(node *head)
{
	node *p = head->next;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

node *reverse(node *head)
{
	node *p, *q;
	p= head->next;
	q = head->next;
	head->next = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
	return head;
}

int main()
{
	node *first = (node*)malloc(sizeof(node));
	node *head = (node*)malloc(sizeof(node));	/*ͷ���*/ 
	head->next = first;
	node *curr = first;	/*��ǰ���*/ 
	datatype data;	/*���ݻ�ȡ*/ 
	int flag = 1;	/*�жϵ�һ������Ƿ���ֵ*/
	while(scanf("%d", &data) != EOF && data != 0)
	{
		if(flag)
		{
			first->info = data;	
			flag = 0;
		}	
		else 
		{
			node *p = (node*)malloc(sizeof(node));
			if(NULL == p)
				break;
			p->info = data;
			p->next = NULL;
			curr->next = p;
			curr = p;
		}
	}
	print_list(head);
	reverse(head);
	print_list(head);
	return 0;	
} 
