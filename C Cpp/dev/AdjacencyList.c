//#include<stdio.h>
//#include<stdlib.h>
//#define M 20	// Ԥ����ͼ����󶥵���
//typedef char DataType; // ������Ϣ��������
//
//typedef struct node{ // �߱���
//	int adjvex;		// �ڽӵ�
//	struct node *next;
//} EdgeNode;
//
//typedef struct vnode{ // ͷ�������
//	DataType vertex;	// ������Ϣ
//	EdgeNode *FirstEdge; // �����ӱ�ͷָ��
//} VertexNode;
//
//typedef struct{		// �ڽӱ�����
//	VertexNode adjlist[M];	// ���ͷ����˳���
//	int n, e;	// ͼ�Ķ����������
//} LinkedGraph;
//
//void create(LinkedGraph *g, char *filename, int c)
//{
//	int i, j, k; // c == 0 ��ʾ��������ͼ�������ʾ��������ͼ
//	EdgeNode *s;
//	FILE *fp;
//	fp = fopen(filename, "r");
//	if(fp)
//	{
//		fscanf(fp, "%d%d", &g->n, &g->e);	// ���붥���������
//		for(i = 0; i < g->n; i++)
//		{
//			fscanf(fp, "%1s", &g->adjlist[i].vertex); // ���붥����Ϣ
//			g->adjlist[i].FirstEdge = NULL;	 // �߱���Ϊ�ձ�
//		}
//		for(k = 0; k < g->e; k++)		// ѭ��e�ν����߱�
//		{
//			fscanf(fp, "%d%d", &i, &j); // ��������ԣ�i�� j��
//			s = (EdgeNode*)malloc(sizeof(EdgeNode));
//			s->adjvex = j; 	// �ڽӵ����Ϊj
//			s->next = g->adjlist[i].FirstEdge;
//			g->adjlist[i].FirstEdge = s; // ���½��*s���붥��Vi�ı߱�ͷ��
//			if(c == 0)	// ����ͼ
//			{
//				s = (EdgeNode*)malloc(sizeof(EdgeNode));
//				s->adjvex = i; // �ڽӵ����Ϊi
//				s->next = g->adjlist[j].FirstEdge;
//				g->adjlist[j].FirstEdge = s; // ���½��*s���붥��Vj�ı߱�ͷ��
//			}
//		}
//		fclose(fp);
//	}
//	else
//	{
//		g->n = 0;	// �ļ���ʧ��
//	}
//}
//
//#define MAXVEX 100  // ��󶥵���
//typedef int Boolean;
//Boolean visited[MAXVEX]; // ���ʱ�־����
//#define TRUE 1
//#define FALSE 0
//
//// �ڽӱ����ȵݹ��㷨
//void dfs(LinkedGraph *g, int i)
//{
//	EdgeNode *p;
//	visited[i] = TRUE;
//	printf("%c ", g->adjlist[i].vertex);	// ��ӡ���㣬Ҳ������������
//	p = g->adjlist[i].FirstEdge;
//	while(p)
//	{
//		if(!visited[p->adjvex])
//		{
//			dfs(g, p->adjvex); // �Է��ʵ��ڽӵ�ݹ����
//		}
//		p = p->next;
//	}
//}
//
//// �ڽӱ����ȱ�������
//void DFSTraverse(LinkedGraph *g)
//{
//	int i;
//	for(i = 0; i < g->n; i++)
//	{
//		visited[i] = FALSE;
//	}
//	for(i = 0; i < g->n; i++)
//	{
//		if(!visited[i])
//		{
//			dfs(g, i);
//		}
//	}
//}
//
//
//void bfs(LinkedGraph *g, int i)
//{
//	int j;
//	EdgeNode *p;
//	int queue[M], front, rear;	// FIFO����
//	front = rear = 0;	// ��ʼ���ն���
//	printf("%c ", g->adjlist[i].vertex); // ����Դ��v
//	visited[i] = TRUE;
//	queue[rear++] = i; // �����ʽ�����
//	while(rear > front) // �����зǿ�ʱ��ִ������ѭ����
//	{
//		j = queue[front++]; // ����
//		p = g->adjlist[i].FirstEdge;
//		while(p)	// ������������ڽӱ�
//		{
//			if(visited[p->adjvex] == 0)
//			{
//				printf("%c ", g->adjlist[p->adjvex].vertex);
//				queue[rear++] = p->adjvex;
//				visited[p->adjvex] = 1;
//			}
//			p = p->next;
//		}
//	}
//}
//
//int BFSTraverse(LinkedGraph *g)
//{
//	int i, count = 0;
//	for(i = 0; i < g->n; i++)
//	{
//		visited[i] = 0;
//	}
//	for(i = 0; i < g->n; i++)
//	{
//		if(!visited[i])
//		{
//			//printf("\n");
//			count++;
//			bfs(g, i);
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int i;
//	LinkedGraph *g = (LinkedGraph*)malloc(sizeof(LinkedGraph));
//	create(g, "G7_.txt", 0);
//	printf("\n+=======�����������========+\n");
//	printf("|----�ڽӱ����ȵݹ��㷨---|\n");
//	printf("|         ");dfs(g, 0);printf("          |");
//	printf("\n|----�ڽӱ����ȱ�������---|\n");
//	printf("|         ");DFSTraverse(g);printf("          |");
//	printf("\n+===========================+\n");
//
//
//	for(i = 0; i < M; i++)
//	{
//		visited[i] = FALSE;
//	}
//
//	printf("\n+=======�����������========+\n");
//	printf("|----�ڽӱ����ȵݹ��㷨---|\n");
//	printf("|         ");bfs(g, 0);printf("          |");
//	printf("\n|----�ڽӱ����ȱ�������---|\n");
//	printf("|         ");BFSTraverse(g);printf("          |");
//	printf("\n+===========================+\n");
//	return 0;
//}
///*
//Input:
//
//4 4
//0123
//0 1
//0 2
//0 3
//2 3
//
//Output:
//0 3 2 1
//*/

