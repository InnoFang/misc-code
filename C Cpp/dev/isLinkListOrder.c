/*�ж�һ���������еĸ������ֵ�Ƿ�����*/
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

int isOrder(node *head)
{
	int flag = 1;	/*�ж������ǽ���������, 1������0������*/
	int result;
	node *p = head->next, *q = head;
	while(p)
	{
		/*���ж�����*/
		if(p->info > q->info)
		{
			result = 1;
		}
		else 
		{
			result = 0; 
			break;
		}
		q = p;
		p = p->next;
	}
	if(result == 0)
	{
		node *p = head->next, *q = head;
		while(p)
		{
			/*�жϽ���*/ 
			if(p->info < q->info)
			{
				result = 1;
			}
			else 
			{
				result = 0; 
				break;
			}
			q = p;
			p = p->next;
		}	
	}
	return result;
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
	if(isOrder(head))
	{
		printf("����\n");
	}
	else
	{
		printf("����\n");
	}
	return 0;	
} 
