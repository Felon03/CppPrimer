/*编写程序，从标准输入读取string序列，存入一个deque中。
编写一个循环，用迭代器打印deque中的元素
*/
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
	string word;
	deque<string> deqStr;

	while (cin >> word)
		deqStr.push_back(word);

	for (auto iter = deqStr.cbegin(); iter != deqStr.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}