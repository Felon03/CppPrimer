/*我们曾用do while循环来编写用户交换的循环。
	用do while重写本程序，解释你更倾向于哪一个版本
*/
// do while 更好，因为符合处理逻辑
#include"12.27.h"
#include<iostream>

using namespace std;

void runQuires(ifstream &file)
{
	TextQuery tq(file);
	do
	{
		cout << "Enter word to look for or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	} while (true);
}

int main()
{
	ifstream filename("data/story.txt");
	runQuires(filename);
	return 0;
}
