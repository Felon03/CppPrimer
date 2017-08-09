/* 使用标准库函数对象判断给定的int值是否能被int容器中的所有元素整除*/
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

int main()
{
	using std::placeholders::_1;
	std::vector<int>  ivec{ 2, 4, 6, 8 };
	std::modulus<int> mod;
	int input;
	std::cin >> input;
	auto divisible = std::all_of(ivec.begin(), ivec.end(), [&](int i) {return 0 == mod(input, i); });
	//for (int k = 2; k != 26; k += 2)
	//{
	//	auto cnt = std::count_if(ivec.begin(), ivec.end(), [&](int i) {return 0 == mod(k, i); });
	//	std::cout << k << cnt << std::endl;
	//	std::cout << (cnt == ivec.size() ? "yes" : "no") << std::endl;
	//}
	auto cnt = std::count_if(ivec.begin(), ivec.end(), [&](int i) {return 0 == mod(input, i); });
	std::cout << (cnt == ivec.size() ? "yes" : "no") << std::endl;
	std::cout << (divisible ? "yes" : "no") << std::endl;

	// test
	// 2 no cnt = 1
	// 4 no cnt = 2
	// 6 no cnt = 2
	// 8 no cnt = 3
	// 10 no cnt = 1
	// 12 no cnt = 3
	// 14 no cnt = 1
	// 16 no cnt = 3
	// 18 no cnt = 2
	// 20 no cnt = 2
	// 22 no cnt = 1
	// 24 yes cnt = 4

	//auto data = { 2,  4, 6, 8, 10 };
	//std::cin >> input;
	////std::modulus<int> mod;
	//auto predicator = [&](int i) { return 0 == mod(input, i); };
	//auto is_divisible = std::any_of(data.begin(), data.end(), predicator);
	//std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;

	return 0;
}