/*假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。定义类C，C有一个NoDefault类型的成员，定义C的默认构造函数*/
#include<iostream>
#include<vector>

using namespace std;

class NoDefault
{
public:
	NoDefault(int i) {}
};

class C
{
private:
	NoDefault def;

public:
	C() : def(0) {}
};

int main()
{
	C c;
	//vector<NoDefault> vec(10);		// 不合法，NoDefault没有默认的构造函数
	vector<C> vec(10);							// 合法，C有默认构造函数

	return 0;
}