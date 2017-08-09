/*编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iterator>

using namespace std;

int main()
{
	ifstream ifs("C:\\Users\\Freed\\Desktop\\contacts.txt");
	if (!ifs)
		cout << "Fail to open file!" << endl;
	istream_iterator<string> in(ifs), eof;
	vector<string> vec;
	copy(in, eof, back_inserter(vec));

	ostream_iterator<string> out(cout, "\n");
	for (auto e : vec)
		*out++ = e;
	//copy(vec.cbegin(), vec.cend(),
	//	ostream_iterator<string>(cout, "\n"));

	return 0;
}