/*��дһ�γ��򣬴ӱ�׼�����ж�ȡstring���������ָ����������������ͬ�ĵ��ʻ������е��ʶ�����Ϊֹ*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str, preStr;	// preStr��¼ǰһ������
	cout << "Please enter some words:	" << endl;
	bool flag = false;
	while (cin >> str && !str.empty())
	{
		if (str == preStr)
		{
			cout << str << " occurs continuously." << endl;
			flag = true;
			break;
		}
		else
			preStr = str;
	}
	// �������ʱ��δ���������ֵĵ���
	if (!flag)
		cout << "No word occurs continuously." << endl;

	return 0;
}