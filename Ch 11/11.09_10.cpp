#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

using namespace std;

int main()
{
	// 11.9 定义一个map，将单词与一个行号的lsit相关联，list中保存的是单词所出现的行号
	map<string, list<size_t>> m;

	// 11.10 可以定义一个vector<int>::iterator到int的map吗？
	// list<int>::iterator到int的map呢？对于两种情况，如果不能，解释为什么

	// 可以定义vector<int>::iterator到int的map, vector的迭代器支持“<”操作
	map<vector<int>::iterator, int> vm;

	// 可以定义list<int>::iterator到int的map
	// 编译可以通过
	map<list<int>::iterator, int> lm;

	// 但是不能使用，因为list的元素不是连续存储的，不支持比较操作
	std::list<int> li;
	lm.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));
	/*
	二进制“<”: 没有找到接受“const std::_List_iterator<std::_List_val<std::_List_simple_types<int>>>”类型的左操作数的运算符(或没有可接受的转换)
	CppPrimer	c:\program files (x86)\microsoft visual studio 14.0\vc\include\xstddef	239	
	*/
	return 0;
}