/*��дһ�γ��������������ʼ��һ��vector����*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int int_arr[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> arr(begin(int_arr), end(int_arr));

	for (auto x : arr)
		cout << x << " ";
	cout << endl;

	return 0;
}