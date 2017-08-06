/*
	16.51 ���ñ��ڵ�ÿ��foo��ȷ��sizeof...(Args)��sizeof...(rest)�ֱ𷵻�ʲô
	16.52 ��дһ��������֤16.51�Ĵ�
*/

#include<iostream>
#include<string>

template<typename T, typename... Args>
void foo(const T &t, const Args& ...rest)
{
	std::cout << "sizeof...(Args)" << " " 
		<< sizeof...(Args) << std::endl
		<< "sizeof...(rest)" << " "
		<< sizeof...(rest) << std::endl;
}

// main func
int main()
{
	int i = 0;
	double d = 3.14;
	std::string s = "how now brown cow";
	foo(i, s, 42, d);    // ��������������
	foo(s, 42, "hi");    // ��������������
	foo(d, s);    // ������һ������
	foo("hi");    // �հ�

	return 0;
}