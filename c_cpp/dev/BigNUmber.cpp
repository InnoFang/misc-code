#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1000;
struct bign
{
	int len, s[maxn];
	bign()
	{
		memset(s,0,sizeof(s));
		len = 1;
	}
	//=�����أ����ַ���ת��Ϊ���� 
	bign operator=(const char *num)
	{
		len = strlen(num);
		for(int i = 0; i < len; i++)
		{
			s[i] = num[len-i-1] - '0';
		}
		return *this;
	}
	//=�����أ�������ת��Ϊ�ַ��� 
	bign operator=(int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;				
	}
	
	
	//bign ��ʼ�� 
	bign (int num)
	{
		*this = num;
	}
	bign (const char *num)
	{
		*this = num;
	}
	
	
	//����ʼ�������ת��Ϊ�ַ���
	string str() const
	{
		string res = "";
		for(int i = 0; i < len; i++)
		{
			res = (char)(s[i] + '0') + res;
		} 
		if(res == "")
			res = "0";	
		return res;
	}	 
	
	
	//+������
	bign operator+(const bign &b) const
	{
		bign c;
		c.len = 0;
		for(int i = 0, g = 0; g || i < max(len, b.len); i++) //g���ڽ�λ,
		//g || i < max(len, b.len) �����ǣ����� 3+9 �������ĳ��ȶ�Ϊ1���������������һ����λ����ôѭ����Ҫ����һ�Σ����������λ�ŵ�������һλ 
		{
			int x = g;  //�����λ 
			if(i < len)
			{
				x += s[i];
			}
			if(i < b.len)
			{
				x += b.s[i];
			}
			c.s[c.len++] = x % 10;
			g = x / 10; //����λ 
		}
		return c; 
	} 
	
	
	//+=����
	bign operator+=(const bign& b)
	{
		*this = *this + b;
		return *this;	
	} 
	
	
	//<������
	bool operator<(const bign &b) const
	{
		if(len != b.len)
		{
			return len < b.len;
		}
		for(int i = len - 1; i >= 0; i--)
		{
			if(s[i] != b.s[i])
			{
				return s[i] < b.s[i];
			}
		}
		return false;
	} 
	//> , <= , >= , != , == ������
	bool operator>(const bign &b) const 
	{
		return b < *this;
	}
	bool operator<=(const bign &b) const 
	{
		return !(b < *this);
	} 
	bool operator>=(const bign &b) const 
	{
		return !(*this < b);
	}
	bool operator!=(const bign &b) const 
	{
		return b < *this || *this < b;
	}
	bool operator==(const bign &b) const 
	{
		return !(b < *this) && !(*this < b);
	}
};
//���룬������������
	istream& operator>>(istream &in, bign &x)
	{
		string s;
		in >> s;
		x = s.c_str();
		return in;
	}
	ostream& operator<<(ostream &out, bign &x)
	{
		out << x.str();
		return out;	
	} 
int main()
{
	bign a, b, c, d, e, f;
	c = 0;
	while(cin >> b)
	{
		if(b == c)
			break;
		a += b;
	}
	cout << a << endl;
//	while(cin >> a >> b)
//	{
//		c = a + b;
//		cout << "a + b = " << c << endl;
//		c += a;
//		cout << "c += a ==> " << c << endl;
//		bool h = a < b;
//		cout << "a < b ==> " << h << endl;
//		h = a>b;
//		cout << "a > b ==> " << h << endl;
//		cin >> d;
//		h = a<=d;
//		cout << "a <= d ==> " << h << endl;
//		cout << "input the e:"<<endl;
//		cin >> e;
//		h = a>=e;
//		cout << "a >= e ==> " << h << endl;
//		cout << "input the f:" << endl;
//		cin >> f;
//		h = a==f;
//		cout << "a == f ==> " << h << endl;
//		h = a!=f;
//		cout << "a != f ==> " << h << endl; 
//	}
	return 0;
}
