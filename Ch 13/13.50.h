#pragma once
/* 在String类的移动操作中添加打印语句，并重新运行13.48中的程序，观察什么时候避免拷贝*/
#include<memory>

class String {
public:
	String() : String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	// 移动构造函数
	String(String&&) noexcept;
	// 移动赋值运算符
	String& operator=(String&&) noexcept;
	~String();

	const char *c_str() const { return elements; }
	size_t size() const { return end - elements; }
	size_t length() const { return end - elements - 1; }

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void range_initialize(const char*, const char*);
	void free();

private:
	char* elements;
	char* end;
	std::allocator<char> alloc;
};