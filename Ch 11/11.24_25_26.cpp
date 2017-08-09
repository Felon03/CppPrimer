#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	// 11.24 下面程序完成什么功能？
	map<int, int> m;
	m[0] = 1;
	// 向map m中添加一组关键字为0， 值为1的元素
	for (const auto &e : m) cout << e.first << " " << e.second << endl;

	// 11.25 对比下面程序与上一题程序
	vector<int> v;
	v[0] = 1;
	 //vector v为空，故无法访问v[0], 因此该程序无意义
	for (const auto &e : v) cout << e << endl;

	// 11.26 可以用什么类型来对一个map进行下标操作？
	// 下标运算符返回的类型是什么？
	// 请给出一个具体的例子-- 即定义一个map，然后写出一个可以用来对map
	// 进行下标操作的类型以及下标运算符将会返回的类型
	map<int, int> map = { {1,2},{3,10} };

	std::map<int, int>::key_type type = 1;
	// 可以使用int类型来对map进行下标操作

	std::map<int, int>::mapped_type return_type = map[type];
	// 下标运算符返回的类型也可以是int

	return 0;
}