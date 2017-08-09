/*改写交换数值程序，改为使用引用交换而非指针交换*/
#include<iostream>

using namespace std;

void exchange_value(int &p, int &q)
{
	int tmp = p;
	p = q;
	q = tmp;

	return;
}

int main()
{
	int x, y;
	cout << "Enter tow integers: " << endl;
	cin >> x >> y;
	exchange_value(x, y);
	cout << "Exchange tow integers: " << x << " " << y << endl;

	return 0;
}