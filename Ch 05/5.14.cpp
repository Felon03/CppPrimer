/*��дһ�γ��򣬴ӱ�׼�����ж�ȡ����string���󲢲��������ظ����ֵĵ��ʡ�*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> st;
	string st1, prestr;
	unsigned int wordCnt = 1;
	bool flag = false;
	while (cin >> st1)
	{
		st.push_back(st1);
	}

	auto beg = st.begin();
	while (beg != st.end())
	{
		if (prestr == *beg)
		{
			++wordCnt;
			prestr = *beg;
			++beg;
		}
		else
		{
			if (wordCnt > 1)
			{
				cout << prestr << " occurs " << wordCnt << " times" << endl;
				wordCnt = 1;
				flag = true;
			}
			prestr = *beg;
			++beg;
		}
		if (beg == st.end())	// ͳ�������������ĵ���
			if (wordCnt > 1)
			{
				cout << prestr << " occurs " << wordCnt << " times" << endl;
				flag = true;
				//wordCnt = 1;	// ���ü�����
			}
	}
	/*�ж��Ƿ����ظ��ĵ��� flag Ϊ true�����ظ��ĵ���*/
	if (!flag)
		cout << "No word occurs more than 2 times." << endl;

	return 0;
}