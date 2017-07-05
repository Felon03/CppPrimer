/* 使用前一个练习定义的类读取标准输入，将每一行保存为一vector的一个元素*/
#include<iostream>
#include<string>
#include<vector>

//class ReadString {
//public:
//	ReadString(std::istream &in = std::cin) : is(in) {}
//	std::vector<std::string> operator() () const
//	{
//		std::vector<std::string> vec;
//		std::string str = "";
//		while (std::getline(is, str))
//		{
//			vec.push_back(str);
//		}
//		return vec;
//	}
//
//private:
//	std::istream &is;
//};

class ReadString {
public:
	ReadString(std::istream &in = std::cin) : is(in) {}
	std::string operator() () const
	{
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}

private:
	std::istream &is;
};

int main()
{
	std::vector<std::string> svec;
	ReadString read;
	for (std::string str;!(str = read()).empty();)
		svec.push_back(str);
	for (const auto &x : svec)
		std::cout << x << " ";
	std::cout << std::endl;

	return 0;
}