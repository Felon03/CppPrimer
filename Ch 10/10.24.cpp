/*����һ��string��ʹ��bind��check_size��һ��int��vector�в��ҵ�һ������string���ȵ�ֵ*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

auto find_first_bigger(const vector<int> &v, const string &s)
{
	return find_if(v.begin(), v.end(),
		bind(check_size, s, _1));
}

int main()
{
	vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string s = "test";
	// ����1��ֱ��ʹ��find_if
	auto iter = find_if(ivec.begin(), ivec.end(), bind(check_size, s, _1));
	/*
	************************
	 * find_if()
	 * find_if()�㷨������������
	 * ���Ƚ���һ�Ե���������ʾһ����Χ
	 * ������������һ��ν�ʣ�find_if�����������е�ÿ��Ԫ�ص��ø��������ν�ʣ�
	 * �����ص�һ����ν�ʷ��ط�0ֵ��Ԫ�أ���������ڣ��򷵻�β��������
	 *************************
	 */
	cout << *iter << endl;
	// ����2������find_first_bigger()����
	auto iter1 = find_first_bigger(ivec, s);
	cout << *iter1 << endl;

	return 0;
}