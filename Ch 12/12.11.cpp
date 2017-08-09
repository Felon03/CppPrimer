/*如果像下面这样调用process，会发生什么？*/

// 报错，当p被销毁时，p指向的内存会被第二次delete

#include<iostream>
#include<memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "inside the process function: " << ptr.use_count() << endl;
}

int main()
{
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p.get()));
	// shared_ptr<int>(p.get())生成一个临时shared_ptr变量
	// 并将其传入process函数，这个临时变量和q指向相同内存
	// 但不是p的拷贝，即独立创建的。其引用计数为1。
	// 在退出process时临时p指向的内存已经被释放
	// 当main函数结束时释放p就会出错。

	return 0;
}