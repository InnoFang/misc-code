/*
Description
 ����ʽ���������£� 
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ... 
������������ö���ʽ��ǰn��ĺ͡� 

Input
����������2����ɣ�������һ��������m��m<100������ʾ����ʵ���ĸ������ڶ��а���m��������������ÿһ������(������Ϊn,n<1000������ö���ʽ��ǰn��ĺ͡� 

Output
����ÿ������ʵ��n��Ҫ���������ʽǰn��ĺ͡�ÿ������ʵ�������ռһ�У��������2λС���� 

Sample Input
2
1 2 

Sample Output
1.00
0.50 
*/
#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		while(n--)
		{
			double sum = 0;
			int flag = -1, m;
			scanf("%d",&m);
			for(int i = 1;i <= m; i++)
			{
				flag *= -1;
				sum += (1.0/i)*flag;
			}
			printf("%.2lf\n",sum);
		}
	}
	return 0;
}
