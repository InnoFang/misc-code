#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lc{
	char *card_num; // ���� 
	char *name;     // ���� 
	char *major;	// רҵ / ϵ
	char *class_num; 	// �༶�� 
	struct lc * next;
} library_card;

library_card * head = NULL; // ͷ���
library_card * curr = NULL; // ����������һ��Ԫ�أ��������Ԫ�� 
char info[100]; // ���ڻ�ȡ������Ϣ 

// ���鿨��Ϣ��ʼ�����û���Ϣ���� 
library_card * initInfo(library_card * lc)
{
	int info_length;
	lc = (library_card*)malloc(sizeof(library_card));
	
	puts("���뿨��:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->card_num = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->card_num, info);
	
	puts("��������:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->name = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->name, info);
	
	puts("����ϵ��:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->major = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->major, info);
	
	puts("����༶:");
	scanf("%s", info);
	info_length = strlen(info);
	lc->class_num = (char*)malloc(info_length * sizeof(char));
	strcpy(lc->class_num, info);
	
	lc->next = NULL;
	
	puts("��ӳɹ�");
	/*//test
	printf("%s\n", lc->card_num);
	printf("%s\n", lc->name);
	printf("%s\n", lc->major);
	printf("%s\n", lc->class_num);
	*/
	return lc;
}

// ���鿨��ʼ�������ǵ�һ����ʱ����ͷ�ڵ�ָ���� 
library_card * initLibraryCard(library_card * head)
{
	//puts("init");
	library_card * lc;
	lc = initInfo(lc);
	head->next = lc;
	curr = lc;
	return head;
}

// ��ӽ��鿨 
library_card * addLibraryCard(library_card * head)
{
//	puts("add");
	if(head->next == NULL)
		return initLibraryCard(head);
	library_card * lc;
	lc = initInfo(lc);
	curr->next = lc;
	curr = lc;
	return head;
}

// ��������������Ԫ��
void reverseInfo(library_card * pr, library_card * cu, library_card * ne) 
{
//	puts("reverse info");
	if(ne == NULL)
		return ;
	library_card * pre = pr; // cu��ǰһ��Ԫ�� 
	library_card * cur = cu; // ��ǰcuԪ�� 
	library_card * nex = ne; // cu�ĺ�һ��Ԫ�� 
	
	cur->next = nex->next;
	nex->next = pre->next;
	pre->next = nex;
} 

// ð������ 
library_card * sortLibraryCardByCardNum(library_card * head)
{
//	puts("sort");
	if(head == NULL && head->next == NULL)
	{
		puts("û�п��������Ϣ~"); 
		return head;
	}
	library_card * p = head->next;
	library_card * q = p->next;
	library_card * cu = head->next; //��ǰԪ�� 
	library_card * pr = head; // ��ǰԪ�ص�ǰһ��Ԫ��  
	while(p)
	{
		while(q)
		{
			if(strcmp(p->card_num, q->card_num) > 0)
			{
				reverseInfo(pr, p, p->next);
			}
			q = q->next;
			//printf("p's card_num is %s\n", p->card_num);
		} 
		pr = p;
		p = p->next;
	} 
	puts("�������~");
	return head;
}

library_card * searchLibraryCardByMajor(library_card * head)
{
//	puts("search");
	int isFound = 0; // �Ƿ��и�ϵ�Ľ��鿨��Ϣ 
	int order = 0; // ���鿨��Ϣ��� 
	puts("����Ҫ���ҵ�ϵ��:");
	scanf("%s", info);
//	puts(info);
	library_card * lc = head->next;
	while(lc)
	{
//		puts(lc->name);
//		puts(lc->major);
		if(strcmp(lc->major, info) == 0)
		{
			if(!isFound)
			{
				printf("\n+----------   %-8sϵ���鿨��Ϣ    -------+\n",info);
				printf("| ");
				printf("|%-10s", "����");
				printf("|%-10s", "����");
				printf("|%-17s", "ϵ��");
				printf("|%-10s", "�༶");
				printf("|\n");
				isFound = 1;
			}
			printf("|%d", ++order);
			printf("|%-10s", lc->card_num);
			printf("|%-10s", lc->name);
			printf("|%-17s", lc->major);
			printf("|%-10s", lc->class_num);
			printf("|\n");
		}
		lc = lc->next;
	}
	if(!isFound)
		puts("û�и�ϵ�Ľ��鿨��Ϣ~");
	else
		puts("+----------------------------------------------------+");
	return NULL;
}

void menu()
{
	puts(" ");
	puts("		+--����֤��Ϣ����ϵͳ--+");
	puts("		|                      |");
	puts("		|  ��Ϣ¼��(1)         |");
	puts("		|  ��Ϣ����(2)         |");
	puts("		|  ��Ϣ����(3)         |");
	puts("		|                      |");
	puts("		|  �˳�(0)             |");
	puts("		+----------------------+");
	puts(" ");
}

int main()
{
	int opera;		// ָ�� 
	int isExit = 0; // �Ƿ��˳� 
	char isAddNext; // �Ƿ������� 
	head = (library_card*)malloc(sizeof(library_card));
	head->next = NULL;
	head->card_num = NULL; // ���� 
	head->name = NULL;     // ���� 
	head->major = NULL;	   // רҵ / ϵ
	head->class_num = NULL; 	// �༶�� 
	system("mode con lines=30 cols=70");
	while(1)
	{
		menu();
		printf("ָ������: ");
		scanf("%d", &opera);
		puts("- - - - - - - - - - - - - - - - ");
		switch(opera)
		{
			case 1:
				isAddNext = 'y';
				while(isAddNext == 'y')
				{
					addLibraryCard(head); // ��ӽ��鿨��Ϣ 
					while(1) // ���û�ѡ���Ƿ���������Ϣ��y->������n->ֹͣ����Ϊ����ָ������ѯ�� 
					{
						puts("�Ƿ�������(y/n)?");
						getchar(); // �Ե��س� 
						isAddNext = getchar();
						tolower(isAddNext); // ���ַ�ת��ΪСд����ֹ�û������д 
						if(isAddNext == 'y' || isAddNext == 'n')
							break;
					} 
				}
				system("cls");
				break;
			case 2:
				sortLibraryCardByCardNum(head);
				system("pause");
				system("cls");
				break;
			case 3:
				searchLibraryCardByMajor(head);
				system("pause");
				system("cls");
				break;
			case 0:
				isExit = 1;
				break;
			default:
				puts("��������ȷָ��");
				system("pause");
				system("cls");
				break;
		}
		if(isExit)
			break;
	}
	return 0;
}

/*
1
1507064146
����
�������ѧ�뼼�� 
15070641
y
1507064132
����
�������ѧ�뼼��
15070641
y
1507064112
���� 
�������ѧ�뼼��
15070641
n
3
�������ѧ�뼼��

*/
