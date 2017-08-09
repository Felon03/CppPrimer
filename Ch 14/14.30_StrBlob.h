#pragma once
/* 为StrBlobPtr类和ConstStrBlobPtr类添加解引用和箭头运算符*/
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<exception>

using std::vector;
using std::string;
using std::make_shared;
using std::shared_ptr;
using std::initializer_list;

class StrBlobPtr;
class ConstStrBlobPtr;

//=================================
//
// StrBlob - custom vector<string>
//
//=================================

class StrBlob {
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	// 相等和不相等运算符
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	// 关系运算符
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator <= (const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);

public:
	StrBlob() : data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string> il)
		: data(make_shared<vector<string>>(il)) {}

	// 重载下标运算符
	string& operator[](size_t n);
	const string& operator[](size_t n) const;

	StrBlob(const StrBlob &sb) : data(make_shared<vector<string>>(*sb.data)) {}
	StrBlob& operator=(const StrBlob&);

	StrBlob(StrBlob &&rhs) noexcept : data(std::move(rhs.data)) {}
	StrBlob& operator=(StrBlob&&) noexcept;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string &t) { data->push_back(t); }
	void push_back(string &&t) { data->push_back(std::move(t)); }

	void pop_back();
	string &front();
	string &back();
	const string &front() const;
	const string &back() const;
private:
	void check(size_type, const string&) const;

private:
	shared_ptr<vector<string>> data;
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

inline void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

inline string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline const string &StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline const string &StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size()) throw std::out_of_range(msg);
}

inline string& StrBlob::operator[](size_t n)
{
	check(n, "out of range");
	return data->at(n);
}

inline const string& StrBlob::operator[](size_t n) const
{
	check(n, "out of range");
	return data->at(n);
}

//=================================================
//
// StrBlobPtr - custom iterator of StrBlob
//
//=================================================

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}

	string& operator*() const;
	string* operator->() const;

	string &deref() const;
	StrBlobPtr &incr();

	// 重载下标运算符
	string& operator[](size_t n);
	const string& operator[](size_t n) const;
	// 重载递增和递减运算符(14.27)
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr& operator++(int);
	StrBlobPtr& operator--(int);
	// 重载加法和减法运算符
	StrBlobPtr& operator+=(size_t);
	StrBlobPtr& operator-=(size_t);
	StrBlobPtr& operator+(size_t) const;
	StrBlobPtr& operator-(size_t) const;

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;

private:
	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

inline string &StrBlobPtr::deref() const
{
	auto p = check(curr, "dereferenece past end");
	return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
inline string & StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline string * StrBlobPtr::operator->() const
{
	return &this->operator*();
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i,
	const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size()) throw std::out_of_range(msg);
	return ret;
}

inline string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}

inline const string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}

inline StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr& StrBlobPtr::operator++(int)
{
	StrBlobPtr ret = *this;    // 记录当前值
	++*this;                                 // 向前移动一个元素，前置++需要检查递增的有效性
	return ret;                           // 返回之前记录的状态
}

inline StrBlobPtr& StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

inline StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

inline StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past end of StrBlobPtr");
	return *this;
}

inline StrBlobPtr& StrBlobPtr::operator+(size_t n) const
{
	StrBlobPtr ret = *this;
	ret += n;
	return ret;
}

inline StrBlobPtr& StrBlobPtr::operator-(size_t n) const
{
	StrBlobPtr ret = *this;
	ret -= n;
	return ret;
}

//==============================================
//
// ConstStrBlobPtr - custom const_iterator of StrBlob
//
//==============================================

class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr&, ConstStrBlobPtr&);
	friend bool operator!=(const ConstStrBlobPtr&, ConstStrBlobPtr&);
	friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator <= (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}

	const string& operator*() const;
	const string* operator->() const;

	const string &deref() const;
	ConstStrBlobPtr &incr();

	// 重载下标运算符
	// ConstStrBlobPtr只有const版本的下标运算符
	const string& operator[](size_t n) const;
	ConstStrBlobPtr& operator++();
	ConstStrBlobPtr& operator--();
	ConstStrBlobPtr& operator++(int);
	ConstStrBlobPtr& operator--(int);
	ConstStrBlobPtr& operator+=(size_t);
	ConstStrBlobPtr& operator-=(size_t);
	ConstStrBlobPtr& operator+(size_t) const;
	ConstStrBlobPtr& operator-(size_t) const;

private:
	shared_ptr<vector<string>> check(size_t, const string &msg) const;

private:
	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

bool operator==(const ConstStrBlobPtr&, ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, ConstStrBlobPtr&);
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator <= (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

inline const string &ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline const string& ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline const string* ConstStrBlobPtr::operator->() const
{
	return &this->operator*();
}

inline shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size()) throw std::out_of_range(msg);
	return ret;
}

inline const string & ConstStrBlobPtr::operator[](size_t n) const
{
	// TODO: 在此处插入 return 语句
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
	check(curr, "increment past end of ConstStrBlob");
	++curr;
	return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator++(int)
{
	ConstStrBlobPtr ret = *this;
	++*this;
	return ret;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator--(int)
{
	ConstStrBlobPtr ret = *this;
	--*this;
	return ret;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of ConstStrBlobPtr");
	return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator+(size_t n) const
{
	ConstStrBlobPtr ret = *this;
	ret += n;
	return ret;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator-(size_t n) const
{
	ConstStrBlobPtr ret = *this;
	ret -= n;
	return ret;
}