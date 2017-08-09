/*编写程序处理一个vector<string>,其元素都表示整型值。计算vector中所有元素的和。
修改程序，使之计算表示浮点值的string之和。
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> ivec{ "0","1", "1", "2", "3", "4", "5", "100", "15", "-15" };
	vector<string> dvec{ "0.5","1.7","3.6","4.9","10.68","7.23","6.59" };
	// 计算整型值的string之和
	int result = 0;
	for (const auto &x : ivec)
	{
		result += stoi(x);
	}
	cout << result << endl;

	// 计算浮点值的string之和
	double dresult = 0.0;
	for (const auto &x : dvec)
		dresult += stod(x);
	cout << dresult << endl;

	return 0;
}