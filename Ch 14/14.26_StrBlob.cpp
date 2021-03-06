#include"14.26_StrBlob.h"
#include<algorithm>

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	// std::lexicographical_compare()用于按字典序比较两个序列
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
		rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
}

bool operator==(const ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
}

StrBlob & StrBlob::operator=(const StrBlob &rhs)
{
	// TODO: 在此处插入 return 语句
	data = make_shared<vector<string>>(*rhs.data);
	return *this;
}

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
