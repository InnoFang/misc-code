/*
Description
 ��ʵ���ľ���ֵ�� 

Input
���������ж��飬ÿ��ռһ�У�ÿ�а���һ��ʵ���� 

Output
����ÿ���������ݣ�������ľ���ֵ��Ҫ��ÿ���������һ�У����������λС���� 

Sample Input
123
-234.00 

Sample Output
123.00
234.00 
*/
#include<stdio.h>
#include<math.h>
double absolute(double a)
{
	if(a < 0)
	{
		a = 0 - a;
	}
	return a;
}
int main()
{
	double a;
	while(scanf("%lf",&a) == 1)
	{
		printf("%.2lf\n",absolute(a));
	}
}
