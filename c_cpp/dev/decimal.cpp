/**
*����������a,b,c,���a/b��С����ʽ����ȷ��С�����cλ��a,b<=10e6 , c<=100
*����a=1,b=6,c=4ʱӦ���0.1667 
*/
#include<stdio.h>
int main()
{
	freopen("decimal.in","r",stdin);
	freopen("decimal.out","w",stdout);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) != EOF)
	{
		printf("%.*lf\n",c,(double)a/b);
	}
	return 0;
}
