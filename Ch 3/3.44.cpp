/*��д��һ��ϰ�еĳ���ʹ�����ͱ���������ѭ�����Ʊ���������*/
#include<iostream>

using namespace std;

int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}	
	};

	size_t cnt = 0;

	/*ʹ�÷�Χfor���ia����Ԫ��*/
	cout << "ʹ�÷�Χfor���ia����Ԫ��" << endl;
	using int_array = int[4];
	for (int_array &row : ia)
		for (int &col : row)
		{
			cout << col << " ";
			cnt++;
			if (cnt == 4)
			{
				cout << endl;
				cnt = 0;
			}
		}
			
	cout << endl;

	/*ʹ����ͨfor���±����*/
	cout << "ʹ����ͨfor���±����" << endl;
	using size = size_t;
	for (size i = 0; i != 3; ++i)
		for (size j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	cout << endl;

	/*ʹ����ͨfor��ָ�����*/
	cout << "ʹ����ͨfor��ָ�����" << endl;
	for (int_array *p = ia; p != ia + 3; ++p)
		for (int *q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	cout << endl;

	return 0;
}