/*
Description
 ����һ���������������������������ż����ƽ�����Լ����������������͡� 

Input
�������ݰ����������ʵ����ÿ�����ʵ������һ�У�����������m��n��ɡ� 

Output
����ÿ���������ݣ����һ�У�Ӧ������������x��y���ֱ��ʾ�ö�����������������ż����ƽ�����Լ����������������͡� 
�������Ϊ32λ�������Ա������� 

Sample Input
1 3
2 5 

Sample Output
4 28
20 152 
*/
#include<stdio.h>
int main()
{
	int m, n;
	while(scanf("%d%d",&m,&n) == 2)
	{
		int x = 0, y = 0;
		if(m > n)
		{
			int t;
			t = m;
			m = n;
			n = t;
		}
		for(int i = m; i <= n; i++)
		{
			if(i % 2 == 0)
			{
				x += i*i;
			}
			else
			{
				y += i*i*i;
			}
		}
		printf("%d %d\n",x, y);
	}
	return 0;
}
