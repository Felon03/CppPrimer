/*��дһ����������������string����s��oldVal��newVal��ʹ�õ�������insert��erase����
��s�����е�oldVal�滻ΪnewVal��
���Գ��������滻tongue�ļ�д��ʽ
*/
#include<iostream>
#include<string>

using namespace std;

void replace_str(string &s, const string &oldVal, const string &newVal)
{
	for (auto beg = s.begin(); distance(beg, s.end()) > distance(oldVal.begin(), oldVal.end());)		// ��֤beg�����Ԫ�صĳ��ȴ��ڵ���oldVal�ĳ���
	{
		if (string(beg, beg + oldVal.size()) == oldVal)		// ����ҵ���
		{
			beg = s.erase(beg, beg + oldVal.size());		// ��ɾ��ԭ����oldVal
			beg = s.insert(beg, newVal.cbegin(), newVal.cend());		// �ٲ���newVal
			advance(beg, newVal.size());		// beg������ָ��neVal�ĺ�һ��Ԫ��
		}
		else
			++beg;		// û�ҵ�������һ��
	}

	return;
}

int main()
{
	string str1{ "Hello, it's worte by C++!!!" };
	replace_str(str1, "C++", "C Plus Plus");
	cout << str1 << endl;

	string str2{ "my world is a big world" };
	replace_str(str2, "big", "biggggggggggggggg");
	cout << str2 << endl;
	return 0;
}