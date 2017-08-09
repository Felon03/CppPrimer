/* 下面代码调用了第413页中定义的process函数，解释此调用是否正确。*/

// 此调用是正确的

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
	process(shared_ptr<int>(p));

	cout << p.use_count() << endl;
	auto q = p;
	cout << p.use_count() << endl;
	cout << "the int p now points to is: " << *p << endl;

	return 0;
}