#include<stdio.h>
#include<stdlib.h>
#define M 20
typedef char datatype;

typedef struct node{
  int adjvex;
  struct node *next;
} edgenode;

typedef struct vnode{
  datatype vertex;
  edgenode *firstedge;
} vertexnode;

typedef struct {
  vertexnode adjlist[M];
  int v, e;
} graph;

void create_graph(graph *g, int c){
  int i, j, k;
  edgenode *s;
  scanf("%d%d", &g->v, &g->e);
  for(i = 0; i < g->v; i++)
  {
    scanf("%d", &g->adjlist[i].vertex);
    g->adjlist[i].firstedge = NULL;
  }
  for(k = 0; k < g->e; k++)
  {
    scanf("%d%d", &i, &j);
    s = (edgenode*)malloc(sizeof(edgenode));
    s->adjvex = j;
    s->next = g->adjlist[i].firstedge;
    g->adjlist[i].firstedge = s;
    if (c == 0) {
      s = (edgenode*)malloc(sizeof(edgenode*));
      s->adjvex = i;
      s->next = g->adjlist[j].firstedge;
      g->adjlist[j].firstedge = s;
    }
  }
} 
  int visited[M] = {0};
  void dfs(graph *g, int i)
  {
      edgenode *s;
      visited[i] = 1;
      printf("%d ", g->adjlist[i].vertex);
      s = g->adjlist[i].firstedge;
      while(s)
      {
        if (!visited[s->adjvex]) {
          dfs(g, s->adjvex);
        }
        s = s->next;
      }
  }
  void DFSTraverse(graph *g)
  {
    int i;
    for ( i = 0; i < g->v; i++) {
      visited[i] = 0;
    }
    for ( i = 0; i < g->v; i++) {
      if (!visited[i]) {
            dfs(g, i);
      }
    }
  }

  void bfs(graph *g , int i)
  {
    int j;
    edgenode *s;
    int queue[M], rear, front;
    rear = front = 0;
    visited[i] = 1;
    queue[rear++] = i;
    printf("%d ", g->adjlist[i].vertex);
    while(rear > front)
    {
      j = queue[front++];
      s = g->adjlist[i].firstedge;
      while(s)
      {
        if (!visited[s->adjvex]) {
          printf("%d ", s->adjvex);
          queue[rear++] = s->adjvex;
          visited[s->adjvex] = 1;
        }
        s = s->next;
      }
    }
  }

  int BFSTraverse(graph *g)
  {
    int i, j, count = 0;
    for ( i = 0; i < g->v; i++) {
      visited[i] = 0;
    }
    for ( j = 0; j < g->v; j++) {
      if (!visited[g->adjlist[j].vertex]) {
        count++;
        bfs(g, g->adjlist[j].vertex);
      }
    }
    return count;
  }


int main()
{
	graph *g = (graph*)malloc(sizeof(graph));
	create_graph(g, 0);
	//bfs(g, 0);
	int b = BFSTraverse(g);
	//DFSTraverse(g);
	printf("\n���� %d ����ͨ����\n", b);
	return 0;
}
/*
Eg1:

4 4
0 1 2 3
0 1
0 2
0 3
2 3

Eg2:
6 7
0 1 2 3 4 5
0 1
0 2
1 3
3 4
1 4
4 5
5 2

*/ 
