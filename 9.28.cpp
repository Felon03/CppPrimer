/*��д����������һ��forward_list<string>������string������������
����Ӧ�������в��ҵ�һ��string,�����ڶ���string���뵽�����ŵ�һ��string֮���λ��
����һ��stringδ�������У��򽫵ڶ���string�嵽����ĩβ
*/
#include<iostream>
#include<forward_list>
#include<string>

using namespace std;

void insert_str(forward_list<string> &flist, const string &s1, const string &s2)
{
	auto prev = flist.before_begin(), curr = flist.begin();
	bool flag = false;			// ���flist���Ƿ����s1
	while (curr != flist.end())
	{
		if (*curr == s1)
		{
			prev = curr;		// prev���浱ǰ��Ԫ��
			curr = flist.insert_after(curr, s2);		// currָ���²����Ԫ��
			flag = true;
		}
		else
		{
			prev = curr;
			++curr;
		}
	}
	if (!flag)
		curr = flist.insert_after(prev, s2);		// ���flist�в���s1, ���ʱcurrָ��flist.end(), ��ָ�����һ��Ԫ�ص���prev
}

int main()
{
	forward_list<string> flist = { "hello", "world", "nice", "to", "meet", "you!" }, flist1 = { "a", "a","b","c","d" };
	string s1 = "world1", s2 = "guys";
	insert_str(flist, s1, s2);
	s1 = "a", s2 = "z";
	insert_str(flist1, s1, s2);

	for (const auto &x : flist)
		cout << x << " ";
	cout << endl;
	for (const auto &x : flist1)
		cout << x << " ";
	cout << endl;

	return 0;
}