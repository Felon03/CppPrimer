/*��д������һ��vector<string>,��Ԫ�ض���ʾ����ֵ������vector������Ԫ�صĺ͡�
�޸ĳ���ʹ֮�����ʾ����ֵ��string֮�͡�
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> ivec{ "0","1", "1", "2", "3", "4", "5", "100", "15", "-15" };
	vector<string> dvec{ "0.5","1.7","3.6","4.9","10.68","7.23","6.59" };
	// ��������ֵ��string֮��
	int result = 0;
	for (const auto &x : ivec)
	{
		result += stoi(x);
	}
	cout << result << endl;

	// ���㸡��ֵ��string֮��
	double dresult = 0.0;
	for (const auto &x : dvec)
		dresult += stod(x);
	cout << dresult << endl;

	return 0;
}