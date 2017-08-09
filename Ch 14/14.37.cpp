/* 编写一个类令其检查两个值是否相等。使用改对象及标准库算法编写程序，
	令其替换某个序列具有给定值的所有实例
*/
#include<iostream>
#include<string>
#include<algorithm>

class IsEqual {
public:
	IsEqual(char ch) : c(ch) {}

	bool operator() (char rhs) const
	{
		return c == rhs;
	}

private:
	char c;
};

int main()
{
	std::string s{ "hello world nice to meet you" };
	std::replace_if(s.begin(), s.end(), IsEqual(' '), ',');

	for (const auto &x : s)
		std::cout << x;
	std::cout << std::endl;
}