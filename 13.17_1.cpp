/*编写13.14中所描述的numbered和f，验证之前的答案*/
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

/*numbered类中没有自定义的拷贝构造函数，故不会生成新的序号，输出三个相同序号*/
void f(numbered s)
{
	std::cout << s.mysn << std::endl;
}

int main()
{
	numbered a, b = a, c = b;			// a.mysn = 1, b.mysn = 1, c.mysn = 1
	f(a);			// 输出1
	f(b);		// 输出1
	f(c);			// 输出1

	return 0;
}