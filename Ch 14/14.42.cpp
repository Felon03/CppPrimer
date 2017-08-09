/* 使用标准库函数对象及适配器定义一条表达式，令其
	(a) 统计大于1024的值有多少个
	(b) 找到第一个不等于pooh的字符串
	(c) 将所有的值乘2
*/
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>

int main()
{
	std::vector<int> ivec{ 2,4,8,16,32,64,128,256,512,1024,2048,4096 };
	std::greater<int> greater;
	int count = 0;
	for (const auto &x : ivec)
	{
		if (greater(x, 1024))
			++count;
	}
	std::cout << count << std::endl;

	// 使用bind和placeholder  Cpp Primer 5th Edition@354(Chs Version)
	using std::placeholders::_1;
	count = std::count_if(ivec.begin(), ivec.end(), std::bind(greater, _1, 1024));
	std::cout << "using bind: ";
	std::cout << count << std::endl;
	// 使用lambda表达式
	count = std::count_if(ivec.begin(), ivec.end(), [greater](const int i) {return greater(i, 1024); });
	std::cout << "using lambda expression: ";
	std::cout << count << std::endl;

	std::vector<std::string> svec{ "pooh", "pooh", "freedomly","pooh", "hello" };
	std::not_equal_to<std::string> notequal;
	for (const auto &x : svec)
	{
		if (notequal("pooh", x))
		{
			std::cout << x << std::endl;
			break;
		}
	}
	auto word = std::find_if(svec.begin(), svec.end(), std::bind(notequal, _1, "pooh"));
	std::cout << "using bind: " << *word << std::endl;

	word = std::find_if(svec.begin(), svec.end(), [notequal](const std::string &s) {return notequal(s, "pooh"); });
	std::cout << "using lambda expression: " << *word << std::endl;

	std::vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };
	std::multiplies<int> multi;
	for (auto &x : vec)
	{
		x = multi(x, 2);
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(multi, _1, 2));
	std::cout << "using bind: ";
	for (const auto &x : vec) 
		std::cout << x << " ";
	std::cout << std::endl;

	std::transform(vec.begin(), vec.end(), vec.begin(), [multi](const int &i) {return multi(i, 2); });
	std::cout << "using lambda expression: ";
	for (const auto &x : vec)
		std::cout << x << " ";
	std::cout << std::endl;


	return 0;
}