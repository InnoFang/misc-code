#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "AdjacencyMatrix.h"	/*�ڽӾ������봴��*/
#include "SpotsInfoQuery.h" 	/*������Ϣ��ѯ */
#include "SpotsSearchQuery.h"   /*����Ѱ·��ѯ����������·��ѯ*/
#include "CutPointQuery.h"		/*����ؽڵ��ѯ*/
#include "AllPathQuery.h" 		/*����·����ѯ�����������·*/
#include "RecommendationPath.h" /*�����������·���Ƽ�*/



// ʹ�ð���

void help()
{
	FILE *fp = NULL; // ��ʼ���ļ�ָ��
	char buff[100]; // �ļ���ȡ������
	fp = fopen("help.txt", "r");
	if(fp == NULL)
		puts("�ļ���ȡʧ�ܣ�");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // �ر��ļ�ָ��
}

/** �˵� **/
int opera = 1; // ȫ�ֱ������˵���ָ��

void updateUI(int k)  // ������ͼ
{
	system("cls");
	FILE *fp = NULL; // ��ʼ���ļ�ָ��
	char buff[100]; // �ļ���ȡ������
	fp = fopen("menu_head.txt", "r");
	if(fp == NULL)
		puts("�ļ���ȡʧ�ܣ�");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // �ر��ļ�ָ��
	if(k == 1) // item1
	{
		puts("                �U		   �� 	 >> ������Ϣ��ѯ     �� 	        �U");
	}
	else
	{
		puts("                �U		   ��  #1   ������Ϣ��ѯ     �� 	        �U");
	}
	if(k == 2)// item2��״̬
	{
		puts("                �U		   ��    >> ����Ѱ·��ѯ     ��                 �U");
	}
	else
	{
		puts("                �U		   ��  #2   ����Ѱ·��ѯ     ��                 �U");
	}
	if(k == 3)// item3��״̬
	{
		puts("                �U		   ��    >> �ؽڵ�  ��ѯ     �� 	        �U");
	}
	else
	{
		puts("                �U		   ��  #3   �ؽڵ�  ��ѯ     �� 	        �U");
	}
	if(k == 4)// item4��״̬
	{
		puts("                �U		   ��    >> ����·����ѯ     �� 	        �U");
	}
	else
	{
		puts("                �U		   ��  #4   ����·����ѯ     �� 	        �U");
	}
	if(k == 5)// item5��״̬
	{
		puts("                �U		   ��    >> �۹�·���Ƽ�     �� 	        �U");
	}
	else
	{
		puts("                �U		   ��  #5   �۹�·���Ƽ�     �� 	        �U");
	}
	if(k == 6)// item6��״̬
	{
		puts("                �U		   ��    >> ʹ �� �� ��      �� 	        �U");
	}
	else
	{
		puts("                �U		   ��  #6   ʹ �� �� ��      �� 	        �U");
	}
	fp = fopen("menu_foot.txt", "r");
	if(fp == NULL)
		puts("�ļ���ȡʧ�ܣ�");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // �ر��ļ�ָ��
}

void exec(int opera)
{
	int k; // ��ȡ����ָ��
	while(1)
	{

		system("cls"); // ����
		// ִ�в˵���
		switch(opera)
		{
			case 1:
				spotsInfoQuery(); // ������Ϣ��ѯ
				break;
			case 2:
				spotsSearchQuery(); // ������·��ѯ
				break;
			case 3:
				cutPointQuery();  // ��ؽڵ�/���
				break;
			case 4:
				allPathQuery();		// ����֮����·��
				break;
			case 5:
				recommendationPath();  // �Ƽ�·��
				break;
			case 6:
				help();
				break;
			default:
				break;
		}
		if((k = getch()) == 27) // ����ָ�����ܺ󣬵��esc����BackSpace�˻ز˵�����
		{
			system("cls");
			updateUI(opera); // ���ز˵��󣬼�ס����˵���ʱ��״̬
			break;
		}
	}
}


void menu()
{
	int k;
	while(k = getch())
	{
		if(k == 224) // ���������Ƿ����
			k = getch();
		else if(k == 27) // �˵�������esc��ֱ���˳�
		{
			system("cls"); // ����
			FILE *fp = NULL; // ��ʼ���ļ�ָ��
			char buff[100]; // �ļ���ȡ������
			fp = fopen("exit.txt", "r");
			if(fp == NULL)
			puts("�ļ���ȡʧ�ܣ�");
			while(fgets(buff, 100, fp) != NULL)
			{
				printf("%s", buff );
			}
			fclose(fp); // �ر��ļ�ָ��
			//Sleep(1000); // �ȴ�1s��ر�
			exit(0);
		}
		else if(k == 13) // ����س�ִ�в˵����
		{
			exec(opera);
			break;
		}
		else if(k == 49 || k == 50 || k == 51 || k == 52 || k == 53 || k == 54) // ����˵������ֱ��ִ�в˵����,������1~6��ִ����Ӧ�Ĺ���
		{
			opera = k - 48;	// ���²˵���ָ��,�����ַ��������
			exec(opera); // ִ�в˵����
		}
		if(k == 72 || k == 119) //������w��������ϼ��������ͼ��
		{
			if(opera == 1)
				updateUI(opera);
			else
				updateUI(--opera);
		}

		if(k == 80 || k == 115)// ������s��������¼��������ͼ��
		{
			if(opera == 6)
				updateUI(opera);
			else
				updateUI(++opera);
		}
	}
}

void initMenu()
{
	// Ĭ�ϲ˵�
	FILE *fp = NULL; // ��ʼ���ļ�ָ�� e
	char buff[100]; // �ļ���ȡ������
	fp = fopen("menu.txt", "r");
	if(fp == NULL)
		puts("�ļ���ȡʧ�ܣ�");
	while(fgets(buff, 100, fp) != NULL)
	{
		printf("%s", buff );
	}
	fclose(fp); // �ر��ļ�ָ��
	while(1)
	{
		menu();
	}
}
/** �˵� **/
int main()
{
	system("mode con lines=32 cols=100");
	system("color f0"); // 3f 
	g = (Mgraph*)malloc(sizeof(Mgraph)); // ����ͼ�ṹ��
	create(g, "info.txt"); // ��ʼ��ͼ
	initMenu();
	return 0;
}
