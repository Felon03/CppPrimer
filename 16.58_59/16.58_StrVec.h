#pragma once
/*
    16.58 为你的StrVec类及Vec类添加emplace_back函数
*/

#include<string>
#include<initializer_list>

class StrVec {
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string>);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	~StrVec();

	StrVec& operator=(std::initializer_list<std::string>);

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const std::string&);

	template<typename... Args> void emplace_back(Args&&...);


private:
	std::pair<std::string*, std::string*>alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	void alloc_n_move(size_t new_cap);
	void range_initialize(const std::string*, const std::string*);
	void chk_n_alloc()
	{
		if (size() == capacity())
			reallocate();
	}

	std::string *elements;
	std::string *first_free;
	std::string *cap;
	std::allocator<std::string> alloc;
};

template<typename ...Args>
inline void StrVec::emplace_back(Args && ... args)
{
	// check if need to reallocate
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}