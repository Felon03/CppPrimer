/*��дһ������ʱ�ڽ��ܱ�����ʾ��ѡ�������ݸ�main����ʵ�ε�����*/
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char **argv)		// argv��һ�����飬����Ԫ��ָ��C����ַ���ָ�룬��һ���β�argc��ʾ�������ַ���������
{
	string str;
	for (auto i = 1; i != argc; ++i)
		cout << argv[i] << endl;

	return 0;
}
