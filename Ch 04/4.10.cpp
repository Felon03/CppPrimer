/*为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止*/
#include<iostream>

using namespace std;

int main()
{
	int num;
	while (cin >> num&&num != 42)
	{
		cout << num << endl;
	}
	cout << "You have input number '42', program terminate." << endl;

	return 0;
}