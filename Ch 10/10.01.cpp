/*ͷ�ļ�algorithm�ж�����һ����Ϊcount�ĺ�����������find������һ�Ե�������һ��ֵ��Ϊ������
count���ظ���ֵ�������г��ֵĴ�����
��д���򣬶�ȡint���д���vector�У���ӡ�ж��ٸ�Ԫ�ص�ֵ���ڸ���ֵ
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> ivec{ 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,0 };
	int val = 1;
	auto result = count(ivec.begin(), ivec.end(), val);
	cout << val << " appeared " << result << " times." << endl;

	return 0;
}