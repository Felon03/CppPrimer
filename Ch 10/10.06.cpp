/*编写程序，使用fill_n将一个序列中的int值都设置为0*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	std::vector<int>	ivec = { 1,2,3,4,5,6,7,8 };
	std::fill_n(ivec.begin(), ivec.size(), 0);
	for (const auto &x : ivec)
		cout << x << " ";
	cout << endl;

	return 0;
}