#pragma once
/* �����Լ���Screen��Window_mgr�� ����clear��Window_mgr�ĳ�Ա����Screen����Ԫ*/
#include<string>
#include<vector>

class Screen;

class Window_mgr
{
public:
	// ������ÿ����Ļ�ı��
	using ScreenIndex = std::vector<Screen>::size_type;
	// ���ձ�Ž�ָ����Screen����Ϊ�հ�
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
	// ���ݶ����Ƿ���const������display����
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return*this; }


private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	// do_display()����������ʾScreen������
	void do_display(std::ostream &os) const { os << contents; }

};

inline void Window_mgr::clear(ScreenIndex index)
{
	// ���������Χ���˳�
	if (index >= screens.size()) return;
	// s��һ��Screen�����ã�ָ����������յ��Ǹ���Ļ
	Screen &s = screens[index];
	// ��ѡ�е��Ǹ�Screen����Ϊ�հ�
	s.contents = std::string(s.height*s.width, ' ');
}

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;			// �����е�λ��
	cursor = row + c;				// �����ڽ�����ƶ���ָ����
	return *this;						// ����ֵ����ʽ���ض���
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;		// ���õ�ǰ�������λ�õ���ֵ
	return *this;
}

inline Screen &Screen::set(pos row, pos col, char c)
{
	contents[row*width + col] = c;		// ���趨λ�õ���ֵ
	return *this;											// ��this������Ϊ��ֵ����
}
