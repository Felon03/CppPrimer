#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<map>

// 14.38
// 编写一个类令其检查某个给定的string的长度是否与一个阈值相等。
// 使用改对象编写程序，统计并报告在输入文件中长度为1的单词有多少个
// 长度为2的单词有多少个、......、长度为10的单词又有多少个

class CalLength {
public:
	CalLength(size_t n) : size(n) {}
	bool operator() (const std::string str) const
	{
		return size == str.length();
	}

private:
	size_t size;
};

int main()
{
	std::map<int, int> map;
	std::vector<std::string> vec;
	std::string file = "data/story.txt";
	std::ifstream in(file);
	if (in)
	{
		std::string buf;
		while (in >> buf)
		{
			vec.push_back(buf);
			map[buf.length()]++;
		}
		for (size_t i = 1; i != 11; ++i)
		{
			CalLength cal(i);
			int cnt = 0;
			for (const auto &x : vec)
				if (cal(x)) ++cnt;
			std::cout << "Lenght of " << i << std::setw(4) << std::right << cnt << std::endl;
			cnt = 0;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "open file failed" << std::endl;
	}

	// 14.39
	// 修改上一题程序，令其报告长度在1至9之间的单词有多少个，长度在10以上的单词又有多少个
	int sum1_9 = 0;
	int sum_10 = 0;
	for (size_t i = 1; i != 10; i++)
	{
		CalLength cal(i);
		for (const auto &x : vec)
			if (cal(x)) ++sum1_9;
	}
	sum_10 = vec.size() - sum1_9;

	std::cout << "length of 1-9: " << sum1_9 <<
		std::endl << "length larger than 10: " << sum_10 << std::endl;

	return 0;
}