#include<iostream>
#include<vector>

using namespace std;

/*6.54
编写函数声明，令其接受两个int形参并且返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针
*/
int func(const int, const int);
typedef decltype(func) fp;	

/*6.55
编写四个函数，分别对int值执行加、减、乘、除运算；在上一天给创建的对象中保存指向这些函数的指针
*/
inline int add(const int n1, const int n2)
{
	return n1 + n2;
}
inline int sub(const int n1, const int n2)
{
	return n1 - n2;
}
inline int mult(const int n1, const int n2)
{
	return n1*n2;
}
inline int divide(const int n1, const int n2)
{
	return n1 / n2;
}

vector<fp *> vec{ add, sub, mult, divide };

/*6.56
调用上述vector对象中的每个元素并输出其结果
*/
int main()
{
	// 方法1
	for (auto x : vec)
		cout << x(2, 2) << endl;

	// 方法2
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << (*it)(2, 2) << endl;

	return 0;
}