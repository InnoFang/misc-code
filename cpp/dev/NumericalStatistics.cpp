/*
Description
 ͳ�Ƹ�����n�����У���������������ĸ����� 

Input
���������ж��飬ÿ��ռһ�У�ÿ�еĵ�һ����������n��n<100������ʾ��Ҫͳ�Ƶ���ֵ�ĸ�����Ȼ����n��ʵ�������n=0�����ʾ������������в�������  

Output
����ÿ���������ݣ����һ��a,b��c���ֱ��ʾ�����������и�������������ĸ����� 

Sample Input
6 0 1 2 3 -1 0
5 1 2 3 4 0.5
0 

Sample Output
1 2 3
0 0 5 
*/
#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		int negative = 0, zero = 0, positive = 0;
		while(n--)
		{
			float m;
			scanf("%f",&m);
			if(m == 0)
			{
				zero++;
			}
			else if(m > 0)
			{
				positive++;
			}
			else
			{
				negative++;
			}
		}
		printf("%d %d %d\n",negative, zero, positive);
	}
	return 0;
}
