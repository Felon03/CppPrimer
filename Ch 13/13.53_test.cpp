#include"13.53.h"
#include<chrono>

using namespace std::chrono;
using namespace std;

int main()
{
	auto t0 = high_resolution_clock::now();
	HasPtr hp1("Hello world"), hp2("Hello C Plus Plus"), *hp3 = new HasPtr("C++");
	hp1 = hp2;
	hp1 = std::move(*hp3);
	hp1 = hp2;
	hp1 = std::move(*hp3);
	hp1 = hp2;
	hp1 = std::move(*hp3);
	hp1 = hp2;
	hp1 = std::move(*hp3);
	auto t1 = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds>(t1 - t0).count() << " ms\n";
	return 0;
}

// 结果分析

// 当使用拷贝交换时
// call constructor
// call constructor
// call constructor
// call copy constructor						1
// call swap(HasPtr&, HasPtr&)		2
// call destructor									3
// call move constructor					1
// call swap(HasPtr&, HasPtr&)		2
// call destructor									3
// call destructor
// call destructor
// 平均用时： 10ms

// 当使用移动赋值运算符
// call constructor
// call constructor
// call constructor
// call copy assignment						1
// call move assignment					1
// call destructor
// call destructor
// 平均用时： 3ms