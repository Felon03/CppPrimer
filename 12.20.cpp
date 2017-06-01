/*编写程序，逐行读入一个输入文件，将内容存入一个StrBlob中，
	用一个StrBlobPtr打印输出StrBlob中的每个元素
*/
#include"12.19.h"
#include<iostream>
#include<fstream>

using namespace std;

bool is_equal(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	if (lhs.wptr.lock() == rhs.wptr.lock())
		return !(lhs.curr == rhs.curr);
	return true;
}

int main()
{
	ifstream ifs("data/test_str.txt");
	StrBlob blob;
	string word;
	while (getline(ifs, word))
		blob.push_back(word);
	//for(string str; getline(ifs, str);) 
	//	blob.push_back(str)
	for (StrBlobPtr p_beg(blob.begin()), p_end(blob.end()); is_equal(p_beg, p_end); p_beg.incr())
		cout << p_beg.deref() << endl;

	return 0;
}