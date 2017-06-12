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
	// TODO: �ڴ˴����� return ���
	data = std::make_shared<vector<string>>(*rhs.data);
	return *this;
}
