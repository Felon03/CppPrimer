/*�����200ҳ��str_subrange������������ı���������δ������еĴ����*/
#include<iostream>
#include<string>

using namespace std;

bool str_sunrange(const string &str1, const string &str2)
{
	// ��С��ͬ�� ��ʱ����ͨ��������жϽ����Ϊ����ֵ
	if (str1.size() == str2.size())
		return str1 == str2;
	// �õ��϶�string����Ĵ�С�����������
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	// �������string����Ķ�Ӧ�ַ��Ƿ���ȣ��Խ϶̵��ַ�������Ϊ��
	for (decltype(size) i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;		// ���� #1��û�з���ֵ��������������
	}
	// ���� #2��������������δ�����κ�ֵ�ͽ����˺�����ִ��
	// ���������ܼ�鲻����һ����

}

int main()
{
	string str1 = "asdf";
	string str2 = "qwerty";

	cout << str_sunrange(str1, str2) << endl;

	return 0;
}