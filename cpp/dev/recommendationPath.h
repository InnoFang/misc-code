#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/
#include "SpotsInfoQuery.h" 	/*������Ϣ��ѯ */
#include "SpotsSearchQuery.h"   /*����Ѱ·��ѯ����������·��ѯ*/
#include "CutPointQuery.h"		/*����ؽڵ��ѯ*/
#include "AllPathQuery.h" 		/*����·����ѯ�����������·*/

#define INFINITY 65535 // ��ʾ�����
#define MAX 15 // ��ʾ�����߱ߵ����ֵ 

//�۹�·���Ƽ�
int haveChosen[MAX]; // �Ѿ���ѡ��ľ��� 
int choose[MAX]; 	//Ҫȥ�ľ���ջ 
int t = -1; 		 // ջ�� 
// �ڽӾ����������������ݹ��㷨
void dfs(Mgraph *g, int i)
{
	int j;

}

void recommendation() // �Ƽ�·������ 
{
	puts("�����Ƽ�·��~~~~~"); 
}

void recommendationPath()
{ 
	puts("\n\n\t\t\t\t\t�� �� · �� �� ��\t\t\t\t\t"); 
	puts("\t\t\t\t\t=================\t\t\t\t\t\n"); 
	puts("\t0. �»�¥\t1. ����԰\t2. ����ɽ\t3. ����Է\t4. ��孲���");
	puts("\t5. �췿��\t6. ������\t7. ͼ���\t8. ��֪�㳡\t9. �Z褹��ʻ�������");
	puts("��������������������������������������������������������������������������������������������������");
	int order = -1;	// ��ȡѡ��ľ������ 
	int k; // �������� 
	int i;
	memset(haveChosen, 0, sizeof(haveChosen));
	t = -1;
	while((k = getch())!= 27 && k != 13) // ���ESC��Enter�˳��� 
	{
		system("cls");
		if(k == 8) // �����BackSpace(ASCIIΪ8)��ʱ��ջ���˳�����Ϊ�գ��򲻲���
		{
			haveChosen[choose[t--]] = 0;	
		}
		order = k - 48;
		if(order >= 0 && order <= 9 && haveChosen[order] == 0)
		{
			haveChosen[order] = 1;
			if(t < g->vertexNum - 1)
			{
				choose[++t] = order;
			}
		} 
		puts("\n\n\t\t\t\t\t�� �� · �� �� ��\t\t\t\t\t"); 
		puts("\t\t\t\t\t=================\t\t\t\t\t\n");
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
		t >= g->vertexNum ? puts("\t\t\t\t\t   ���Ѿ�ѡ���ˣ�") : puts(" ");
		puts("��������������������������������������������������������������������������������������������������");
		printf("    ����ѡ��\n\t");
		for(i = 0 ; i <= t ; i++)
		{
			printf("%s  ", g->vexs[choose[i]].name);
		}
	}
	if(order == 13)
	{
		puts("\n    ���·���Ƽ����£�");	
		recommendation();
	}
		
}

