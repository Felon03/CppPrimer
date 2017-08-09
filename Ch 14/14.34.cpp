/* 定义一个函数对象类，令其执行if-then-else的操作*/
#include<iostream>

struct PrintMax
{
	int operator()(bool check, int val1, int val2) const {
		return check ? val1 : val2;
	}
};

int main()
{
	PrintMax pm;
	bool b = true;
	bool b1 = false;
	int v1 = 1, v2 = -1;
	
	// condition: true
	auto ans = pm(b, v1, v2);
	std::cout << ans << std::endl;

	// condition: false
	auto ans1 = pm(b1, v1, v2);
	std::cout << ans1 << std::endl;
	return 0;
}