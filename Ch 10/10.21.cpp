/*编写一个lambda，不惑一个局部int变量，并递减变量值，直至它变为0
	一旦变量变为0，再调用lambda应该不再递减变量。labmda应该返回一个bool值，
	指出捕获的变量是否为0
*/
#include<iostream>

using namespace std;

int main()
{
	int v1 = 10;
	auto f = [&v1]()->bool
	{
		if (v1 == 0)
		{
			return true;
		}
		else
		{
			--v1;
			return false;
		}
	};

	while (!f()) cout << v1 << endl;

	return 0;
}