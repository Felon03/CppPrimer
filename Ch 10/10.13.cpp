/*ʹ��algorithm�е�partition�㷨��д����������һ��string������һ��boolֵ
	ָ��string�Ƿ���5�����߸����ַ���ʹ�ô˺�������words����ӡ�����ȴ��ڵ���5��Ԫ�ء�
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool is_length_less_than_five(const string &s)
{
	return s.size() < 5;
}

int main()
{
	vector<string> sv{ "the", "quick","red","fox","jumps","over","the", "slow","red","turtle" };
	auto iter = partition(sv.begin(), sv.end(), is_length_less_than_five);
	for (; iter != sv.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//auto f = [] {return 42; };
	//cout << f() << endl;
	return 0;
}