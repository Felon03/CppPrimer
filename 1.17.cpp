#include<iostream>
using namespace std;

int main8()
{
	// currVal ��ʾ��ǰͳ�Ƶ��������������ֵ����val
	int currVal = 0, val = 0;
	// ��ȡ��һ��������ȷ��ȷʵ�����ݿ��Դ���
	if (cin>>currVal)
	{
		int cnt = 1;				// �������ڴ���ĵ�ǰֵ�ĸ���
		while (cin>>val)
		{
			if (val == currVal)
			{
				++cnt;
			}
			else
			{
				cout << currVal << " occurs " << cnt << " times." << endl;
				currVal = val;		// ��¼��ֵ
				cnt = 1;					// ���ü�����
			}
		}	// while
		// ��ס��ӡ�ļ������һ��ֵ�ĸ���
		cout << currVal << " occurs " << cnt << " times." << endl;
	}	// if
	return 0;
}