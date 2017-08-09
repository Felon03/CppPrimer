/*编写13.16中所描述的numbered和f*/
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

/*f中的参数是引用传递，不会调用拷贝构造函数，故输出的序号和传入的参数相同*/
void f(const numbered & s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;			// a.mysn = 1, b.mysn = 2, c.mysn = 3
	f(a);		// 输出1
	f(b);	// 输出2
	f(c);		// 输出3

	return 0;
}