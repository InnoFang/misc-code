/*
*��nյ�ƣ����1~n����һ���˰����еƴ򿪣��ڶ����˰������б��Ϊ2�ı����Ŀ���(��Щ�ƽ����ص�)����3���˰������б��
*3�ı����Ŀ���(���عص��Ľ����򿪣����ŵĵƽ����ر�)���������ơ�һ����k���ˣ����������Щ�ƿ��ţ�����n��k�����
*���ŵĵƱ�š�k<=n<=1000
*sample input
*7 3
sample output
*1 5 6 7   
*/#include<stdio.h>
#include<string.h>
#define MAXN 1000 + 10
int arr[MAXN];
int main()
{
	int n , k , i , j;
	while(scanf("%d%d",&n,&k) == 2)
	{
		memset(arr,0,sizeof(arr));	
		for(i = 1 ; i <= k ; i++)
		{
			for(j = 1 ; j <= n ; j++)
			{
//				if(i % (j - 1) == 0)
//				{
//					if(arr[j - 1] == 0)
//						arr[j - 1] = 1;
//					else
//						arr[j - 1] = 0;
//				}
				if(j % i == 0)
					arr[j] = !arr[j];
			}
		}
		for(i = 1 ; i <= n ; i++)
		{
			if(arr[i] == 1)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
