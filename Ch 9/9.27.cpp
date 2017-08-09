/*��д���򣬲��Ҳ�ɾ��forward_list<int>�е�����Ԫ��*/
#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> flist{ 0,1,2,3,4,5,6,7,8,9,10 };
	auto prev = flist.before_begin();		// ��ȡ��һ��Ԫ��֮ǰ�ĵ�����
	auto curr = flist.begin();							// ��ȡ��һ��Ԫ�صĵ�����
	while (curr != flist.end())
	{
		if (*curr % 2 != 0)			// ���������
			curr = flist.erase_after(prev);
		else
		{
			prev = curr;		// prevָ����һ��curr��currָ����һ��Ԫ��
			++curr;
		}
	}
	for (const auto &x : flist)
		cout << x << " ";
	cout << endl;
	return 0;
}