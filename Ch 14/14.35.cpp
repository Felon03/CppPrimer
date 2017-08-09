/* 编写一个类似与PrintString的类，令其充istream中读取一行输入，
	然后返回一个表示我们所读内容的string。如果读取失败，返回空string
*/
#include<string>
#include<iostream>

class ReadString {
public:
	ReadString(std::istream &in = std::cin) : is(in) {}
	std::string operator() () const
	{
		std::string str = "";
		std::getline(is, str);
		return is ? str : std::string();
	}

private:
	std::istream &is;    // 用于读取的流
};

int main()
{
	ReadString read;
	std::string mystr = read();
	std::cout << mystr << std::endl;

	return 0;
}