#include<stdio.h>
const int m = 6, n = 8;
int maze[m+2][n+2];

//ջ
typedef struct{
	int x,y,d;
}SeqStack; 

//��̽
typedef struct{
	int x;
	int y;
}item;
item move[8] = {{0,0},{0,1},{1,0},{1,1},{1,-1},{0,-1},{-1,0},{-1,-1}};
//�Թ���ʼ�� 
void init_maze()
{
	for(int i = 0; i < m+2; i++)
	{
		for(int j = 0; j < n+2; j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
}

//�ƿ�ջ 
LinkStack* init_stack()
{
	return NULL;
}

//�п�ջ
int is_empty(LinkStack* top)
{
	if(top == NULL)
	{
		return 1;
	}
	return 0;
}

//��ջ
LinkStack* push_stack(LinkStack* top, int data)
{
	LinkStack* s;
//	if(is_empty(top))
//	{
//		init_stack();
//	}
	s = (LinkStack*)malloc(sizeof(LinkStack));
	if(NULL == s)
	{
		printf("It's fail to push!");
		return NULL;
	}
	s->data = data;
	s->next = top;
	top = s;
	return top;
}

//��ջ 
LinkStack* pop_stack(LinkStack* top, int *data)
{
	LinkStack* p;
//	if(is_empty(top))
//	{
//		return NULL;
//	}
	*data = top->data;
	p = top;
	top = top->next;
	free(p);
	return top;
}

int main()
{
	SeqStack* s,temp;
	temp = (SeqStack*)malloc(sizeof(SeqStack));
	temp.x = 1, temp.y = 1, temp.d = -1;
	push_stack(s,temp)
	while(!)
	return 0;
}
