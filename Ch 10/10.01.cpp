/*头文件algorithm中定义了一个名为count的函数，它类似find，接受一对迭代器和一个值作为参数。
count返回给定值在序列中出现的次数。
编写程序，读取int序列存入vector中，打印有多少个元素的值等于给定值
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,0 };
	int val = 1;
	auto result = count(ivec.begin(), ivec.end(), val);
	cout << val << " appeared " << result << " times." << endl;

	return 0;
}