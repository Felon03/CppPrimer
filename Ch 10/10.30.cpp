/*使用流迭代器、sort和copy从标准输入读入一个整数序列，将其排序，
	并将结果写到标准输出。
*/
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> iv;
	while (in != eof)
		iv.push_back(*in++);
	// 对容器中的元素进行排序
	sort(iv.begin(), iv.end());
	// 通过copy打印排序后的元素
	copy(iv.cbegin(), iv.cend(), out);
	//for (auto e : iv)
	//	*out++ = e;
	cout << endl;

	return 0;
	
}