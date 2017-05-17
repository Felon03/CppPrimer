/*��д���򣬽�������������һ�������ļ�����������ļ����ļ����������ļ������Ӧ����������
	ʹ��istream_iterator��ȡ�����ļ���ʹ��ostream_iterator������д���һ������ļ���ÿ��
	֮�󶼸�һ���ո񡣽�ż��д��ڶ�������ļ���ÿ��ֵ����ռһ�С�
*/
#include<fstream>
#include<iostream>
#include<iterator>
#include<string>
#include<vector>

using namespace std;

int classification(const string &s1, const string &s2, const string &s3)
{
	ifstream ifs(s1);
	if (!ifs) 
	{
		cout << "Fali to open" << s1 << endl;
		return -1;
	}
	istream_iterator<int> in(ifs), eof;
	vector<int> iv;
	copy(in, eof, back_inserter(iv));

	ofstream oddfs(s2), evenfs(s3);
	ostream_iterator<int> odd(oddfs, " "), even(evenfs, "\n");
	for (const auto &x : iv)
	{
		x % 2 == 0 ? even = x : odd = x;
	}
	return 1;
}

int main()
{
	string s1 = "data/int.txt",
		s2 = "data/odd.txt",
		s3 = "data/even.txt";
	auto ret = classification(s1, s2, s3);
	if (ret == 1)
		cout << "Classification success!" << endl;
	else
		cout << "Classification fail..." << endl;
	return 0;
}