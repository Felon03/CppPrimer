
#include<iostream>
#include<string>

using namespace std;

// 6.36 编写一个函数的声明，使其返回数组的引用并且该数组包含10个string对象。不要使用尾置返回类型、decltype或者类型别名
string (&func(string (&arr)[10]))[10];

// 6.37
// 使用类型别名
using arrT = string[10];
arrT& func1(arrT& arr);
// 使用尾置返回类型
auto func2(arrT& arr)->string(&)[10];
// 使用decltype关键字
string arrS[10];
decltype(arrS) &func3(arrT& arr);

// 6.38
// 修改arrPtr函数，，使其返回数组的引用
int odd[] = { 1,3,4,7,9 };
int even[] = { 0, 2, 4, 6, 8 };
decltype(odd) &arrPtr(int i)
{
	return (i % 2) ? odd : even;
}