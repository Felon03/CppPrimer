/*��д����������һ����ʾ���ֵ�string�����������ֱ��ʾǰ׺(��Mr.��Ms.)�ͺ�׺(��Jr.��III)���ַ���
ʹ�õ�������insert��append������ǰ׺�ͺ�׺��ӵ������������У������ɵ���string����
*/
#include<iostream>
#include<string>	

using namespace std;

string extend_str(const string &s, const string &pre, const string &suff)
{
	string ret = s;
	auto beg = ret.begin();
	ret.insert(beg, pre.begin(), pre.end());
	ret.append(suff);
	return ret;
}

int main()
{
	string name;
	cout << "Please enter your name: ";
	cin >> name;
	cout << extend_str(name, "Mr. ", " bonjour!") << endl;

	return 0;
}