#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>

using namespace std;

int main()
{
	// 11.9 ����һ��map����������һ���кŵ�lsit�������list�б�����ǵ��������ֵ��к�
	map<string, list<size_t>> m;

	// 11.10 ���Զ���һ��vector<int>::iterator��int��map��
	// list<int>::iterator��int��map�أ��������������������ܣ�����Ϊʲô

	// ���Զ���vector<int>::iterator��int��map, vector�ĵ�����֧�֡�<������
	map<vector<int>::iterator, int> vm;

	// ���Զ���list<int>::iterator��int��map
	// �������ͨ��
	map<list<int>::iterator, int> lm;

	// ���ǲ���ʹ�ã���Ϊlist��Ԫ�ز��������洢�ģ���֧�ֱȽϲ���
	std::list<int> li;
	lm.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));
	/*
	�����ơ�<��: û���ҵ����ܡ�const std::_List_iterator<std::_List_val<std::_List_simple_types<int>>>�����͵���������������(��û�пɽ��ܵ�ת��)
	CppPrimer	c:\program files (x86)\microsoft visual studio 14.0\vc\include\xstddef	239	
	*/
	return 0;
}