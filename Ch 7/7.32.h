#pragma once
/* 定义自己的Screen和Window_mgr， 其中clear是Window_mgr的成员。是Screen的友元*/
#include<string>
#include<vector>

class Screen;

class Window_mgr
{
public:
	// 窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	// 按照编号将指定的Screen重置为空白
	void clear(ScreenIndex);

private:
	std::vector<Screen> screens{ Screen(14,80, ' ') };
};

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);

public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}

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

inline void Window_mgr::clear(ScreenIndex index)
{
	// 如果超出范围则退出
	if (index >= screens.size()) return;
	// s是一个Screen的引用，指向我们想清空的那个屏幕
	Screen &s = screens[index];
	// 将选中的那个Screen重置为空白
	s.contents = std::string(s.height*s.width, ' ');
}

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
