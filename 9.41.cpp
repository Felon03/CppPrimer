/*��д���򣬴�һ��vector<char>��ʼ��һ��string*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<char> vchar = { 'H', 'E', 'L', 'L', 'O', ' ' , 'W', 'O', 'R', 'L','D','!','!','!' };
	string str(vchar.begin(), vchar.end());
	for (const auto &x : str)
		cout << x;
	cout << endl;
	return 0;
}