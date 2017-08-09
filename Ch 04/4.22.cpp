/*将60分到75分之间的成绩设定为low pass*/
#include<iostream>

using namespace std;

int main()
{
	int grade;
	cout << "Please input the grade" << endl;
	cin >> grade;
	/*使用条件运算符*/
	cout << ((grade > 90) ? "high pass" : (grade <= 75 && grade >= 60) ? "low pass" : (grade < 60) ? "fail" : "pass") << endl;

	/*使用if语句*/
	if (grade > 90)
		cout << "high pass" << endl;
	else if (grade <= 75 && grade >= 60)
		cout << "low pass" << endl;
	else if (grade < 60)
		cout << "fail" << endl;
	else
		cout << "pass" << endl;

	return 0;
}