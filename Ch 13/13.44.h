#pragma once
/* ��д��׼��string��ļ򻯰汾������ΪString�������Ӧ��������һ��Ĭ�Ϲ��캯��
	��һ������C����ַ���ָ�뺯�������Ĺ��캯����ʹ��allocatorΪString����������ڴ�
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