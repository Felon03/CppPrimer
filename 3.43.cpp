/*��д������ͬ�汾�ĳ�������������ia��Ԫ�ء��汾1ʹ�÷�Χfor�������������
�汾2�Ͱ汾3��������ͨfor��䣬���а汾2Ҫ�����±������
�汾3Ҫ��ʹ��ָ�롣�����汾��Ҫֱ��д���������ͣ�����ʹ�����ͱ�����auto�ؼ��ֻ�decltype�ؼ���	*/
#include<iostream>

using namespace std;

int main()
{
	/*����ia[3][4]����*/
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};

	/*ʹ�÷�Χfor���ia*/
	cout << "ʹ�÷�Χfor���ia����" << endl;
	for (int(&row)[4] : ia)
		for (int &col : row)
			cout << col << " ";
	cout << endl;

	cout << "ʹ����ͨfor���±���������ia����" << endl;
	/*ʹ����ͨfor���±������*/
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 4; j++)
			cout << ia[i][j] << " ";
	cout << endl;

	cout << "ʹ����ͨfor��ָ�����ia����" << endl;
	/*ʹ����ͨfor��ָ��*/
	for (int(*p)[4] = ia; p != ia + 3; ++p)
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	cout << endl;

	return 0;

}