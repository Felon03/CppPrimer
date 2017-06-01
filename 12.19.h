/* �������Լ��汾��StrBlobPtr������StrBlob�࣬����ǡ����friend������begin��end��Ա*/
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
	// ��Ӻ�ɾ��Ԫ��
	void push_back(const string &t) { data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	//// ���const���͵�push_back()��pop_back()
	//void push_back(const string &t) const
	//{
	//	data->push_back(t);
	//}
	//void pop_back() const
	//{
	//	check(0, "pop_back on empty StrBlob");
	//	data->pop_back();
	//}
	// Ԫ�ط���
	string &front()
	{
		// ���vectorΪ�գ�check���׳�һ���쳣
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string	 &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	// const �汾��front��back
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
	// ǰ׺����
	StrBlobPtr& incr()
	{
		// ���curr�Ѿ�ָ��������β��ָ�룬�Ͳ��ܵ�����
		check(curr, "increment past end of StrBlobPtr");
		++curr;		// �ƽ���ǰλ��
		return *this;
	}
private:
	std::shared_ptr<vector<string>>
		check(std::size_t i, const std::string &msg) const
	{
		auto ret = wptr.lock();		// �ж�vector�Ƿ񻹴���
		if (!ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
			throw std::out_of_range("msg");
		return ret;		// ���򷵻�ָ��vector��shared_ptr
	}

private:
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;		// �������еĵ�ǰλ��
};