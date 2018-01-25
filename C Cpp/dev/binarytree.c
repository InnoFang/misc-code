#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct BiTNode{
	datatype data;
	struct BiTNode *lchild, *rchild;
} bitnode;
/*˳��ջ*/
typedef struct sttacl{
	bitnode* data[100];
	int tag[100];
	int top;
} seqstack;

/*��ջ*/
void push(seqstack *s, bitnode *t)
{
	s->data[s->top] = t;
	s->top++;
}

/*��ջ*/ 
bitnode* pop(seqstack *s)
{
	if(s->top != 0)
	{
		s->top--;
		return (s->data[s->top]);
	}
	else
	{
		return NULL;
	}
}

bitnode *createBiTree()
{
	bitnode *t;
	datatype ch;
	scanf("%c", &ch);
	if(ch == '#')
		t = NULL;
	else 
	{
		t = (bitnode*)malloc(sizeof(bitnode));
		if(!t)
		{
			printf("��㴴��ʧ��");
			return NULL;
		}
		t->data = ch;
		t->lchild = createBiTree();
		t->rchild = createBiTree();
	}
	return t;
} 

/*�ݹ�ǰ�����*/
void preorder(bitnode *t)
{
	if(t)
	{
		printf("%c ",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

/*�ݹ��������*/
void inorder(bitnode *t)
{
	if(t)
	{
		inorder(t->lchild);
		printf("%c ",t->data);
		inorder(t->rchild);			
	}
}

/*�ݹ�������*/ 
void postorder(bitnode *t)
{
	if(t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c ",t->data);
	}
}

/*�ǵݹ�ǰ�����*/
void preorder1(bitnode *t)
{
	seqstack s;
	s.top = 0;
	while((t) || (s.top != 0))
	{
		if(t)
		{
			printf("%c ", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else 
		{
			t = pop(&s);
			t = t->rchild;
		}
	}
}


/*�ǵݹ��������*/
void inorder1(bitnode *t)
{

	seqstack s;
	s.top = 0;
	while(t || s.top != 0)
	{
		if(t)
		{
			push(&s, t);
			t = t->lchild;
		}
		else 
		{
			t = pop(&s);
			printf("%c ", t->data);
			t = t->rchild;
		}
	}
} 

/*�ǵݹ�������*/
void postorder1(bitnode *t)
{
	seqstack s;
	s.top = 0;
	while(t || s.top != 0)
	{
		if(t)
		{
			s.data[s.top] = t;
			s.tag[s.top] = 0;	
			s.top++;
			t = t->lchild;
		} 
		else 
		{
			if(s.tag[s.top - 1] == 1)
			{
				t = s.data[--s.top];	//�����s.top�����ȼ��ٽ��в��� 
				printf("%c ", t->data);	
				t = NULL;
			}	
			else 
			{
				t = s.data[s.top - 1]; 
				s.tag[s.top - 1] = 1;
				t = t->rchild;
			}
		}
	} 
}

int countLeaf(bitnode *t)
{
	if(!t)
		return 0;
	if(!t->rchild && !t->lchild)	//ĳ���ڵ������������������Ϊ�գ���ΪҶ�ӽ�� 
		return 1;
	else
		return countLeaf(t->lchild) + countLeaf(t->rchild);
}

int countLeaf1(bitnode *t){
	int sum = 0;
	seqstack s;
	s.top = 0;
	while((t) || (s.top != 0))
	{
		if(t)
		{
//			printf("%c ", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else 
		{
			t = pop(&s);
			if(!t->rchild && !t->lchild)	//ĳ���ڵ������������������Ϊ�գ���ΪҶ�ӽ�� 
				sum += 1;
			t = t->rchild;
			
		}
	}
	return sum;
} 

/*

			a
	b				C
d		e		f		g

input : abd##e##cf##g##
*/

int main()
{
	bitnode *root = createBiTree();
	printf("\n+------�ݹ�ǰ�����------+\n");
	preorder(root);	//a b d  e c f g
	printf("\n+------�ݹ��������------+\n");
	inorder(root);	//d b e a f c g
	printf("\n+------�ݹ�������------+\n");
	postorder(root);//d e b f g c a	
	
	
	printf("\n+------�ǵݹ�ǰ�����------+\n");
	preorder1(root);	//a b d e c f g
	printf("\n+------�ǵݹ��������------+\n");
	inorder1(root);	//d b e a f c g
	printf("\n+------�ǵݹ�������------+\n");
	postorder1(root);//d e b f g c a	
	printf("\nleaf's number : %d\n", countLeaf(root));
	printf("leaf's number2 : %d", countLeaf1(root));
	return 0;	
}
