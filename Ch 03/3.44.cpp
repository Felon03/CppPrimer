/*改写上一练习中的程序，使用类型别名啦代替循环控制变量的类型*/
#include<iostream>

using namespace std;

int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}	
	};

	size_t cnt = 0;

	/*使用范围for输出ia数组元素*/
	cout << "使用范围for输出ia数组元素" << endl;
	using int_array = int[4];
	for (int_array &row : ia)
		for (int &col : row)
		{
			cout << col << " ";
			cnt++;
			if (cnt == 4)
			{
				cout << endl;
				cnt = 0;
			}
		}
			
	cout << endl;

	/*使用普通for和下标输出*/
	cout << "使用普通for和下标输出" << endl;
	using size = size_t;
	for (size i = 0; i != 3; ++i)
		for (size j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	cout << endl;

	/*使用普通for和指针输出*/
	cout << "使用普通for和指针输出" << endl;
	for (int_array *p = ia; p != ia + 3; ++p)
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	cout << endl;

	return 0;
}