/*��дһ�γ�������ָ�뽲�����е�Ԫ����Ϊ0*/
#include<iostream>

using namespace std;

int main()
{
	constexpr size_t sz = 5;
	int a[sz];
	int *beg = begin(a), *last = end(a);
	while (beg != last)
	{
		*beg = 0;
		beg++;
	}

	for (auto x : a)
		cout << x << " ";
	cout << endl;

	return 0;
}