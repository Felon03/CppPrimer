/* 定义你自己版本的StrBlobPtr，更新StrBlob类，加入恰当的friend声明及begin和end成员*/
#pragma once
#include<vector>
#include<string>
#include<memory>
#include<exception>
#include<initializer_list>

using std::vector;
using std::string;

class StrBlobPtr;

class StrBlob {
public:
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob() : data(std::make_shared<vector<string>>()) {}
	StrBlob(std::initializer_list<string> il)
		: data(std::make_shared<vector<string>>(il)) {}
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// 添加和删除元素
	void push_back(const string &t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	//// 添加const类型的push_back()和pop_back()
	//void push_back(const string &t) const
	//{
	//	data->push_back(t);
	//}
	//void pop_back() const
	//{
	//	check(0, "pop_back on empty StrBlob");
	//	data->pop_back();
	//}
	// 元素访问
	string &front()
	{
		// 如果vector为空，check会抛出一个异常
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string	 &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	// const 版本的front和back
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

class StrBlobPtr {
public:
	friend bool is_equal(const StrBlobPtr&, const StrBlobPtr&);
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	//bool operator != (const StrBlobPtr &p) { return p.curr != curr; }
	string& deref() const
	{
		auto p = check(curr, "dereference past end.");
		return (*p)[curr];
	}
	// 前缀递增
	StrBlobPtr& incr()
	{
		// 如果curr已经指向容器的尾后指针，就不能递增它
		check(curr, "increment past end of StrBlobPtr");
		++curr;		// 推进当前位置
		return *this;
	}
private:
	std::shared_ptr<vector<string>>
		check(std::size_t i, const std::string &msg) const
	{
		auto ret = wptr.lock();		// 判断vector是否还存在
		if (!ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
			throw std::out_of_range("msg");
		return ret;		// 否则返回指向vector的shared_ptr
	}

private:
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;		// 在数组中的当前位置
};