/*编写一段程序，利用指针将数组中的元素置为0*/
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