/*��д13.15����������numbered��f*/
#include<iostream>

class numbered {
public:
	numbered()
	{
		static int unique_id = 0;
		mysn = ++unique_id;
	}
	numbered(const numbered &rhs)
	{
		mysn = rhs.mysn + 1;
	}

public:
	int mysn;
};

/*��ʵ�δ���f��ʱ������ÿ������캯�������µ���ţ�
�����������ͬ����ţ��ұȴ����ʵ�ε���Ŵ�1*/
void f(numbered s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;			// a.mysn = 1, b.mysn = 2, c.mysn = 3
	f(a);			// ���2
	f(b);		// ���3
	f(c);			// ���4

	return 0;
}
