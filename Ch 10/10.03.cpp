/*用accumulate求一个vector<int>中的元素之和*/
#include<iostream>
#include<vector>
#include<numeric>

int main()
{
	std::vector<int> ivec{ 1,2,3,4,5,6,7,8,9};
	auto sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
	std::cout << "The sum of vecotr<int> ivec = " << sum << std::endl;

	return 0;
}