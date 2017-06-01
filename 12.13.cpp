/* 如果执行下面的代码，会发生什么*/
#include<iostream>
#include<memory>

int main()
{
	auto sp = std::make_shared<int>();
	auto p = sp.get();
	delete p;

	// delete p会释放sp指向的内存
	// main()函数结束时会自动释放智能指针sp，
	// 造成二次释放
	return 0;
}