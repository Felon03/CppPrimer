/*Ϊwhileѭ��дһ��������ʹ��ӱ�׼�����ж�ȡ����������42ʱֹͣ*/
#include<iostream>

using namespace std;

int main()
{
	int num;
	while (cin >> num&&num != 42)
	{
		cout << num << endl;
	}
	cout << "You have input number '42', program terminate." << endl;

	return 0;
}