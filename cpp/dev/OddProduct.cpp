/*
Description
 ����n�������������������������ĳ˻��� 

Input
�������ݰ����������ʵ����ÿ������ʵ��ռһ�У�ÿ�еĵ�һ����Ϊn����ʾ��������һ����n����������n������������Լ���ÿ�����ݱض����ٴ���һ�������� 

Output
���ÿ�����е����������ĳ˻������ڲ���ʵ�������һ�С� 

Sample Input
3 1 2 3
4 2 3 4 5 

Sample Output
3
15 
*/
#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int m, product = 1;
		while(n--)
		{
			scanf("%d",&m);
			if(m % 2 == 1)
			{
				product *= m;
			}
		}
		printf("%d\n",product);
	}
	return 0;
} 
