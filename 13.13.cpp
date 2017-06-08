/*理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，
	为该类定义这些成员，每个成员都打印出自己的名字：

	struct X {
		X() { std::cout << "X()" << std::endl; }
		X(const X&) { std::cout<< "X(const X&)" << std::endl; }
	};
	给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同的方式使用X的对象：
	将它们作为非引用和引用参数传递；动态分配他们；将他们存放于容器中；诸如
	此类。观察程序的输出，指导你恶恶人理解了什么时候会使用拷贝控制成员，以及
	为什么会使用他们。当你观察程序输出时，记住编译器可以略过对拷贝构造函数的
	调用。
*/

#include<iostream>
#include<vector>

class X {
public:
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator= (const X &x)
	{
		std::cout << "X& operator=(const X &x)" << std::endl;
		return *this;
	}

	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

void f(const X&lx, X rx)
{
	std::vector<X> vec;
	vec.push_back(lx);
	vec.push_back(rx);
}

int main()
{
	X *x = new X;
	f(*x, *x);
	delete	x;

	return 0;
}