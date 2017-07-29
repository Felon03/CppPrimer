/* 
    16.19 
	编写函数，接受一个容器的引用，打印容器中的元素。
    使用容器的size_type和size成员来控制打印元素的循环。

	16.20
	重写16.19，使用begin和end返回迭代器来控制循环
*/
#include<iostream>
#include<vector>
#include<list>
#include<string>

template<typename T> void print_elements(const T &t);

template<typename T> void print_elements1(const T &t);


int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
	print_elements(vec);
	std::cout << std::endl;

	std::list<std::string> lst{ "hello", "world", "cpp", "freedom" };
	print_elements1(lst);
	std::cout << std::endl;
	return 0;
}

template<typename T>
void print_elements(const T & t)
{
	using  size_type = typename T::size_type ;
	auto iter = t.begin();
	for (size_type i = 0; i != t.size(); ++i)
	{
		std::cout << *iter++ << " ";
	}
	//std::cout << std::endl;
}

template<typename T>
void print_elements1(const T & t)
{
	for (auto iter = t.begin(); iter != t.end(); ++iter)
		std::cout << *iter << " ";
}
