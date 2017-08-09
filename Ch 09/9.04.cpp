/*编写函数，接受一对指向vector<int>的迭代器和一个int值。
在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到
*/
#include<vector>
using std::vector;

bool find(vector<int>::iterator beg, vector<int>::iterator end, int value)
{
	for (auto iter = beg; iter != end; ++iter)
		if (*iter == value) return true;
	return false;
}