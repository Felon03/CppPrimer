/*��д��һ�⺯��������һ��������ָ���ҵ���Ԫ�ء�
ע�⣬������봦��δ�ҵ�����ֵ�����
*/
#include<vector>

using std::vector;

using iter = vector<int>::iterator;

iter find(iter beg, iter end, int value)
{
	for (auto itera = beg; itera != end; ++itera)
		if (*itera == value) return itera;
	return end;
}