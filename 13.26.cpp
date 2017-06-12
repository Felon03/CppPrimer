#include "13.26.h"

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
	return ConstStrBlobPtr(*this, data->size());
}

StrBlob & StrBlob::operator=(const StrBlob & rhs)
{
	// TODO: 在此处插入 return 语句
	data = std::make_shared<vector<string>>(*rhs.data);
	return *this;
}
