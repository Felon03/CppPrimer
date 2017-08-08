/*
    16.65 ��16.63�������Ƕ������������ص�debug_rep�汾��
	һ������const char*��������һ������char*������
	��������������дΪ�������汾��	
*/

#include<iostream>
#include<sstream>
#include<vector>
#include<string>

//template<typename T> std::string debug_rep(const T &t);
// ����
template<typename T> std::string debug_rep(T *p);
// ������
template<> std::string debug_rep(const char *p);
template<> std::string debug_rep(char *p);

int main()
{
	//char p[] = "hello world";
	char *p = "hello cpp";
	const char *cp = p;

	std::cout << debug_rep(p) << "\n";
	std::cout << debug_rep(cp) << "\n";

	return 0;
}

template<typename T> std::string debug_rep(T *p)
{
	std::cout << "debug_rep(T)" << std::endl;
	std::ostringstream ret;
	ret << p;
	return ret.str();
}

// ����
template<> std::string debug_rep(const char *p)
{
	std::cout << "debug_rep(const char*)" << std::endl;
	std::string ret(p);
	return ret;
}

template<> std::string debug_rep(char *p)
{
	std::cout << "debug_rep(char*)" << std::endl;
	std::string ret(p);
	return ret;
}