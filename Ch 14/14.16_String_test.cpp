#include"14.16_String.h"
#include<vector>

void foo(String s)
{
	std::cout << s << std::endl;
}

void bar(const String& s)
{
	std::cout << s.c_str() << std::endl;
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
	String s2(std::move(s0));
	String s3 = s1;
	String s4 = (text);
	s2 = s1;

	if (s2 == s1) std::cout << "s2 == s1" << std::endl;

	foo(s1);
	bar(s1);
	foo("tmep");
	bar("temp");
	String s5 = baz();

	std::vector<String> svec;
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(baz());
	svec.push_back("test String");

	for (const auto &s : svec)
		std::cout << s << std::endl;

	std::cout << "Please enter a string: ";
	String s6;
	std::cin >> s6;
	std::cout << "The string you have entered: " << s6 << std::endl;

	return 0;
}