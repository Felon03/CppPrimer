#include "12.22.h"

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}
