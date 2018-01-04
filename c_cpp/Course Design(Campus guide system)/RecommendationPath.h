/*�����������·���Ƽ�*/
#ifndef _RECOMMENDATION_PATH_H_
#define _RECOMMENDATION_PATH_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/
#include "SpotsSearchQuery.h"   /*����Ѱ·��ѯ����������·��ѯ*/

#define INFINITY 65535 // ��ʾ�����
#define MAX 15 // ��ʾ�����߱ߵ����ֵ 

//�۹�·���Ƽ�
int haveChosen[MAX]; // �Ѿ���ѡ��ľ��� 
int choose[MAX]; 	//Ҫȥ�ľ���ջ 
int choose_top = -1; 		 // ����ջ�� 
int visit[MAX]; 
int dfsOrder[MAX]; // ����dfs����˳������ͻ��û�����Ľ�� 
int dfsOrder_top = -1;	// dfs����˳��ջջ�� 
int path[MAX] = {0}; // �Ƽ�·�� 
int path_top = -1;	// �Ƽ�·��ջջ�� 
int distance = 0; // ��·�������ܾ��� 

int isInChoose(int i) // �жϽ���Ƿ����û�ѡ��Ľ��, �Ƿ���1�����Ƿ���0 
{
	int j;
	for(j = 0; j <= choose_top; j++)
	{
		if(choose[j] == i)
		{
			return 1;
		}
	}
	return 0;
} 

// �ڽӾ����������������ݹ��㷨������DFSΪ�û�ѡ��Ľ������ 
void dfs(Mgraph *g, int i)
{
	int j;
	visit[i] = 1;
	if(isInChoose(i)) // ������û�ѡ�Ľ�������DFS˳��ջ�� 
		dfsOrder[++dfsOrder_top] = i;
	for(j = 0; j < g->vertexNum; j++)
	{
		if(g->edges[i][j].weight != 0 && g->edges[i][j].weight != INFINITY && !visit[j])
		{
			dfs(g, j);
		}
	}
}

void getPath(Mgraph *g, int p[], int d[], int start, int end) // ��ȡ��start��end�����·�� 
{
	int st[MAX], i, pre, top = -1; // ����ջst����ʼ����ջ
	distance += d[end]; // ����start��end�������̾��� 
	st[++top] = start;
	pre = p[end];
	while(pre != -1)
	{
		st[++top] = pre;
		pre = p[pre];	
	}	
	while(top > 0)
		path[++path_top] = st[top--];  // ����start��end�����·�� 
	if(start == end)	// start����end�������Ϊ�Ѿ��ߵ����һ������������ʱ�ѵ�end��·��Ϊ����·�� 
		path[++path_top] = end;
}
void recommendation() // �Ƽ�·������ 
{
	int i; 		
	int p[MAX] = {0}; // ����·�� 
	int d[MAX] = {0}; // ������� 
	dfs(g, 0); /*����dfs�ҵ������dfs˳��ջ*/
	putchar('\n');
	for( i = 0; i < dfsOrder_top; i++) // ��dfs˳��ջ�У������ڽ�����̾��룬����¼�����Ϣ 
	{
		memset(p, 0, sizeof(p)); // ·�������ʼ�� 
		memset(d, 0, sizeof(d)); // ���������ʼ�� 
		dijkstra(g, dfsOrder[i], p, d); // ����Dijkstra�ҵ����· 
		getPath(g, p, d, dfsOrder[i], dfsOrder[i + 1]); // ��ȡָ�������· 
	}
	dijkstra(g, dfsOrder[i], p, d); // ѭ�����󣬻�ʣ���һ������û�в��ң���������Dijkstra�������· 
	getPath(g, p, d, dfsOrder[i], dfsOrder[i]); // ��ȡ���· 
	printf("\t"); 
	for(i = 0; i <= path_top; i++) // ����Ƽ�·�� 
	{
		printf("%s", g->vexs[path[i]].name);
		if(i < path_top)
			printf(" ==�� ");	
	} 
	putchar('\n');
	printf("\n\tȫ�̾���Ϊ%d��", distance); // ���ȫ�̾��� 
}

