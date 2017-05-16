/*��׼�ⶨ����һ����Ϊcount_if���㷨������find_if���˺�������һ�Ե�������
��ʾһ�����뷶Χ��������һ��ν�ʣ�������뷶Χ��ÿ��Ԫ��ִ�С�count_if
����һ������ֵ����ʾΪ���ж��ٴ�Ϊ�档ʹ��count_if��д��д���ǳ�����ͳ��
�ж��ٵ��ʳ��ȳ���6�Ĳ���*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<string> words{ "cppprimer"," asdfg","qwertyu","zxcvbnm","123456","hello","world" };
	auto cnt = count_if(words.begin(), words.end(),
		[](const string &s) {return s.size() > 6; });
	cout << cnt << endl;

	return 0;
}