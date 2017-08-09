/* 为了能让StrBlobPtr使用const StrBlob,你觉得应该如何修改?
定义一个名为ConstStrBlobPtr的类，使其能够指向const StrBlob
*/
#pragma once
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

	size_type size() const { return data->size(); }

	bool empty() const { return data->empty(); }

	void push_back(const string &s) { data->push_back(s); }

	void pop_back()
	{
		check(0, "pop_back on empty StrBlob.");
		data->pop_back();
	}

	string &front()
	{
		check(0, "front on empty StrBlob.");
		return data->front();
	}

	string &back()
	{
		check(0, "back on empty StrBlob.");
		return data->back();
	}

	const string &front() const
	{
		check(0, "front on empty StrBlob.");
		return data->front();
	}

	const string &back() const
	{
		check(0, "back on empty StrBlob.");
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

	bool operator != (ConstStrBlobPtr &p) { return p.curr != curr; }

	//string &deref()
	//{
	//	auto p = check(curr, "dereference past end.");
	//	return (*p)[curr];
	//}

	const string &deref() const
	{
		auto p = check(curr, "dereference past end.");
		return (*p)[curr];
	}

	ConstStrBlobPtr &incr()
	{
		check(curr, "increment past end of CosntStrBlobPtr.");
		++curr;
		return *this;
	}

private:
	std::shared_ptr<vector<string>>
		check(std::size_t i, const std::string &msg) const
	{
		auto ret = wptr.lock();
		if (!ret) throw std::runtime_error("unbound ConstStrBlobPtr.");
		if (i >= ret->size()) throw std::out_of_range(msg);
		return ret;
	}

private:
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
};