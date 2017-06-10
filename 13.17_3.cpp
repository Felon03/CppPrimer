/*��д13.16����������numbered��f*/
#include<iostream>

class numbered {
public:
	numbered()
	{
		static int unique_id = 0;
		mysn = ++unique_id;
	}

	numbered(const numbered &s)
	{
		mysn = s.mysn + 1;
	}

public:
	int mysn;
};

/*f�еĲ��������ô��ݣ�������ÿ������캯�������������źʹ���Ĳ�����ͬ*/
void f(const numbered & s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;			// a.mysn = 1, b.mysn = 2, c.mysn = 3
	f(a);		// ���1
	f(b);	// ���2
	f(c);		// ���3

	return 0;
}