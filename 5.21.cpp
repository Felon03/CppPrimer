/*�޸�5.20��ʹ���ҵ����ظ����ʱ����Դ�д��ĸ��ͷ*/
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
			if (str[0] >= 'A' && str[0] <= 'Z')
			{
				cout << str << " occurs continuously." << endl;
				flag = true;
				break;
			}
			else
				continue;
		}
		else
			preStr = str;
	}
	// �������ʱ��δ���������ֵĵ���
	if (!flag)
		cout << "No word occurs continuously." << endl;

	return 0;
}