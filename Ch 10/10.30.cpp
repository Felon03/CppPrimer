/*ʹ������������sort��copy�ӱ�׼�������һ���������У���������
	�������д����׼�����
*/
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
	istream_iterator<int> in(cin), eof;
	ostream_iterator<int> out(cout, " ");
	vector<int> iv;
	while (in != eof)
		iv.push_back(*in++);
	// �������е�Ԫ�ؽ�������
	sort(iv.begin(), iv.end());
	// ͨ��copy��ӡ������Ԫ��
	copy(iv.cbegin(), iv.cend(), out);
	//for (auto e : iv)
	//	*out++ = e;
	cout << endl;

	return 0;
	
}