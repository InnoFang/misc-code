#include <iostream> 
using namespace std; 

int main () {
	double x;
	while (cin >> x){
		double COS = 1;						 // cos ��ֵ�������� 
		double flag = -1;					 // ����λ 
		double de = 1; 						 // ��ĸ
		double mo = 1; 						 // ���� 
		int fac = 1;   						 // ���Ʒ�ĸ�Ľ׳� 
		for (int i = 1; ; i++) {
			de *= x * x; 					 // ÿ�μ� x ��ƽ�� 
			mo *= (fac * 2) * (fac * 2 - 1); // ��һ����ĸ=��ǰ��ĸ*2n* (2n - 1) 
			fac += 1; 
			double fraction = de / mo; 		 // ��ʽ 
			if (fraction < 1e-10) break; 	 // �����ʽС�ڸ�������Ϊ����С�����Բ��� 
			COS += flag * fraction; 		 // ��ӷ�ʽ
			flag *= -1;						 // ���·���λ 
		}
		cout << COS << endl;
	}
	return 0;
}
