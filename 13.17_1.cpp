/*��д13.14����������numbered��f����֤֮ǰ�Ĵ�*/
#include<iostream>

class numbered {
public:
	numbered()
	{
		static int unique_id = 0;
		mysn = ++unique_id;
	}

public:
	int mysn;
};

/*numbered����û���Զ���Ŀ������캯�����ʲ��������µ���ţ����������ͬ���*/
void f(numbered s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);			// ���1
	f(b);		// ���1
	f(c);			// ���1

	return 0;
}