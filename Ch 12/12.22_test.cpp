#include"12.22.h"
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	//ifstream ifs("data/test_str.txt");

	const StrBlob blob{ "hello", "world", "nice", "to", "meet", "you!" };
	for (ConstStrBlobPtr p_beg(blob.begin()), p_end(blob.end()); p_beg != p_end; p_beg.incr())
		cout << p_beg.deref() << endl;

	return 0;
}