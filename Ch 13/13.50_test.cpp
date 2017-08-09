#include"13.50.h"
#include<vector>
#include<iostream>

using namespace std;

void foo(String x)
{
	cout << x.c_str() << endl;
}

void bar(const String &x)
{
	cout << x.c_str() << endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	String s4(text);
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();		// String(String&&) 避免拷贝

	vector<String> S_vec;
	S_vec.reserve(8);
	S_vec.push_back(s0);
	S_vec.push_back(s1);
	S_vec.push_back(s2);
	S_vec.push_back(s3);
	S_vec.push_back(s4);
	S_vec.push_back(s5);
	S_vec.push_back(baz());			// String(String&&) 避免拷贝
	S_vec.push_back("good job");		// String(String&&) 避免拷贝

	for (const auto &s : S_vec)
		cout << s.c_str() << endl;

	return 0;
}