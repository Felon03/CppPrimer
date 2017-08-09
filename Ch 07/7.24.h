/*给Screen类添加三个构造函数
1. 默认构造函数
2. 接受宽和高的值，将contents初始化成给定数量的空白
3. 接受宽和高的值以及一个字符，该字符作为初始化之后屏幕显示的内容
*/
#pragma once
#include<string>

class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;		//1
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}		//2
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}		//3

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r*width + c]; }


private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
