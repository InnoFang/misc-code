/*������Ϣ��ѯ */
#ifndef _SPOT_INFO_QUERY_H_ 
#define _SPOT_INFO_QUERY_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/

void spotsInfoQuery()
{
	int order; // ��ȡ�û�����ľ������ 
	puts(" ");
	puts("\t\t\t\t       ���� �� �� Ϣ �� ѯ��\t\t\t\t\t"); 
	puts("\t\t\t\t0. �»�¥\t��\t5. �췿��\t\t\t\t");
	puts("\t\t\t\t1. ����԰\t��\t6. ������\t\t\t\t");
	puts("\t\t\t\t2. ����ɽ\t��\t7. ͼ���\t\t\t\t");
	puts("\t\t\t\t3. ����Է\t��\t8. ��֪�㳡\t\t\t");
	puts("\t\t\t\t4. ��孲���\t��\t9. �Z褹��ʻ�������\t\t\t");
	puts(" "); 
	printf("\t\t\t    ���뾰����Ž��в�ѯ ��");
	order = getch();
	if(order >= 48 && order <= 57) // ����������0 ~ 9 ����ʾ��Ӧ�ľ�����Ϣ 
	{
		order -= 48; 
		printf("%d\n", order);
		puts("\t\t    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \t\t");
		printf("\n\t\t\t������ţ�%s\n", g->vexs[order].code);
		printf("\n\t\t\t�������ƣ�%s\n", g->vexs[order].name);
		printf("\n\t\t\t�����飺\n\n\t\t%s", g->vexs[order].intro);
	}
}
#endif
