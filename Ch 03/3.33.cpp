#include<iostream>


using namespace std;

int main()
{
	unsigned scores[11];	// ����ʼ�����齫���·ֶμ�������
	unsigned grade;
	// ��ȡ��βָ�� C++11
	unsigned *beg = begin(scores);
	unsigned *last = end(scores);	// βָ��ָ��������һ��Ԫ�صĺ�һλ��������ִ�н����͵�������
	while (cin >> grade)
	{
		if (grade <= 100)
		{
			++scores[grade / 10];
		}
	}
	for (auto x : scores)
		cout << x << " ";
	cout << endl;

	return 0;
}