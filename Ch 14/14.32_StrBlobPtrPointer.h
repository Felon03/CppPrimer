#pragma once
/* ����һ�������京��ָ��StrBlobPtr�����ָ�룬Ϊ����ඨ�����صļ�ͷ�����*/

class StrBlobPtr;

class StrBlobPtrPointer {
public:
	StrBlobPtrPointer() = default;
	StrBlobPtrPointer(StrBlobPtr *p) : pointer(p) {}

	StrBlobPtr& operator*();
	StrBlobPtr* operator->();


private:
	StrBlobPtr* pointer = nullptr;
};

inline StrBlobPtr& StrBlobPtrPointer::operator*()
{
	return *(this->pointer);
}

inline StrBlobPtr* StrBlobPtrPointer::operator->()
{
	return &this->operator*();
}
