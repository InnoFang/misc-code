/*
Description
 ��������İ뾶ֵ�������������� 

Input
���������ж��飬ÿ��ռһ�У�ÿ�а���һ��ʵ������ʾ��İ뾶�� 

Output
�����Ӧ��������������ÿ���������ݣ����һ�У�������������λС���� 

Sample Input
1
1.5 

Sample Output
4.189
14.137 

Hint
 #define PI 3.1415927 
*/
#include<stdio.h>
#include<math.h>
#define PI 3.1415927 
int main()
{
	double r;
	while(scanf("%lf",&r) == 1)
	{
		printf("%.3lf\n",(4 * PI * r*r*r) / 3);
	}
	return 0;
}
