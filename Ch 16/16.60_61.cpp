/*
    16.60 ����make_shared����ι�����
	����emplace_back��make_shared��һ���ɱ������Աģ��
	������ʵ�����ڴ�ռ���ֱ�ӹ���һ��Ԫ�ز�����һ��share_ptr

	16.61 �������Լ��汾��make_shared
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
