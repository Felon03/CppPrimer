#include<iostream>
#include<vector>

using namespace std;

/*��cin����һ�������������Ǵ���һ��vector����*/
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