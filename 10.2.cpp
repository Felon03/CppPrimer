/*������һ�⣬����ȡstring���д���list��*/
#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	std::list<std::string> strList{ "a", "b", "a","c","a","d","e","f","z","z","z" };
	auto val = "z";
	auto result = count(strList.cbegin(), strList.cend(), val);
	std::cout <<"'"<< val <<"'"  << " appears " << result << " times." << std::endl;

	return 0;
}