/*编写一段程序，使用do while循环重复地执行下述任务：首先提示用户输入两个string对象，然后挑出较短的那个并输出它*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	/*不断提示用户输入一对字符串，然后输出较短的*/
	string rsp;	// rsp用于判断是否继续一轮新的输入
	do
	{
		cout << "Please enter two strings:" << endl;
		string a, b;
		cin >> a >> b;
		if (a.size() > b.size())
			cout << "The shorter string is '" << b << "'" << endl;
		else if (a.size() < b.size())
			cout << "The shorter string is '" << a << "'" << endl;
		else
			cout << "The length of a and b are same." << endl;
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
}