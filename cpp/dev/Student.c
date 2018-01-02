#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct s{
	char name[5];
	int id;
	char phone[11];
	struct s *next;
} Student;

Student *init_student(Student *head, Student *curr, char *name, int id, char *phone)
{
	Student *p = (Student*)malloc(sizeof(Student));
	strcpy(p->name, name);
	p->id = id;
	strcpy(p->phone, phone);
	p->next = NULL;
	head->next = p;
	curr = p;
	printf("��ӳɹ���\n\n");
	return p;
}

Student *add_student(Student *head, Student *curr, char *name, int id, char *phone)
{
	if(NULL == head->next)
	{
		return init_student(head, curr, name, id, phone);
	}
	Student *p = (Student*)malloc(sizeof(Student));
	strcpy(p->name, name);
	p->id = id;
	strcpy(p->phone, phone);
	p->next = NULL;
	curr->next = p;
	curr = p;
	printf("��ӳɹ���\n\n");
	return p;
}

Student *find(Student *head, int local)
{
	int j = 0;
	Student *p = head;
	if(local < 0)
	{
		printf("��%d��λ�ò�����\n", local);
		return NULL;
	}
	else if(local == 0)
	{
		return p;
	}
	while(p && local != j)
	{
		p = p->next;
		j++;
	}
	return p;
}

Student *insert_student(Student *head, int local, char *name, int id, char *phone)
{
	Student *p, *q;
	q = find(head, local - 1);
	if(!q)
	{
		printf("�޷��������ݣ�\n");
		return head;
	}
	p = (Student*)malloc(sizeof(Student));
	strcpy(p->name, name);
	p->id = id;
	strcpy(p->phone, phone);
	p->next = q->next;
	q->next = p;
	printf("����ɹ���\n");
	return head;
}

Student *query_student(Student *head, char *name)
{
	if(NULL == head)
	{
		printf("ѧ��ͨѶ¼Ϊ�գ�\n");
		return NULL;
	}
	Student *p = head->next;
	while(p)
	{
		if(strcmp(p->name, name) == 0)
		{
			break;
		}
		p = p->next;
	}
	return p;
}

Student *delete_student(Student *head, char *name)
{
	Student *pre = head, *q;
	q = head->next;
	if(!query_student(head, name))
	{
		printf("û������Ϊ:%s��ѧ����¼��\n",name);
		return NULL;
	}
	while(q && strcmp(q->name, name) != 0)
	{
		pre = q;
		q = q->next;
	}
	if(q)
	{
		pre->next = q->next;
		free(q);
	}
	printf("ɾ���ɹ�!\n");
	return head;
}

void print_student(Student *head)
{
	Student *p = head->next;
	int size = 1;
	printf("+----------------------------ѧ��ͨѶ¼----------------------------+\n");
	while(p)
	{
		printf("|%d|������%-10s	ѧ�ţ�%-15d	�绰��%-12s |\n", size++, p->name, p->id, p->phone);
		p = p->next;
	}
	printf("+------------------------------------------------------------------+\n");
}

int main()
{
	int order;		/*������*/
	int addNum;		/*���ѧ����������*/
	int local;		/*��������λ��*/
	int isExit = 0;	/*�Ƿ��˳�*/
	int id;			/*ѧ��ѧ��*/
	char name[5];	/*ѧ������*/
	char phone[11];	/*ѧ���绰*/
	Student *head = (Student*)malloc(sizeof(Student));;	/*ͷ���*/
	Student *curr = head->next = NULL;	/*��¼��ǰ����ַ�������������*/
	Student *temp = NULL;	/*������ʱ�ṹ�����*/
	int i, j;
	while(1)
	{
		printf("\n+------ָ��˵�------+\n");
		printf("|                    |\n");
		printf("|  ���ѧ������(1)   |\n");	/*��ʼ��ѧ�����ݱ����������*/
		printf("|  ����ѧ������(2)   |\n");
		printf("|  ɾ��ѧ������(3)   |\n");
		printf("|  ���ѧ������(4)   |\n");	/*��ӡ�������ѧ������*/
		printf("|  ��ѯѧ������(5)   |\n");	/*�������ֲ�ѯѧ����¼*/
		printf("|                    |\n");
		printf("|  �˳�(0)           |\n");
		printf("+--------------------+\n");
		printf("\n���������ָ�");
		scanf("%d", &order);
		switch(order)
		{
			case 1:
				printf("\n����Ҫ������ݵ���Ŀ��");
				scanf("%d", &addNum);
				for(i = 0; i < addNum; i++)
				{
					printf("������������");
					scanf("%s", name);
					printf("������ѧ�ţ�");
					scanf("%d", &id);
					printf("������绰��");
					scanf("%s", phone);
					curr = add_student(head, curr, name, id, phone);
				}
				break;
			case 2:
				printf("\n������Ҫ�����λ�ã�");
				scanf("%d", &local);
				printf("������������");
				scanf("%s", name);
				printf("������ѧ�ţ�");
				scanf("%d", &id);
				printf("������绰��");
				scanf("%s", phone);
				insert_student(head, local, name, id, phone);
				break;
			case 3:
				printf("������Ҫsɾ����ѧ�������֣�");
				scanf("%s", name);
				delete_student(head, name);
				break;
			case 4:
				print_student(head);
				break;
			case 5:
				printf("������Ҫ��ѯ��ѧ�������֣�");
				scanf("%s", name);
				temp = query_student(head, name);
				if(temp)
				{
					printf("+----------------------------��ѯ���-----------------------------+\n");
					printf("|������%-10s	ѧ�ţ�%-15d	�绰��%-12s|\n", temp->name, temp->id, temp->phone);
					printf("+-----------------------------------------------------------------+\n");
				}
				else
					printf("\nû�и�ѧ����¼��\n");
				break;
			case 0:
				isExit = 1;
				break;
			default:
				printf("\nָ���������������룡\n");
				break;
		}
		if(isExit)
			break;
	}
	printf("�������˳�\n");
	return 0;
}

