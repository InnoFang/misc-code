/* 
����һЩѧ���ĳɼ����ĸ��������ֵĴ�����ࣿ����ж�����У���С�������
TASK1��������Ϊ������һ�ٵķǸ�����
TASK2��������Ϊ������һ�ٵķǸ�ʵ��������ౣ����λС�� 
*/
#include<stdio.h>
#include<string.h>
//#define TASK
#define MAXN 101
int main()
{
	//����ɼ�Ϊ���� 
	#ifdef TASK 
	int rank[MAXN],n,i,max;
	memset(rank,0,sizeof(rank));
	while(scanf("%d",&n) == 1)
	{
		rank[n]++;
	}
	max = rank[0];
	for(i = 1 ;i < MAXN ;i++)
	{
		if(max < rank[i])
			max = rank[i];
	}
	for(i = 0 ;i < MAXN ;i++)
	{
		if(rank[i] == max)
			printf("%d\n",i);
	}
	#else
	//����ɼ�Ϊ���� ��Ҳ���Դ���ʵ�� 
	float score[MAXN],rank[MAXN],list[MAXN],x,t;
	int i,j,flag = 0,m = 0,n = 0,p = 0,max;
	memset(score,0,sizeof(score));
	memset(rank,0,sizeof(rank));
	//������������м�⣬���Ѿ����������ôֱ�Ӽ��������������飬����ͼ������鲢���� 
	while(scanf("%f",&x) == 1)
	{
		flag = 0;
		for(i = 0 ; i < MAXN ;i++)
		{
			if(x == score[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			rank[i]++;
		}
		else
		{
			score[m++] = x;
			rank[n++]++;
		}			
	}	
	//���ɼ����ֵ������� 
	max = rank[0];
	for(i = 1 ; i < n;i++)
	{	
		if(max < rank[i])
			max = rank[i];
	}
	//������������ͬ�ĳɼ�����list���� 
	for(i = 0 ;i < n ; i++)
	{
		if(max == rank[i])
		{
		//			printf("%.2f\n",score[i]);	
			list[p++] = score[i];
		}
	}
	// ��list����ĳɼ���С�������� 
	for(i = 0 ; i < p - 1; i++)
	{
		for(j = 0 ; j <= i ;j++)
		{
			if(list[j] > list[j+1])
			{
				t = list[j];
				list[j] = list[j+1];
				list[j+1] = t;
			}
		}
	}
	for(i = 0 ; i < p ;i++)
	{
		printf("%.2f\n",list[i]);
	}
	#endif
	return 0;
}
