/*��һ���������еĽ�����*/
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct link_node{
	datatype info;
	struct link_node *next;
} node;

void print_list(node *head)
{
	node *p = head;
	while(p)
	{
		printf("%d\t", p->info);
		p = p->next;
	}
	printf("\n");
}

int node_number(node *head)
{
	int num = 0;
	node *p = head;
	while(p)
	{
		num++;
		p = p->next;
	}
	return num;
}

int main()
{
	node *first = (node*)malloc(sizeof(node));
	node *head = first; 
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
	printf("the number of node is %d\n", node_number(head));
	return 0;	
} 
