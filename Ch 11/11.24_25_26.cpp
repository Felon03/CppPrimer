#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	// 11.24 ����������ʲô���ܣ�
	map<int, int> m;
	m[0] = 1;
	// ��map m�����һ��ؼ���Ϊ0�� ֵΪ1��Ԫ��
	for (const auto &e : m) cout << e.first << " " << e.second << endl;

	// 11.25 �Ա������������һ�����
	vector<int> v;
	v[0] = 1;
	 //vector vΪ�գ����޷�����v[0], ��˸ó���������
	for (const auto &e : v) cout << e << endl;

	// 11.26 ������ʲô��������һ��map�����±������
	// �±���������ص�������ʲô��
	// �����һ�����������-- ������һ��map��Ȼ��д��һ������������map
	// �����±�����������Լ��±���������᷵�ص�����
	map<int, int> map = { {1,2},{3,10} };

	std::map<int, int>::key_type type = 1;
	// ����ʹ��int��������map�����±����

	std::map<int, int>::mapped_type return_type = map[type];
	// �±���������ص�����Ҳ������int

	return 0;
}