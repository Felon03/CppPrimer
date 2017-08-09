#include<iostream>
#include<string>	
using namespace std;

int main()
{
	string s;
	string result;
	while (cin>>s)
	{
		// 将输入的字符串合并
		//result += s;
		// 将输入的字符串合并，每个输入之间由空格分隔
		result += s + " ";
	}
	cout << "The content of string: " << result << endl;

	return 0;
}