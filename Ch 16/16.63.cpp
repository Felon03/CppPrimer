/*
    16.63 ����һ��ģ�壬ͳ��һ������ֵ��һ��vector�г��ֵĴ�����
	���Ժ������ֱ𴫵ݸ���һ��double��vector��һ��int��vector
	�Լ�һ��string��vector
	16.64 Ϊ��ģ���д�������汾������vector<const char*>��
*/
#include<iostream>
#include<vector>
#include<string>

template<typename T> int count_elem(const std::vector<T> &vec, const T t);

// ������char*
template<> int count_elem(const std::vector<const char*> &vec,  const char *elem);


int main()
{
	std::vector<int> ivec{ 1,2,3,4,5,6,7,8,9,0,0,0,1,1,2,3,45,6 };
	std::vector<std::string> svec{ "hello","cpp","hellp","cpp","world","freedom" };
	std::vector<double> dvec{ 2.5,2.6,2.7,2.8,2.9,3.0,3.0,3.0,3.1,3.1,3.2,3.2 };
	std::vector<const char*> cvec{ "abc", "bc", "c","abc","c","bc" };

	std::string elem = "cpp";
	std::cout << count_elem(ivec, 0) << "\n";
	std::cout << count_elem(svec, std::string("cpp")) << "\n";
	std::cout << count_elem(svec, elem) << "\n";
	std::cout << count_elem(dvec, 3.0) << "\n";
	std::cout << count_elem(cvec, "abc") << "\n";

	return 0;
}

template<typename T>
int count_elem(const std::vector<T>& vec, const T t)
{
	int counter = 0;
	for (const auto &elem : vec)
		if (elem == t) ++counter;
	return counter;
}

template<>
int count_elem(const std::vector<const char*> &vec, const char *elem)
{
	int counter = 0;
	for (const auto &ch : vec)
		if (elem == ch) ++counter;
	return counter;
}
