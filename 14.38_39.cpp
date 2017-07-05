#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
#include<map>

// 14.38
// ��дһ����������ĳ��������string�ĳ����Ƿ���һ����ֵ��ȡ�
// ʹ�øĶ����д����ͳ�Ʋ������������ļ��г���Ϊ1�ĵ����ж��ٸ�
// ����Ϊ2�ĵ����ж��ٸ���......������Ϊ10�ĵ������ж��ٸ�

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
	// �޸���һ��������䱨�泤����1��9֮��ĵ����ж��ٸ���������10���ϵĵ������ж��ٸ�
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