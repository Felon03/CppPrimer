/*
    16.53 编写你自己版本的print函数，并打印一个、两个、及5个实参来测试它，
	要打印的实参都应有不同的类型。
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
//	// TODO: 在此处插入 return 语句
//	return os << t;
//}

template<typename T, typename ...Args>
std::ostream & print(std::ostream & os, const T & t, const Args & ...rest)
{
	// TODO: 在此处插入 return 语句
	os << t << " ";
	return print(os, rest...);
}

template<typename T>
std::ostream & print(std::ostream & os, const T & t)
{
	// TODO: 在此处插入 return 语句
	return os << t;
}
