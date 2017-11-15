/*����·����ѯ�����������·*/
#ifndef _ALL_PATH_QUERY_H_
#define _ALL_PATH_QUERY_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/

#define INFINITY 65535 // ��ʾ�����
#define MAX 15 // ��ʾ�����߱ߵ����ֵ 

int path[MAX]; // ����֮��·��
int top = -1; // path�Ķ���
int num = 0; // ·������ 
// �ж�һ�������Ƿ����ڸø�·���� 
int isInPath(int vertex)
{
	int i;
	for(i = 0; i < top; i++)
	{
		if(path[i] == vertex)
			return 1;
	}
	return 0;
}
// �������֮������·�� 
void allPathStartToDest(int vertex, int dest)
{
	int i;
	if(isInPath(vertex)) // ���ý���Ѿ���·���д�����ֱ�ӷ��� 
	{
		return ;
	}
	if(vertex == dest) // ����ǰ������Ŀ�ĵأ������
	{
		num++; 
		printf("\n    ·��%d:  ", num);
		for(i = 0; i <= top; i++)
		{
			printf("%s ==��", g->vexs[path[i]].name);
		}
		printf("%s", g->vexs[vertex].name);
	} 
	else
	{
		for(i = 0; i < g->vertexNum; i++)
		{	
			if(g->edges[vertex][i].weight != 0 && g->edges[vertex][i].weight != INFINITY) // �����ڽӵ�Ҫ�󣬲��Ҳ���·���У�Ҳû�����ʹ� 
			{	
				path[++top] = vertex; // ����Ҫ�����·����
				allPathStartToDest(i, dest);
				top--; 		
			}
		}
	}
}

//����·����ѯ 
void allPathQuery()
{
	int i, j;
	int start = 0, dest = 0; // ��ȡ�û�����ľ������ 
	puts(" ");
	puts("\t\t\t\t\t �� �� · �� �� ѯ\t\t\t\t\t"); 
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
		while((dest = getch()) < 48 || dest > 57); // �ȴ��û�������ȷ���
		dest -= 48;
  	    printf("%s\n", g->vexs[dest].name);
		puts("\t\t\t\t- - - - - - - - - - - - - - - - - - \t\t\t");
		puts("\t\t\t\t      Ϊ �� �� �� �� �� · �� \t\t\t");
		memset(path, -1, sizeof(path));
		top = -1;
		num = 0;
		allPathStartToDest(start, dest); // �������֮������·�� 
	}	
} 
#endif
