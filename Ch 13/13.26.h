#pragma once
/* 编写类值版本的StrBlob*/
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<exception>

using std::vector;
using std::string;

class ConstStrBlobPtr;

class StrBlob {
public:
	using size_type = vector<string>::size_type;
	friend class ConstStrBlobPtr;

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il) 
		: data(std::make_shared<vector<string>>(il)) {}

	// 拷贝构造函数
	StrBlob(const StrBlob &rhs) 
		: data(std::make_shared<vector<string>>(*rhs.data)) {}

	// 拷贝赋值运算符
	StrBlob& operator=(const StrBlob &rhs);

	size_type size() const { return data->size(); }

	bool empty() const { return data->empty(); }

	void push_back(const string &s) { data->push_back(s); }

	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	string &front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	string &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const string &front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const string &back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

private:
	void check(size_type i, const string &msg) const
	{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}

private:
	std::shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) 
		: wptr(a.data), curr(sz) {}

	bool operator != (ConstStrBlobPtr &rhs) { return rhs.curr != curr; }

	const string &deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	ConstStrBlobPtr &incr()
	{
		check(curr, "increment past end of ConstStrBlobPtr");
		++curr;
		return *this;
	}

private:
	std::shared_ptr<vector<string>>
		check(std::size_t i, const string &msg) const
	{
		auto ret = wptr.lock();		// 检查vector是否还存在
		// 如果不存在，返回runtime_error
		if (!ret) throw std::runtime_error("unbound ConstStrBlobPtr");
		if (i >= ret->size()) throw std::out_of_range(msg);
		return ret;
	}

private:
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
};