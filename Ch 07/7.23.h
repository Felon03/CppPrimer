/*��д���Լ���Screen��*/
#pragma once
#include<string>

class Screen
{
public:
	using pos = std::string::size_type;		// ʹ�����ͱ����ȼ۵�����һ����������
	Screen() = default;
	// cursor�������ڳ�ʼֵ��ʼ��Ϊ0
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}
	char get() const { return contents[cursor]; }		// ��ȡ��괦���ַ�
	char get(pos r, pos c) const { return contents[r*width + c]; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};
