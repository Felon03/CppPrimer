#include<iostream>
#include<vector>

using namespace std;

/*用cin读入一组整数并把它们存入一个vector对象*/
int main()
{
	vector<int> integer_array;
	int x;
	while (cin>>x)
	{
		integer_array.push_back(x);
	}
	cout << "[";
	for (auto c : integer_array)
		if (c == integer_array.back())
			cout << c;
		else
			cout << c << ",";
	cout << "] "<<endl;

	return 0;
}