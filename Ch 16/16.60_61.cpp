/*
    16.60 解释make_shared是如何工作的
	类似emplace_back，make_shared是一个可变参数成员模板
	它用其实参在内存空间中直接构造一个元素并返回一个share_ptr

	16.61 定义你自己版本的make_shared
*/

#include<memory>
#include<iostream>
#include<string>

template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args&&...);

int main()
{
	std::shared_ptr<int> p = make_shared<int>(42);
	std::cout << *p << std::endl;

	std::shared_ptr<std::string> ps = make_shared<std::string>(10, 'c');
	std::cout << *ps << std::endl;
	return 0;
}

template<typename T, typename ...Args>
std::shared_ptr<T> make_shared(Args&&... args)
{
	std::shared_ptr<T> ret(new T(std::forward<Args>(args)...));
	return ret;
}
