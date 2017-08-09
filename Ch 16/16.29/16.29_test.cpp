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

	std::vector<int> vi{ 1,2,3,4,5,6,7 };
	Blob<int> blob(vi.begin(), vi.end());
	for (Blob<int>::size_type i = 0; i != blob.size(); ++i)
		std::cout << blob[i] << " ";
	std::cout << std::endl;
	return 0;
}
