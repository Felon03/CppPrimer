/*��дһ�������������������������һ����int����������һ����intָ�롣
�����Ƚ�int��ֵ��ָ����ָ��ֵ�����ؽϴ���Ǹ�
*/
#include<iostream>

using namespace std;

// �ȽϺ���
int compare_int(const int &a, const int *b)
{
	return a > *b ? a : *b;
}

int main()
{
	int x = 100;
	int y = 200;
	int *z = &y;
	
	cout << compare_int(x, z) << endl;

	return 0;
}