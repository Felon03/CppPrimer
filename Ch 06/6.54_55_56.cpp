#include<iostream>
#include<vector>

using namespace std;

/*6.54
��д���������������������int�ββ��ҷ�������Ҳ��int��Ȼ������һ��vector��������Ԫ����ָ��ú�����ָ��
*/
int func(const int, const int);
typedef decltype(func) fp;	

/*6.55
��д�ĸ��������ֱ��intִֵ�мӡ������ˡ������㣻����һ��������Ķ����б���ָ����Щ������ָ��
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
��������vector�����е�ÿ��Ԫ�ز��������
*/
int main()
{
	// ����1
	for (auto x : vec)
		cout << x(2, 2) << endl;

	// ����2
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << (*it)(2, 2) << endl;

	return 0;
}