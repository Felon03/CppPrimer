/*写出一条表达式用于确定一个整数是奇数还是偶数*/
#include<iostream>

using namespace std;

int main()
{
	cout << "请输入一个数" << endl;
	int num;
	cin >> num;
	if (num % 2 == 0)
		cout << num << "是偶数" << endl;
	else
		cout << num << "是奇数" << endl;

	return 0;
}