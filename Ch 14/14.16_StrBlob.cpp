#include "14.16_StrBlob.h"

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator==(const ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

// 拷贝赋值运算符
StrBlob & StrBlob::operator=(const StrBlob &rhs)
{
	// TODO: 在此处插入 return 语句
	data = make_shared<vector<string>>(*rhs.data);
	return *this;
}

// 移动赋值运算符
StrBlob & StrBlob::operator=(StrBlob &&rhs) noexcept
{
	// TODO: 在此处插入 return 语句
	if (this != &rhs)
	{
		data = std::move(rhs.data);
		rhs.data = nullptr;
	}
	return *this;
}

// 成员函数
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}
