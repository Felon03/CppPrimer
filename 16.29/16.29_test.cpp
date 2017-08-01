/*
    16.29 修改Blob类，使用你自己的shared_pointer代替标准库中的版本 
*/
#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<functional>
#include "DebugDelete.h"
#include "shared_pointer.h"
#include "unique_pointer.h"
#include "Blob.h"

int main()
{
	Blob<std::string> b;
	b.push_back("hello");

	b[0] = "world";
	std::cout << b[0] << std::endl;
	return 0;
}
