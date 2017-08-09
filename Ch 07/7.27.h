#pragma once
/*��Screen�����move��set��display����������֤�Ƿ���ȷ*/
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

