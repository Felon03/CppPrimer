#include<iostream>
#include<string>	
using namespace std;

int main()
{
	string s;
	string result;
	while (cin>>s)
	{
		// ��������ַ����ϲ�
		//result += s;
		// ��������ַ����ϲ���ÿ������֮���ɿո�ָ�
		result += s + " ";
	}
	cout << "The content of string: " << result << endl;

	return 0;
}