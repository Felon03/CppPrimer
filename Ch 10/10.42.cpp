/*ʹ��list����vector����ʵ��ȥ���ظ����ʵĳ���*/
#include<iostream>
#include<list>
#include<string>

using namespace std;

void elimDups(list<string> &words)
{
	// ��words����
	words.sort();
	// ɾ���ظ�Ԫ��
	words.unique();
}

int main()
{
	list<string> ls{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(ls);
	for (const auto &x : ls)
		cout << x << " ";
	cout << endl;

	return 0;
}