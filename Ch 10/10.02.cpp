/*重做上一题，但读取string序列存入list中*/
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