/*��дһ���������ж�string�������Ƿ��д�д��ĸ����д��һ����������string����ȫ���ĳ�Сд��ʽ*/
#include<iostream>
#include<string>

using namespace std;

bool has_Capital(const string &s)
{
	for (auto beg = s.begin(); beg != s.end(); ++beg)
		if (isupper(*beg))
			return true;
	return false;
}

string lower_string(string &s)
{
	for (auto &x : s)
		if (isupper(x))
		{
			x = tolower(x);		// ����Ǵ�д��ĸ����ΪСд
		}

	return s;
}

int main()
{
	string str("Hello World!");
	cout << boolalpha << has_Capital(str) << endl;		// std::boolalpha ��true false����ʽ���
	cout << lower_string(str) << endl;

	return 0;
}