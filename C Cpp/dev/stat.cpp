#include<stdio.h>
#include<stdlib.h>
int main()
{
	freopen("stat.in","r",stdin);
	freopen("stat.out","w",stdout);
	int x,*s,t,i,m,n;//x��ʾҪ�������ĸ���,sΪ��̬�ڴ�������������, tΪ���������i����ѭ����m��ʾ�жϱ�׼��n���ڼ�¼С�ڱ�׼�õ����� 
	while(scanf("%d",&x) == 1)
	{
		n = 0;
		s = (int*) malloc(x);
		for(i = 0 ; i < x ; i++)
		{
			scanf("%d",&t);
			s[i] = t;
		}
		scanf("%d",&m);
		for(i = 0 ; i < x ; i++)
		{
			if(s[i] < m)
				n++;
		}
		
		printf("%d\n",n);
		free(s);
	}
}
