/* ��дһ��������������һ�α�����ʱ����0���Ժ�ÿ�α����÷���ֵ��1*/
#include<iostream>

using namespace std;

int calling_cnt()
{
	static int cnt = 0;

	return cnt++;
}

int main()
{
	for (int i = 0; i != 10; ++i)
		cout << calling_cnt() << endl;

	return 0;
}