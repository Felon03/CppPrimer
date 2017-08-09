/*��make_plural�����ĵڶ����βθ���Ĭ��ʵ�Ρ�s���������°汾�ĺ������success��failure�ĵ����͸�����ʽ*/
#include<iostream>
#include<string>

using namespace std;

// ���ctr��ֵ����1������word�ĸ�����ʽ
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << make_plural(1, "success") << endl;
	cout << make_plural(1, "falure") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(2, "failure") << endl;

	return 0;
}