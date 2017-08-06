/*
    16.53 ��д���Լ��汾��print����������ӡһ������������5��ʵ������������
	Ҫ��ӡ��ʵ�ζ�Ӧ�в�ͬ�����͡�
*/
#include<iostream>
#include<string>
#include<vector>

//template<typename T>
//std::ostream &print(std::ostream &os, const T &t);

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest);

template<typename T>
std::ostream &print(std::ostream &os, const T &t);

int main()
{
	int i = 42;
	double d = 3.14;
	std::string s = "hello";
	std::vector<int> ivec{ 1,2,3,4,5 };
	char *a = "world";

	print(std::cout,i);
	std::cout << "\n";
	print(std::cout, i, d);
	std::cout << "\n";
	print(std::cout, i, d, s, ivec[1], a);
	std::cout << "\n";

	return 0;
}

//template<typename T>
//std::ostream & print(std::ostream & os, const T & t)
//{
//	// TODO: �ڴ˴����� return ���
//	return os << t;
//}

template<typename T, typename ...Args>
std::ostream & print(std::ostream & os, const T & t, const Args & ...rest)
{
	// TODO: �ڴ˴����� return ���
	os << t << " ";
	return print(os, rest...);
}

template<typename T>
std::ostream & print(std::ostream & os, const T & t)
{
	// TODO: �ڴ˴����� return ���
	return os << t;
}
