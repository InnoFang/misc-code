/*�ڵ�������ֵΪy�Ľ��ǰ�����һ��ֵΪx�Ľ��*/
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

/*�ҵ�ֵΪdata�Ľ���ǰһ�����*/
node *findTheLast(node *head, datatype data)
{
	node *p = head;
	while(p->next && p->next->info != data)
	{
		p = p->next;
	}
	return p; 
}

/*��ֵΪy�Ľ��ǰ�����ֵΪx�Ľ��*/
node *insert(node *head, int y, int x)
{
	node *index;
	node *q;	/*Ҫ����Ľ��*/
	index = findTheLast(head, y);
	if(NULL == index)
	{
		printf("�Ҳ���ֵΪ%d�Ľ��\n", y);		
	}
	else 
	{
		q = (node*)malloc(sizeof(node));
		q->info = x;
		q->next = index->next;
		index->next = q;
		printf("q = %d\n", q->info);
	}
	return head;
}

int main()
{
	node *first = (node*)malloc(sizeof(node));
	node *head = (node*)malloc(sizeof(node));	/*ͷ���*/ 
	head->next = first;	
	node *curr = first;	/*��ǰ���*/ 
	node *a = NULL;	/*���淵�صĽ��*/
	datatype data;	/*���ݻ�ȡ*/ 
	int flag = 1;	/*�жϵ�һ������Ƿ���ֵ*/
	int y, x;	
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
	printf("������y����x����ֵ\n"); 
	scanf("%d%d",&y,&x);
	insert(head, y, x);
	print_list(head);
	return 0;
}
