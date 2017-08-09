#pragma once
/* 定义一个类令其含有指向StrBlobPtr对象的指针，为这个类定义重载的箭头运算符*/

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
