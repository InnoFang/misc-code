#include<stdio.h>
#include<string.h>
const int  maxn = 3000;
int f[maxn];
int main()
{
	int i, j, n;
	scanf("%d",&n);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(i = 2; i <= n; i++)
	{
		int c = 0;//�����λ 
		//ģ��˷� 
		for(j = 0; j < maxn; j++)
		{
			int s = f[j] * i + c;//��ø���λ������i�ĳ˻� 
			f[j] = s % 10;//���õ��Ļ�ȡ�࣬��Ϊ������˺��λ�ϵ��� 
			c = s / 10;//�������ĳ˻�����9���ͽ�λ 
		}
	}
	for(j = maxn - 1; j >= 0; j--)
	{
		if(f[j])
			break;
	}
	for(i = j; i >= 0; i--)
	{
		printf("%d",f[i]);
	}
	printf("\n");
	return 0;
}
