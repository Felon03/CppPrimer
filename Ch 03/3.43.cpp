/*编写三个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程
版本2和版本3都适用普通for语句，其中版本2要求用下标运算符
版本3要求使用指针。三个版本都要直接写出数据类型，不能使用类型别名、auto关键字或decltype关键字	*/
#include<iostream>

using namespace std;

int main()
{
	/*定义ia[3][4]数组*/
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	/*使用范围for输出ia*/
	cout << "使用范围for输出ia数组" << endl;
	for (int(&row)[4] : ia)
		for (int &col : row)
			cout << col << " ";
	cout << endl;

	cout << "使用普通for和下标运算符输出ia数组" << endl;
	/*使用普通for和下标运算符*/
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 4; j++)
			cout << ia[i][j] << " ";
	cout << endl;

	cout << "使用普通for和指针输出ia数组" << endl;
	/*使用普通for和指针*/
	for (int(*p)[4] = ia; p != ia + 3; ++p)
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	cout << endl;

	return 0;

}