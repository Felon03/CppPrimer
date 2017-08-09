#pragma once
/* 为之前定义的String类中的拷贝构造函数和拷贝赋值运算符添加一条语句
	在每次函数执行时打印一条信息。
*/
#include<memory>

class String {
public:
	String() : String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

	const char* c_str() const { return elements; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const  char*);
	void range_initialize(const char*, const char*);
	void free();


private:
	char* elements;
	char* end;
	std::allocator<char> alloc;
};