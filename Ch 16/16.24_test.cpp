#include<iostream>
#include<vector>
#include<list>
#include<memory>
#include"16.24_Blob.h"

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	Blob<int> blob(v.begin(), v.end());
	return 0;
}