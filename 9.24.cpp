/*��д���򣬷ֱ�ʹ��at���±��������front��begin��ȡһ��vector�еĵ�һ��Ԫ�ء�
��һ����vector�ϲ��Գ���
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec;		// ����һ����vector

	cout << vec.at(0) << endl
		<< vec[0] << endl
		<< vec.front() << endl
		<< *vec.begin() << endl;

	return 0;
}