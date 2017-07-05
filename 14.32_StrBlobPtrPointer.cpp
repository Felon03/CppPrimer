#include "14.32_StrBlobPtrPointer.h"
#include"14.30_StrBlob.h"
#include<iostream>


int main()
{
	StrBlob sb{ "hello", "world" };
	StrBlobPtr iter = sb.begin();
	StrBlobPtrPointer p(&iter);
	//std::cout << &p << std::endl;
	std::cout << p->deref() << std::endl;
}
