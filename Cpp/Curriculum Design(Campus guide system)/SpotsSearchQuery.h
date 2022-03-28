/*����Ѱ·��ѯ*/
/*Dijkstra�㷨*/ 
#ifndef _SPOTS_SEARCH_QUERY_H
#define _SPOTS_SEARCH_QUERY_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/

#define INFINITY 65535 // ��ʾ�����
#define MAX 15 // ��ʾ�����߱ߵ����ֵ 

void dijkstra(Mgraph *g, int v0, int path[], int dist[])
{
	int i, k, v, min, x;
	int final[MAX]; // ��ʾ��ǰԪ���Ƿ���������·��
	memset(final,  0, sizeof(final)); // ��final����Ԫ��ȫ����0������ʼ�����нڵ��Ϊδ����
	for(v = 0; v < g->vertexNum; v++)
	{
		dist[v]	= g->edges[v0][v].weight;
		if(dist[v] < INFINITY && dist[v] != 0)
			path[v] = v0;  // ��ʾ�ý���ǰ�����Ϊv0 
		else 
			path[v] = -1;  // ��ʾ�ý����ǰ����� 
	}	
	final[v0] = 1; // ��ǰ��㵽��ǰ����·���Ѿ��ҵ�
	dist[v0] = 0; // ·������Ϊ0
	for(i = 1; i < g->vertexNum; i++)
	{
		min = INFINITY; // ��ʶ�����·�� 
		for(k = 0; k < g->vertexNum; k++)
		{
			if(!final[k]  && dist[k] < min) // ���ý�㻹δ��ѡ������·��С��min 
			{
				v = k;	 // ��������̶������Ķ��� 
				min = dist[k];
			}
		}	
		if(min == INFINITY) // ����ö������������󣬼����� 
			return ;
		final[v] = 1; // v0����ǰ�������·���Ѿ��ҵ�
		for(k = 0; k < g->vertexNum; k++)
		{
			if(!final[k] && (min + g->edges[v][k].weight < dist[k]))	// ��δ��ѡ�Ķ����л��� 
			{
				dist[k] = min + g->edges[v][k].weight;
				path[k] = v;
			}
		} 
	} 
} 

void startToDest(Mgraph *g, int path[], int dist[], int start, int dest) 
{
	int st[MAX], i, pre, top = -1; // ����ջst����ʼ����ջ
	printf("\n\t    ����·��:\n");
	st[++top] = dest;
	pre = path[dest];
	while(pre != -1)
	{
		st[++top] = pre;
		pre = path[pre];	
	}	
	printf("\t\t    ");
	while(top > 0)
		printf("%s ==��", g->vexs[st[top--]].name);
	printf("%s", g->vexs[dest].name);	
	putchar('\n');
 	printf("\n\t    ȫ�̾��룺\n\t\t    %d��" , dist[dest]);
}

void spotsSearchQuery()
{
	int path[MAX], dist[MAX], i;
	int start = 0, dest = 0; // ��ȡ�û�����ľ������ 
	puts(" ");
	puts("\t\t\t\t       ���� �� Ѱ · �� ѯ��\t\t\t\t\t"); 
	puts("\t\t\t\t0. �»�¥\t��\t5. �췿��\t\t\t\t");
	puts("\t\t\t\t1. ����԰\t��\t6. ������\t\t\t\t");
	puts("\t\t\t\t2. ����ɽ\t��\t7. ͼ���\t\t\t\t");
	puts("\t\t\t\t3. ����Է\t��\t8. ��֪�㳡\t\t\t");
	puts("\t\t\t\t4. ��孲���\t��\t9. �Z褹��ʻ�������\t\t\t");
	puts(" "); 
	printf("\t\t\t\t����������ĵ����أ�:-)\n");
	start = getch();
	if(start >= 48 && start <= 57) // ����������0 ~ 9 ����ʾ��Ӧ�ľ�����Ϣ 
	{
		start -= 48; 
		printf("\t\t\t\t    %s\t==��\t", g->vexs[start].name);
		dijkstra(g, start, path, dist);
		while((dest = getch()) < 48 || dest > 57); // �ȴ��û�������ȷ���
		dest -= 48;
  	    printf("%s\n", g->vexs[dest].name);
		puts("\t\t\t\t- - - - - - - - - - - - - - - - - - \t\t\t");
		puts("\t\t\t\t    Ϊ �� �� �� �� �� · �� \t\t\t");
		startToDest(g, path, dist, start, dest); // ������·�� 
	}
}

#endif
