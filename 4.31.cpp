#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec(10, 0);
	vector<int>::size_type cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
		ivec[ix] = cnt;
	for (auto x : ivec)
		cout << x << " ";
	cout << endl;

	cnt = ivec.size();
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, --cnt)
		ivec[ix] = cnt;
	for (auto x : ivec)
		cout << x << " ";
	cout << endl;

	return 0;
}