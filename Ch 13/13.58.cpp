/* 编写新的Foo类，其sorted函数中有打印语句*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Foo {
public:
	Foo sorted() && ;			// 可用于改变的右值
	Foo sorted() const &;	// 可用于任何类型的Foo
private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	cout << "&&" << endl;
	return *this;
}

Foo Foo::sorted() const &
{
	//Foo ret(*this);
	//sort(ret.data.begin(), ret.data.end());
	//return ret;

	std::cout << "&" << endl;

	// exec 13.56
	//Foo ret(*this);
	//return ret.sorted();

	// exec 13.57
	return Foo(*this).sorted();
}

int main()
{
	Foo().sorted();		// stack overflow
	Foo f;
	f.sorted();				// passed
}
