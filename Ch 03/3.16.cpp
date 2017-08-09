#include<iostream>
#include<vector>
#include<string>	

using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10, 42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10, "hi" };
	for (auto c : v1)
		cout << c << endl;
	for (auto c : v2)
		cout << c << endl;
	for (auto c : v3)
		cout << c << endl;
	for (auto c : v4)
		cout << c << endl;
	for (auto c : v5)
		cout << c << endl;
	for (auto c : v6)
		cout << c << endl;
	for (auto c : v7)
		cout << c << endl;

	return 0;
}