#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int list[MAX_SIZE];
	int last;	
} SeqList;
/*˳���ĳ�ʼ�� ��L��Ϊָ����������ȶ�̬����洢�ռ䣬Ȼ�󣬽�����last ָ����Ϊ��1����ʾ����û������Ԫ��*/

SeqList* init_SeqList()
{
	SeqList *l;
	l = (SeqList*)malloc(sizeof(SeqList));
	l->last = -1;
	return l;  
}
/*
 ��������
(1) ��ai��an ˳�������ƶ���Ϊ��Ԫ���ó�λ�ã�
(2) ��x ����ճ��ĵ�i��λ�ã�
(3) �޸�last ָ��(�൱���޸ı�)��ʹ֮��ָ�����һ��Ԫ�ء�
���㷨��ע���������⣺
(1) ˳���������������MAXSIZE���洢��Ԫ����������˳�����������ʱ�ȼ���ռ��Ƿ����ˣ��ڱ���������²����������룬��������������
(2) Ҫ�������λ�õ���Ч�ԣ�����i ����Ч��Χ�ǣ�1<=i<=n+1������n Ϊԭ����
(3) ע�����ݵ��ƶ�����
*/
int insert_SeqList(SeqList *l, int i, int x)
{
	int j;
	if(l->last == MAX_SIZE - 1)/*��ռ����������ܲ���*/
	{
		printf("It's full!");
		return  -1;
	}
	if(i < 1 || i > l->last + 2)/*������λ�õ���ȷ��,����С�ڵ�һ�������һ���ĺ�һ��λ��*/
	{
		printf("Insert error!");
		return 0;
	}
	for(j = l->last; j >= i - 1; j--)
	{
		l->list[j+1] = l->list[j];	/* ����ƶ�*/
	}
	l->list[i-1] = x;/*��Ԫ�ز���*/
	l->last++;/*last��ָ�����Ԫ��*/
	return 1;/*����ɹ�������*/
}
/*
ɾ������
(1) ��ai+1��an ˳�������ƶ���
(2) �޸�lastָ��(�൱���޸ı�)ʹ֮��ָ�����һ��Ԫ�ء�
���㷨ע���������⣺
��1��ɾ����i��Ԫ�أ�i��ȡֵΪ1<=i<=n ,�����i��Ԫ�ز����ڣ���ˣ�Ҫ���ɾ��λ�õ���Ч�ԡ�
��2�������ʱ������ɾ��������ʱL->last��ֵΪ-1��������i<1 || i>L->last+1��Ҳ�����˶Ա�յļ�顣
��3��ɾ��ai ֮�󣬸������Ѳ����ڣ������Ҫ����ȡ��ai ������ɾ��
*/
int delete_SeqList(SeqList *l, int i)
{
	int j;
	if(i < 1|| i > l->last + 1)/*���ձ�ɾ��λ�õĺϷ���*/
	{
		printf("It does not exist!");
		return -1;
	}
	for(j = i; j <= l->last; j++) /*�����ƶ�*/
	{
		l->list[j-1] = l->list[j];
	}
	l->last--;
	return 1;/*ɾ���ɹ�*/
}
/*��ֵ����
���Ա��еİ�ֵ������ָ�����Ա��в��������ֵx��ȵ�����Ԫ�ء�
��˳�������ɸ�������򵥵ķ����ǣ��ӵ�һ��Ԫ��a1 �����κ�x�Ƚϣ�
ֱ���ҵ�һ����x��ȵ�����Ԫ�أ��򷵻�����˳����еĴ洢�±����ţ����߲�һ����
���߲��������û���ҵ���x ��ȵ�Ԫ�أ�����-1*/
int local_SeqList(SeqList *l, int x)
{
	int j;
	for(j = 0; j <= l->last; j++)
	{
		if(l->list[j] == x)
		{
			printf("%d's index is %d\n",x,j+1);
			return 1;
		}
	}
	if(j > l->last)
	{
		return -1;
	}
//  int i=0;
//	while(i<=L.last && L->data[i]!= x)
//	i++;
//	if (i>L->last) return -1;
//	else return i; /*���ص��Ǵ洢λ��*/
}
int main()
{
	SeqList *l;
	l = init_SeqList();
	int i, j, n;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&l->list[i]);
	}
	l->last = n;	
	insert_SeqList(l, 2, 5);
	printf("After inserted:\n");
	for(i = 0; i < l->last; i++)
	{
		printf("%d ",l->list[i]);
	}
	printf("\n");
	delete_SeqList(l, 3);
	printf("After deleted:\n");
	for(i = 0; i < l->last; i++)
	{
		printf("%d ",l->list[i]);
	}
	printf("\n");
	printf("Search the '5'...\n");
	local_SeqList(l, 5);
	return 0;
}
