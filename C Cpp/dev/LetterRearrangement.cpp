/*
����һ���ֵ䣨��******��β����Ȼ�����������ɵ��ʣ�Ϊ����һ������w������Ҫ���ֵ����ҵ�������w����ĸ���ź�õ���
���ʣ��������ֵ����С�����˳����һ�����������������ڣ������:(�������뵥��֮���ÿո����и��������������뵥��
���в�����6��Сд��ĸ��ɡ��ֵ��еĵ��ʲ�һ�����ֵ������� 
*/
#define LOCAL
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char dic[2000][10], re[2000][10];
int n = 0;

int cmp_char(const void* a, const void* b)
{
	return (*(char*)a - *(char*)b);
}

int cmp_string(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}

int main()
{
	#ifdef LOCAL
	freopen("LetterRearrangement.in","r",stdin);
	freopen("LetterRearrangement.out","w",stdout);
	#endif
	while(1)
	{
		scanf("%s",dic[n]);
		if(dic[n][0] == '*')
		{
			break;
		}
		n++;
	}
	qsort(dic, n, sizeof(dic[0]), cmp_string); // ���ֵ�ĵ������� 
//	for(int i = 0; i < n; i++)
//	{
//		printf("%s ",dic[i]);
//	}
//	printf("\n");
	for(int i = 0; i < n; i++)
	{
		strcpy(re[i], dic[i]);
		qsort(re[i], strlen(re[i]), sizeof(re[i][0]), cmp_char);//��ÿ�����ʵ���ĸ�������� 
	}
//	for(int i = 0; i < n; i++)
//	{
//		printf("%s ",re[i]);
//	}
	char word[10];
	while(scanf("%s",word) == 1)
	{
		int found = 0, i;
		qsort(word, strlen(word), sizeof(word[0]), cmp_char);
		for( i = 0; i < n; i++)
		{
			if(strcmp(word,re[i]) == 0)
			{
				found = 1;
				printf("%s ",dic[i]);	
			} 
		}
		if(!found)
		{
			printf(":(");
		}
		printf("\n");
	}
	return 0;
}
