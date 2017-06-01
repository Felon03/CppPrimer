/*  如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。
	编写包含这种错误的程序，观察编译器如何诊断这种错误。	
*/
#include<iostream>
#include<memory>

int main()
{
	std::unique_ptr<int> p1(new int(42));
	// 拷贝
	//std::unique_ptr<int> p2(p1);	// 尝试引用已删除的函数
	std::unique_ptr<int> p3;
	// 赋值
	//p3 = p1;		// 尝试引用已删除的函数
	std::cout << *p1 << std::endl;
	p1.reset();
	return 0;
}