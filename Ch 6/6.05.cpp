/* ��дһ�����������ʵ�εľ���ֵ*/
#include<iostream>

using namespace std;

double cal_abs(double n);

int main()
{
	double n;
	cout << "Enter a number: " << endl;
	cin >> n;
	cout << cal_abs(n) << endl;

	return 0;
}

double cal_abs(double n)
{
	return n >= 0 ? n : -n;
}
