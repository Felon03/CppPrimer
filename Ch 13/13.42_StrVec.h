#pragma once
#include<memory>
#include<string>
#include<initializer_list>

class StrVec {
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	// ��ӽ��ܲ���Ϊinitializer_list<string>�Ĺ��캯��
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	std::string &at(size_t pos) { return *(elements + pos); }
	const std::string &at(size_t pos) const { return *(elements + pos); }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const std::string&);

private:
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}
	void free();
	void reallocate();
	void alloc_n_move(size_t new_cap);
	void range_initialize(const std::string*, const std::string*);

private:
	std::string *elements;               // ָ��������Ԫ�ز��ͷ��ڴ�
	std::string *first_free;               // ָ�������һ������Ԫ�ص�ָ��
	std::string *cap;                           // ָ������β��λ�õ�ָ��
	static std::allocator<std::string> alloc;       // ����Ԫ��
};