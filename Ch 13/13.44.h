#pragma once
/* 编写标准库string类的简化版本，命名为String。你的类应该至少有一个默认构造函数
	和一个接受C风格字符串指针函数参数的构造函数。使用allocator为String类分配所需内存
*/

#include<memory>

class String {
public:
	String() : String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	const char* c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

private:
	std::pair<char*, char*>alloc_n_copy(const char*, const char*);
	void range_initialize(const char*, const char*);
	void free();


private:
	char* elements;
	char* end;
	std::allocator<char> alloc;
};