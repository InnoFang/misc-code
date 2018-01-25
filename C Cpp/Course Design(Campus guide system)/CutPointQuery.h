/*����ؽڵ��ѯ*/
#ifndef _CUT_POINT_QUERY_H_
#define _CUT_POINT_QUERY_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/

#define INFINITY 65535 // ��ʾ�����
#define MAX 15 // ��ʾ�����߱ߵ����ֵ 
#define ROOT 2 // ǰ����������ڵ� 

int visi[MAX]; 
int cut[MAX];	// �洢�ؽڵ� 
int cutNum = 0; // �Ƿ��йؽڵ� 
void dfs_cut(Mgraph *g, int i)
{
	int j;
	if(visi[i] != ROOT)
		visi[i] = 1;
	int child = 0;
	for(j = 0; j < g->vertexNum; j++)
	{  
		if(g->edges[i][j].weight != 0 && g->edges[i][j].weight != INFINITY && !visi[j])
		{	
			child++; 
			dfs_cut(g, j);
		}
	}
	if(visi[i] == ROOT && child >= 2) // ���õ��Ǹ��������д��ڵ���2����������Ϊ�ؽڵ� 
	{
		cutNum++; // �ؽڵ�������һ 
		cut[i] = 1;	// �Ըõ���Ϊ�ؽڵ� 
	}
}

void cutPointQuery()
{
	int i;
	FILE *fp = NULL; // ��ʼ���ļ�ָ�� 
	char buff[100]; // �ļ���ȡ������ 
	fp = fopen("NUCMap.txt", "r");
	if(fp == NULL)  
		puts("�ļ���ȡʧ�ܣ�");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff);
	}
	fclose(fp); // �ر��ļ�ָ�� 
	memset(cut, 0, sizeof(cut)); // ����ؽڵ� ��ʼ�� 
	cutNum = 0;
	for(i = 0; i < g->vertexNum; i++) // ��ÿ��������DFS 
	{	
		memset(visi, 0, sizeof(visi)); // ���������ʼ�� 
		visi[i] = ROOT; // �Ըý�����DFS֮ǰ�����õ���Ϊ���ڵ� 
		dfs_cut(g, i);
	}
	if(cutNum)
	{
		printf("\t\t\tУ԰ͼ�Ĺؽڵ����Ϊ��%d\n\n\t\t\t�ֱ�Ϊ: \n", cutNum);
		for(i = 0; i < g->vertexNum; i++) // ��������ؽڵ� 
		{	
			if(cut[i] == 1)
				printf("\n\t\t\t\t* %s\n", g->vexs[i].name); 
		}
	} 
	else
		printf("\n\t\t\t�ؽڵ����Ϊ0�������ڹؽڵ�\n");
	
} 
#endif
