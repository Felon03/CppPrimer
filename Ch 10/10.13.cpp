/*使用algorithm中的partition算法编写函数，接受一个string，返回一个bool值
	指出string是否有5个或者更多字符。使用此函数划分words。打印出长度大于等于5的元素。
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool is_length_less_than_five(const string &s)
{
	return s.size() < 5;
}

int main()
{
	vector<string> sv{ "the", "quick","red","fox","jumps","over","the", "slow","red","turtle" };
	auto iter = partition(sv.begin(), sv.end(), is_length_less_than_five);
	for (; iter != sv.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//auto f = [] {return 42; };
	//cout << f() << endl;
	return 0;
}