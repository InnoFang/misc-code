/*
Description
 ���ڱ��ʽn^2+n+41����n�ڣ�x,y����Χ��ȡ����ֵʱ������x,y��(-39<=x<y<=50)���ж��ñ��ʽ��ֵ�Ƿ�Ϊ������ 
 
Input
���������ж��飬ÿ��ռһ�У�����������x��y��ɣ���x=0,y=0ʱ����ʾ������������в������� 

Output
����ÿ��������Χ�ڵ�ȡֵ��������ʽ��ֵ��Ϊ�����������"OK",�����������Sorry��,ÿ�����ռһ�С� 

Sample Input
0 1
0 0 

Sample Output
OK 
*/
#include<stdio.h>
int is_prime(int n)
{
	for(int i = 2; i < n/2; i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int x, y;
	while(scanf("%d%d",&x,&y) == 2)
	{
		if(!x && !y)
		{
			break;
		}
		int ok = 1;
		for(int n = x; n <= y; ++n)
		{
			if(!is_prime(n*n + n + 41))
			{
				ok = 0;
			}
		}
		if(ok)
		{
			printf("OK\n");
		}
		else
		{
			printf("Sorry\n");
		}
	} 
	return 0;
}
