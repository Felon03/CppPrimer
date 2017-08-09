/*理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，
	为该类定义这些成员，每个成员都打印出自己的名字：

	struct X {
		X() { std::cout << "X()" << std::endl; }
		X(const X&) { std::cout<< "X(const X&)" << std::endl; }
	};
	给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同的方式使用X的对象：
	将它们作为非引用和引用参数传递；动态分配他们；将他们存放于容器中；诸如
	此类。观察程序的输出，指导你确认理解了什么时候会使用拷贝控制成员，以及
	为什么会使用他们。当你观察程序输出时，记住编译器可以略过对拷贝构造函数的
	调用。
*/

#include<iostream>
#include<vector>

class X {
public:
	// 构造函数
	X() { std::cout << "X()" << std::endl; }
	// 拷贝构造函数
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	// 拷贝赋值运算符
	X& operator= (const X &x)
	{
		std::cout << "X& operator=(const X &x)" << std::endl;
		return *this;
	}
	// 析构函数
	~X()
	{
		std::cout << "~X()" << std::endl;
	}
};

void f(const X &lx, X rx)
{
	std::vector<X> vec;
	vec.reserve(2);		
	vec.push_back(lx);
	//std::cout << "about to do push_back(bx)" <<std::endl;
	vec.push_back(rx);
	// When second element is added to the vector(the vec.push_back(rx);)
	// a resize of the vector's underlying stroage is done and the single element
	// already in the vector is copied to the new storage.
	// ref:https://stackoverflow.com/questions/32240542/the-c-primer-exercise-13-13-about-the-constructor
	// 当vec存入第二个元素时，vec需要重新分配地址（在没有reserve(2)的情况下）
	// 而此前vec中已经存在一个元素，故要将其拷贝到新的地址，此时会调用一次
	// 拷贝构造函数X(const X&);
	//std::cout << "done push_back(bx)" << std::endl;
}

int main()
{
	X *x = new X;
	f(*x, *x);
	delete	x;

	return 0;
}