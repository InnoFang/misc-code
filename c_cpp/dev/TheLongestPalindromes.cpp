/*
*����һ���ַ��������������Ļ����Ӵ� 
*˼·��
*	1.��fgets��ȡ�ļ��е�ÿһ�е��ַ���
*	2.��isalpha�����ж��Ƿ�Ϊ��ĸ��������ĸ��toupper����ͬһ��Ϊ��д������p[]���鱣��ÿ���ַ��±� 
*	3.ö�ٻ��Ĵ����м�λ�ã�����Ϊ���Ĵ�����Ϊż�������������������������ÿһ������ڻ�ȡ���Ĵ����������������
��¼���Ĵ���ʼ�ͽ�����λ�� 

Ps:�������ַ�����Ҫ���м���д���Ӧ�ÿ��ǵ��ַ�������Ϊż���������������������������Ӧ�Ĵ���취 
*/
#define LOCAL 
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXN 5000 + 10
char  buf[MAXN], s[MAXN] , p[MAXN];//bufΪԭ���ַ�����sΪ����Ԥ������ַ�����p��������ÿ��ԭ���ַ���ÿ���ַ����±� 
int main()
{
#ifdef LOCAL
	freopen("TheLongestPalindromes.in","r",stdin);
	freopen("TheLongestPalindromes.out","w",stdout);
#endif
	int i,j,m = 0,max = 0,len,x,y;
	//�ڱ�֤����Խ�������¿�����gets��׼���� 
	fgets(buf,sizeof(s),stdin);//��ȡ�ļ��ڵ�ÿһ�е��ַ��� 
	len = strlen(buf);
	for(i = 0 ; i < len ; i++)
	{
		if(isalpha(buf[i]))
		{
			p[m] = i;
			s[m++] = toupper(buf[i]);//��ԭ���ַ���Ԥ���� 
		}				
	}
	for(i = 0 ;i < m ; i++)
	{
		//���Ĵ�����Ϊ����������� 
		for(j = 0 ; i - j >= 0 && i + j < m ; j++)
		{
			if(s[i-j] != s[i + j])
				break;
			if(2 * j + 1 >= max)
			{
				max = 2 * j + 1;		
				x = p[i - j];
				y = p[i + j];		
			}

		}
		//���Ĵ�Ϊż��������� 
		for(j = 0 ; i - j >= 0 && i + j + 1 < m ; j++)
		{
			if(s[i - j] != s[i + j + 1])
				break;
			if(2 * j + 2 > max)
			{
				max = 2 * j + 2;	
				x = p[i - j];
				y = p[i + j + 1];			
			}
		}
	}
	for(i = x ; i <= y ;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n");
	return 0;
}
