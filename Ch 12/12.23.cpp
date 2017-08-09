/*编写程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。
	重写这个程序，来凝结两个标准库string对象。
*/
#include<iostream>
#include<string>
#include<cstring>

int main()
{
	const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	// strcat_s() 连接两个字符串
	// 第一个参数是目标字符串指针，第二个参数是字符串长度，第三个是源字符串指针
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	std::cout << r << std::endl;

	const std::string s1 = "hello ";
	const std::string s2 = "world";
	auto s3 = s1 + s2;
	unsigned size = s3.size() + 1;
	char *rs = new char[size]();
	// strcpy_s()将源字符串拷贝给目标字符串
	// 第一个参数是目标字符串指针，第二个参数是字符串长度，第三个是源字符串指针
	strcpy_s(rs, size, s3.c_str());
	std::cout << rs << std::endl;
	delete[] r, rs;
	return 0;
}