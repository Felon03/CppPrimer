/*编写你自己的Screen类*/
#pragma once
#include<string>

class Screen
{
public:
	using pos = std::string::size_type;		// 使用类型别名等价地声明一个类型名字
	Screen() = default;
	// cursor被其类内初始值初始化为0
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}
	char get() const { return contents[cursor]; }		// 读取光标处的字符
	char get(pos r, pos c) const { return contents[r*width + c]; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
