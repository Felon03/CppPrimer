#include "16.04_find.h"
#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<int> ivec{ 0,1,2,3,4,5,6,7,8,9,10 };
	vector<string> svec{ "a","b","c","d","ab","bc","cd","abc","bcd" };
	auto iter = my_find(ivec.begin(), ivec.end(), 100);
	if (iter != ivec.end())
		cout << *iter << endl;
	else
		cout << "Element not found!" << endl;

	auto siter = my_find(svec.begin(), svec.end(), "bc");
	if (siter != svec.end())
		cout << *siter << endl;
	else
		cout << "Element not found!" << endl;
}