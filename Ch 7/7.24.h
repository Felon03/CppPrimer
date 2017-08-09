/*��Screen������������캯��
1. Ĭ�Ϲ��캯��
2. ���ܿ�͸ߵ�ֵ����contents��ʼ���ɸ��������Ŀհ�
3. ���ܿ�͸ߵ�ֵ�Լ�һ���ַ������ַ���Ϊ��ʼ��֮����Ļ��ʾ������
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
