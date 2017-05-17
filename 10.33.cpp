/*编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。
	使用istream_iterator读取输入文件。使用ostream_iterator将奇数写入第一个输出文件，每个
	之后都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。
*/
#include<fstream>
#include<iostream>
#include<iterator>
#include<string>
#include<vector>

using namespace std;

int classification(const string &s1, const string &s2, const string &s3)
{
	ifstream ifs(s1);
	if (!ifs) 
	{
		cout << "Fali to open" << s1 << endl;
		return -1;
	}
	istream_iterator<int> in(ifs), eof;
	vector<int> iv;
	copy(in, eof, back_inserter(iv));

	ofstream oddfs(s2), evenfs(s3);
	ostream_iterator<int> odd(oddfs, " "), even(evenfs, "\n");
	for (const auto &x : iv)
	{
		x % 2 == 0 ? even = x : odd = x;
	}
	return 1;
}

int main()
{
	string s1 = "data/int.txt",
		s2 = "data/odd.txt",
		s3 = "data/even.txt";
	auto ret = classification(s1, s2, s3);
	if (ret == 1)
		cout << "Classification success!" << endl;
	else
		cout << "Classification fail..." << endl;
	return 0;
}