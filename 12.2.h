/*编写你自己的SrtBlob类，包含const版本的front和back*/
#pragma once
#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<exception>

using std::vector;
using std::string;

class StrBlob {
public:
	using size_type = vector<string>::size_type;
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