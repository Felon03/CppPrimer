/*利用迭代器改写3.3.3节划分分数段的程序*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<unsigned> scores(11, 0);	// 11个分数段，全部初始化为0
	unsigned grade;
	auto begin = scores.begin();
	while (cin>>grade)
	{
		if (grade<=100)
			*(begin + grade / 10) += 1;
	}
	for (auto it = scores.begin(); it != scores.end(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}