/*��δ�һ��list<int>��ʼ��һ��vector<double>?
��һ��vector<int>�ָ���δ���?��д������֤��
*/
#include<iostream>
#include<list>
#include<vector>

using namespace std;

int main()
{
	// list<int> ��ʼ��vector<double>
	list<int> ilst{ 1,2,3,4,5,6,7,8 };
	for (auto x : ilst)
		cout << x << " ";
	cout << endl;
	vector<double> dv(ilst.begin(), ilst.end());

	for (auto x : dv)
		cout << x << " ";
	cout << endl;

	// vector<int> ��ʼ��vector<double>
	vector<int> ivc{ 1,2,3,4,5 };
	for (auto x : ivc)
		cout << x << " ";
	cout << endl;
	vector<double> dvc(ivc.begin(), ivc.end());
	for (auto x : dvc)
		cout << x << " ";
	cout << endl;

	return 0;
}