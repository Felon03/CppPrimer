/*��д����������һ��ָ��vector<int>�ĵ�������һ��intֵ��
������������ָ���ķ�Χ�в��Ҹ�����ֵ������һ������ֵ��ָ���Ƿ��ҵ�
*/
#include<vector>
using std::vector;

bool find(vector<int>::iterator beg, vector<int>::iterator end, int value)
{
	for (auto iter = beg; iter != end; ++iter)
		if (*iter == value) return true;
	return false;
}