/*�޸�ǰһ�����ʹ��ֻ��ӡ���ظ���Ԫ�أ�Ӧʹ��unique_copy*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> iv;

	while (in != eof)
		iv.push_back(*in++);

	sort(iv.begin(), iv.end());
	unique_copy(iv.cbegin(), iv.cend(), out);
	cout << endl;

	return 0;
}