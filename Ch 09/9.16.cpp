/*重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素*/
#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	list<int> list{ 1,2,3,4 };
	vector<int> vec1{ 1,2,3,4,5 };
	vector<int> vec2{ 1,2,3,4 };

	cout << boolalpha << (vector<int>(list.begin(), list.end()) == vec1) << endl;

	cout << boolalpha << (vector<int>(list.begin(), list.end()) == vec2) << endl;

	return 0;
}