/*编写13.15中所描述的numbered和f*/
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

/*当实参传入f中时，会调用拷贝构造函数生成新的序号，
故输出三个不同的序号，且比传入的实参的序号大1*/
void f(numbered s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;			// a.mysn = 1, b.mysn = 2, c.mysn = 3
	f(a);			// 输出2
	f(b);		// 输出3
	f(c);			// 输出4

	return 0;
}
