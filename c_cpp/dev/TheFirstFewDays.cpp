/*
Description
 ����һ�����ڣ������������Ǹ���ĵڼ��졣 

Input
���������ж��飬ÿ��ռһ�У����ݸ�ʽΪYYYY/MM/DD��ɣ�����μ�sample input ,���⣬��������ȷ�����е����������ǺϷ��ġ� 

Output
����ÿ���������ݣ����һ�У���ʾ�������Ǹ���ĵڼ��졣 

Sample Input
1985/1/20
2006/3/12 

Sample Output
20
71 
*/
#include<stdio.h>
int is_leap(int y)
{
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0; 
	}
}
int main()
{
	int y, m, d;
	while(scanf("%d/%d/%d",&y,&m,&d) == 3)
	{
		int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		if(is_leap(y))
		{
			days[1] = 29;
		}
		int total = 0;
		for(int i = 1; i <= 12; i++)
		{
			if(i < m)
			{
				total += days[i-1];
			}
		}
		total += d;
		printf("%d\n",total);
	}
	return 0;
}
