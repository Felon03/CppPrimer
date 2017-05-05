/*重写上一题函数，返回一个迭代器指向找到的元素。
注意，程序必须处理未找到给定值的情况
*/
#include<vector>

using std::vector;

using iter = vector<int>::iterator;

iter find(iter beg, iter end, int value)
{
	for (auto itera = beg; itera != end; ++itera)
		if (*itera == value) return itera;
	return end;
}