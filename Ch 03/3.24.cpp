/*使用迭代器重做3.3.3节最后一个练习*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> digits;
	int x;
	while (cin>>x)
	{
		digits.push_back(x);
	}
	for (auto it = digits.begin(); it != digits.end() - 1; ++it)
	{
		cout << *it + *it + 1 << endl;
	}
	auto end = digits.end() - 1, begin = digits.begin();
	while (begin<=end)
	{
		cout << *begin + *end << endl;
		end--, begin++;
	}
	//for (auto iter = digits.begin(); iter != digits.end(); ++iter)
	//{
	//	if (iter<=end)
	//	{
	//		cout << *iter + *end << endl;
	//		end--;
	//	}
	//}

	return 0;
}