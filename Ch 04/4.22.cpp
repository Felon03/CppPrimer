/*��60�ֵ�75��֮��ĳɼ��趨Ϊlow pass*/
#include<iostream>

using namespace std;

int main()
{
	int grade;
	cout << "Please input the grade" << endl;
	cin >> grade;
	/*ʹ�����������*/
	cout << ((grade > 90) ? "high pass" : (grade <= 75 && grade >= 60) ? "low pass" : (grade < 60) ? "fail" : "pass") << endl;

	/*ʹ��if���*/
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