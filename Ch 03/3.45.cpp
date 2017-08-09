/*再次改写程序，这次使用auto关键字*/
#include<iostream>

using namespace std;

int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	/*使用范围for输出ia*/
	cout << "使用范围for输出ia" << endl;
	for (auto &row : ia)
		for (auto & col : row)
			cout << col << " ";
	cout << endl;

	/*使用普通for加下标*/
	cout << "使用普通for加下标输出ia" << endl;
	for (auto i = 0; i != 3; i++)
		for (auto j = 0; j != 4; j++)
			cout << ia[i][j] << " ";
	cout << endl;

	/*使用普通for加指针输出ia*/
	cout << "使用普通for加指针输出ia" << endl;
	for (auto *p = ia; p != ia + 3; ++p)
		for (auto q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	cout << endl;

	return 0;
}