void recommendationPath()
{ 
	puts("\n\n\t\t\t\t��    ��    ·    ��    ��     ��"); 
	puts("\t\t\t    =========================================\n"); 
	puts("\t0. �»�¥\t1. ����԰\t2. ����ɽ\t3. ����Է\t4. ��孲���");
	puts("\t5. �췿��\t6. ������\t7. ͼ���\t8. ��֪�㳡\t9. �Z褹��ʻ�������");
	printf("����������������������������������������������������������������������������������������������������");
	printf("\t\t\t     Tips:����ѡ�У���λ��ȡ��ѡ�У��س�ִ��"); 
	int order = -1;	// ��ȡѡ��ľ������ 
	int k; // �������� 
	int i;
	memset(haveChosen, 0, sizeof(haveChosen)); // ��ʼ���Ѿ�ѡ�񾰵����� 
	choose_top = -1;
	while((k = getch())!= 27 && k != 13) // ���ESC��Enterֹͣѡ�� 
	{
		system("cls"); // ���� 
		if(k == 8) // �����BackSpace(ASCIIΪ8)��ʱ����ѡ����ջջ���˳�����ѡ�������㣬��Ϊ�գ��򲻲���
		{
			haveChosen[choose[choose_top--]] = 0;	
		}
		//������ļ���ȥ48���õ�һ����ֵ����Ϊ����(����0~9��ASCIIΪ48~57)�����õ���Ӧ���������� 
		order = k - 48; 
		// �ж��û���ѡ���Ƿ������ּ� 
		if(order >= 0 && order <= 9 && haveChosen[order] == 0) // �����֣����Ҹþ���û�б�ѡ�� 
		{
			haveChosen[order] = 1; //  ��Ǹþ����Ѿ�ѡ���� 
			if(choose_top < g->vertexNum - 1) // ������ѡ����ջ 
			{
				choose[++choose_top] = order;
			}
		} 
		// �����û���ѡ�� 
		puts("\n\n\t\t\t\t��    ��    ·    ��    ��     ��"); 
		puts("\t\t\t    =========================================\t\t\t\t\n"); 
		haveChosen[0] == 0 ? printf("\t0. �»�¥") : printf("");
		haveChosen[1] == 0 ? printf("\t1. ����԰") : printf("");
		haveChosen[2] == 0 ? printf("\t2. ����ɽ") : printf("");
		haveChosen[3] == 0 ? printf("\t3. ����Է") : printf("");
		haveChosen[4] == 0 ? printf("\t4. ��孲���") : printf("");
		haveChosen[5] == 0 ? printf("\t5. �췿��") : printf("");
		haveChosen[6] == 0 ? printf("\t6. ������") : printf("");
		haveChosen[7] == 0 ? printf("\t7. ͼ���") : printf("");
		haveChosen[8] == 0 ? printf("\t8. ��֪�㳡") : printf("");
		haveChosen[9] == 0 ? printf("\t9. �Z褹��ʻ�������") : printf("");
		puts("\n����������������������������������������������������������������������������������������������������");
		printf("\n    ����ѡ��\n\t");
		for(i = 0 ; i <= choose_top ; i++) // ��ʾ�û�ѡ������нڵ� 
		{
			printf("%s  ", g->vexs[choose[i]].name);
		}
	}
	if(k == 13) // ���û������Enter������ִ���Ƽ�·���㷨 
	{ 
		puts("\n\n    Ϊ���Ƽ����·����");
		memset(visit, 0, sizeof(visit));
		memset(dfsOrder, 0, sizeof(dfsOrder)); // ����dfs����˳������ͻ��û�����Ľ�� 
		dfsOrder_top = -1;	
		memset(path, -1, sizeof(path)); // ��·��ջ��ʼ�� 
		path_top = -1;
		distance = 0; // �ܾ����ʼ�� 
		recommendation();
	}
		
}

#endif
