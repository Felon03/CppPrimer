/*��дһ�γ���ʹ��do whileѭ���ظ���ִ����������������ʾ�û���������string����Ȼ�������϶̵��Ǹ��������*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	/*������ʾ�û�����һ���ַ�����Ȼ������϶̵�*/
	string rsp;	// rsp�����ж��Ƿ����һ���µ�����
	do
	{
		cout << "Please enter two strings:" << endl;
		string a, b;
		cin >> a >> b;
		if (a.size() > b.size())
			cout << "The shorter string is '" << b << "'" << endl;
		else if (a.size() < b.size())
			cout << "The shorter string is '" << a << "'" << endl;
		else
			cout << "The length of a and b are same." << endl;
		cout << "More? Enter yes or no: ";
		cin >> rsp;
	} while (!rsp.empty() && rsp[0] != 'n');
}