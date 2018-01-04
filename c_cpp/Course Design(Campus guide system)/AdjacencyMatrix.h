/*�ڽӾ������봴��*/
#ifndef _ADJACENCY_MATRIX_H_
#define _ADJACENCY_MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define INFINITY 65535 // ��ʾ�����
#define MAX 15 // ��ʾ�����߱ߵ����ֵ 

typedef struct { // ����߽ṹ�壬��ԱΪȨ�� 
	int weight;
} edge;

typedef struct { // ������ṹ�壬��������Ϣ 
	char *name; // ��������
	char *code; // �������  
	char *intro; // ������ 
} vertex;
 
typedef struct { // �����ڽӾ��� 
	vertex vexs[MAX]; // ��� 
	edge edges[MAX][MAX]; // �� 
	int vertexNum, edgeNum; // ����������� 
} Mgraph; 

Mgraph *g = NULL; // ����ͼ��ȫ�ֱ��� 

// �����ڽӾ��� 
void create(Mgraph *g, char *text)
{
	int i, j, k, w;
	char info[100]; // ���ڻ���������Ϣ 
	int infoLen; // ������Ϣ�ĳ��� 
	FILE *rf;
	rf = fopen(text, "r");
	if(rf)
	{
		fscanf(rf, "%d%d", &g->vertexNum, &g->edgeNum); // ����ͼ�Ķ������ͱ���
		for(i = 0; i < g->vertexNum; i++)   // ��ʼ����������Ϣ 
		{
			fscanf(rf, "%s", info);	// ��ȡ������Ϣ -- ������� 
			infoLen = strlen(info); // ��ȡ������Ϣ���� 
			g->vexs[i].code = (char*)malloc(infoLen * sizeof(char)); //  ���߻�����Ϣ����Ϊ�ý���code�ַ������ٿռ� 
			strcpy(g->vexs[i].code, info); // �����code��Ա��ֵ
			
			fscanf(rf, "%s", info);	// ��ȡ������Ϣ -- �������� 
			infoLen = strlen(info); // ��ȡ������Ϣ���� 
			g->vexs[i].name = (char*)malloc(infoLen * sizeof(char)); //  ���߻�����Ϣ����Ϊ�ý���name�ַ������ٿռ� 
			strcpy(g->vexs[i].name, info); // �����name��Ա��ֵ
			 
			fscanf(rf, "%s", info);	// ��ȡ������Ϣ -- ������ 
			infoLen = strlen(info); // ��ȡ������Ϣ���� 
			g->vexs[i].intro = (char*)malloc(infoLen * sizeof(char)); //  ���߻�����Ϣ����Ϊ�ý���intro�ַ������ٿռ� 
			strcpy(g->vexs[i].intro, info); // �����intro��Ա��ֵ
		}
		for(i = 0; i < g->vertexNum; i++)	// ��ʼ���ڽӾ��� 
		{
			for(j = 0; j < g->vertexNum; j++)
			{
				if(i == j)
				{
					g->edges[i][j].weight = 0;
				}
				else
				{
					g->edges[i][j].weight = INFINITY;
				}
			}
		}
		for(k = 0; k < g->edgeNum; k++)
		{
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j].weight = w;
			g->edges[j][i].weight = w; // ��������ͼ�ڽӾ��� 
		}
		fclose(rf);
	}
	else
	{
		g->vertexNum = 0;
	}
}
#endif
