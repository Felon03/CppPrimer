#pragma once
/*给Screen类添加move、set和display函数，并验证是否正确*/
#include<string>

class Screen
{
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' '){}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd),contents(ht*wd, c){}

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r*width + c]; }
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	// 根据对象是否是const重载了display函数
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return*this; }


private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	// do_display()函数负责显示Screen的内容
	void do_display(std::ostream &os) const { os << contents; }

};

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;			// 计算行的位置
	cursor = row + c;				// 在行内将光标移动至指定列
	return *this;						// 以左值的形式返回对象
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;		// 设置当前光标所在位置的新值
	return *this;
}

inline Screen &Screen::set(pos row, pos col, char c)
{
	contents[row*width + col] = c;		// 给设定位置的新值
	return *this;											// 将this对象作为左值返回
}

