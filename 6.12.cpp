/*��д������ֵ���򣬸�Ϊʹ�����ý�������ָ�뽻��*/
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