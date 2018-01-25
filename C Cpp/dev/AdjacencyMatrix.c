#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FINITY 5000		// �˴���5000��ʾ�����
#define M 20	// ��󶥵���
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
typedef char vertextype;	// ����ֵ����
typedef int edgetype; // Ȩֵ����
typedef struct {
	vertextype vexs[M]; // ������Ϣ��
	edgetype edges[M][M]; // �ڽӾ���
	int n, e; // ͼ�ж��������ͱ���
} Mgraph;

void create(Mgraph *g, char *s, int c) // c == 0 ��ʾ��������ͼ
{
	int i, j, k, w;
	FILE *rf;
	rf = fopen(s, "r");	// ���ļ��ж�ȡͼ�ı���Ϣ
	if (rf)
	{

		fscanf(rf, "%d%d", &g->n, &g->e); // ����ͼ�Ķ������ͱ���
		for ( i = 0; i < g->n; i++) // ����ͼ�еĶ���ֵ
		{
			fscanf(rf, "%1s", &(g->vexs[i]));
		}
		for ( i = 0; i < g->n; i++) // ��ʼ���ڽӾ���
		{
			for ( j = 0; j < g->n; j++)
			{
				if (i == j)
				{
					g->edges[i][j] = 0;
				}
				else
				{
					g->edges[i][j] = FINITY;
				}
			}
		}

		for ( k = 0; k < g->e; k++) // ���������еı�
		{
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
			{
				g->edges[j][i] = w;	// ��������ͼ�ڽӾ���
			}
		}
		fclose(rf);	// �ر��ļ�
	}
	else
	{

		g->n = 0;
	}
}


#define MAXVEX 100  // ��󶥵���
typedef int Boolean;
Boolean visited[MAXVEX]; // ���ʱ�־����
#define TRUE 1
#define FALSE 0

// �ڽӾ����������������ݹ��㷨
void dfs(Mgraph *g, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", g->vexs[i]); // ��ӡ���㣬Ҳ��������������
	for(j = 0; j < g->n; j++)
	{
		if(g->edges[i][j] !=0 && g->edges[i][j] != FINITY && !visited[j])
		{
			dfs(g, j);	// ��Ϊ���ʵ��ڽӶ���ݹ����
		}
	}
}

// �ڽӾ������ȱ�������
void DFSTraverse(Mgraph *g)
{
	int i;
	for(i = 0; i < g->n; i++)
	{
		visited[i] = FALSE;	
	}
	for(i = 0; i < g->n; i++)
	{
		if(!visited[i])
		{
			dfs(g, i);
		}
	}
}

#define ROOT 0 // ǰ����������ڵ� 
int dfn[M]; // ����DFS������˳���������õ��ǰ�������� 
int low[M]; // ��ʾ�ö���ɵ������С����� 
int parent[M]; // ��ǰ��������У�ÿ������Ӧ�ĸ��ڵ� 
int vis[M]; // ÿ���ڵ��Ƿ񱻷��ʹ� 
int DFSCount = 0; // ǰ�������� 
int cutNum = 0; // �ؽڵ����� 
int cut[M]; // �����ҵ��Ĺؽڵ� 
int stack[M]; // DFS˳��ջ
int top = -1; // ջ�� 
 
// Tarjan�㷨 
void cut_dfs(Mgraph *g, int u) 
{
	int i;
	vis[u] = 1;
	int children = 0; // ��¼���u������
	dfn[u] = low[u] = DFSCount++;
	for(i = 0; i < g->n; i++)
	{
		int v ;
		if(g->edges[u][i] != 0 && g->edges[u][i] != FINITY) 
			v = i;
		else
			continue;
		printf("test: vertex=%c, dfn=%d, low=%d\n", g->vexs[u], dfn[u], low[u]);
		if(!vis[v])
		{
			children++;
 			parent[v] = u; // u��v�ĸ��ڵ� 
			cut_dfs(g, v);
			low[u] = min(low[u], low[v]); // u����lowΪ�ܵ������С���ı��
			if(parent[u] == 0 && children > 1) //u����Ǹ����ʱ�ý������������1 
			{	
				cutNum++;
				cut[u] = 1; // ���uΪ�ؽڵ� 
				puts("#1");
			}
			if(parent[u] != 0 && low[v] >= dfn[u])//u��㲻Ϊ�����ʱ���ӽڵ�ı�Ŵ���u�ܵ������С��� 
			{
				cutNum++; 
				cut[u] = 1;// ���uΪ�ؽڵ� 
				puts("#2");
			}
		}	
		else if(parent[v] != u) // ��u���ڽ���Ѿ������ʣ����Ҹ��ڽ�㲻��u�ĸ����ʱ,��(u,v)���ɻر� 
		{	
			printf("yes,parent[v] = %d, u = %d\n", parent[v], u);
			low[u] = min(low[u], dfn[v]);	
		} 
	} 
}

void cutPointQuery(Mgraph *g)
{
	int i;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));	// ��ʼ��
	memset(parent, 0, sizeof(parent)); // ��ʼ�����ڵ����� 
	memset(cut, 0, sizeof(cut)); // ��ʼ���ؽڵ����� 
//	parent[0] = -1; // �����0��Ϊ����� 
	cut_dfs(g, 0);
	if(cutNum > 0)
	{
		printf("\t\t\t�ؽڵ����Ϊ��%d���ֱ�Ϊ\n", cutNum);
		for(i = 0; i < g->n; i++) // ��������ؽڵ� 
		{	
			if(cut[i] == 1)
				printf("%c", g->vexs[i]); 
		}
	} 
	else
		printf("\t\t\t�ؽڵ����Ϊ0�������ڹؽڵ�\n");
}
int main()
{
	int i;
	Mgraph *g = (Mgraph*)malloc(sizeof(Mgraph));
	create(g, "G7.txt", 0);
//	int i, j;
//	for(i = 0; i < g->n; i++)
//	{
//		for(j = 0; j < g->n; j++)
//		{
//			printfe("%d ", g->edges[i][j]);
//		}
//		printf("\n");
//	}
	dfs(g, 0) ;
//	printf("\n+------+\n");
//	DFSTraverse(g);

	/*���ڽӾ�������ͼ�Ĺؽڵ�*/
//	cutPointQuery(g); 
//	for(i = 0; i < M; i++)
//		printf("%d ", parent[i]);
//	putchar('\n');
//	for(i = 0; i < M; i++)
//	{
//		if(cut[i] == 1)
//			printf("%c ", g->vexs[cut[i]]);
//	}
//	putchar('\n');
//	return 0;
}
/*
Input:

4 4
0123
0 1 56
0 2 34
0 3 78
2 3 25

Output:
0 1 2 3
*/
