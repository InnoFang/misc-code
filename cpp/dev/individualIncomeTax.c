/*������˰�˸��������룬����Ӧ�ɸ�������˰*/
#include <stdio.h>
int main()
{
	double salary; 	// ����
	double taxRate;	// ˰�� 
	double deduction;// �۳��� 
	double tax;	//��������˰˰�� 
	printf("�����������");
	scanf("%lf", &salary);
	if(salary < 500)	// ���� 1 
	{
		taxRate = 5;
		deduction = 0;
	}
	else if(salary >= 500 && salary < 2000)  // ���� 2 
	{
		taxRate = 10;
		deduction = 25;
	}
	else if(salary >= 2000 && salary < 5000) // ���� 3 
	{
		taxRate = 15;
		deduction = 125;
	}
	else if(salary >= 5000 && salary < 20000)  // ���� 4 
	{
		taxRate = 20;
		deduction = 375;
	}
	else if(salary >= 20000 && salary < 40000) // ���� 5 
	{
		taxRate = 25;
		deduction = 1375;
	}
	else if(salary >= 40000 && salary < 60000) // ���� 6 
	{
		taxRate = 30;
		deduction = 3375;
	}
	else if(salary >= 60000 && salary < 80000) // ���� 7	
	{
		taxRate = 35;
		deduction = 6375;
	}
	else if(salary >= 80000 && salary < 100000)// ���� 8 
	{
		taxRate = 40;
		deduction = 10375;
	}
	else if(salary >= 100000)	// ���� 9 
	{
		taxRate = 45;
		deduction = 15375;
	}
	tax = (salary - 1600) * taxRate * 0.01 - deduction; // �����������˰˰�� 
	printf("Ӧ�ɸ�������˰˰��: %lf\n", tax);
	return 0;
}
