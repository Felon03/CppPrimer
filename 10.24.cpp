/*给定一个string，使用bind和check_size在一个int的vector中查找第一个大于string长度的值*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

auto find_first_bigger(const vector<int> &v, const string &s)
{
	return find_if(v.begin(), v.end(),
		bind(check_size, s, _1));
}

int main()
{
	vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string s = "test";
	// 方法1，直接使用find_if
	auto iter = find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
	/*
	************************
	 * find_if()
	 * find_if()算法接受三个参数
	 * 首先接受一对迭代器，表示一个范围
	 * 第三个参数是一个谓词，find_if对输入序列中的每个元素调用给定的这个谓词，
	 * 它返回第一个是谓词返回非0值的元素，如果不存在，则返回尾迭代器。
	 *************************
	 */
	cout << *iter << endl;
	// 方法2，调用find_first_bigger()函数
	auto iter1 = find_first_bigger(ivec, s);
	cout << *iter1 << endl;

	return 0;
}