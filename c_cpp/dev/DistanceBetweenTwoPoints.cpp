/*
Input
���������ж��飬ÿ��ռһ�У���4��ʵ����ɣ��ֱ��ʾx1,y1,x2,y2,����֮���ÿո������ 

Output
����ÿ���������ݣ����һ�У����������λС���� 

Sample Input
0 0 0 1
0 1 1 0 

Sample Output
1.00
1.41 
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double x1, y1, x2, y2;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2) == 4)
	{
		printf("%.2lf\n",sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
	}
	return 0;
}
