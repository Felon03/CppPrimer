/* p和q的定义如下，对于接下来的对process的每个调用，
	如果合法，解释他做了什么，如果不合法，解释错误原因
*/
#include<iostream>
#include<memory>

using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "inside process funtion: " << ptr.use_count() << endl;
}

int main()
{
	auto p = new int();
	auto sp = make_shared<int>();

	// 合法，拷贝sp到process()函数中进行处理，
	// 在process运行的过程中sp的引用计数为2
	//process(sp);

	// 非法，不能将一个内置指针隐式转换为一个智能指针
	//process(new int());

	// 非法，不能将一个内置指针隐式转换为一个智能指针
	//process(p);

	// 合法，但不推荐这么做。
	// process()结束后会释放p所指向的内存，
	// 在main中delete p会发生错误，即二次释放
	//process(shared_ptr<int>(p));

	return 0;
}