/*��дһ��������ͬʱ�õ��βΡ��ֲ������;�̬�ֲ�����*/
#include<iostream>

using namespace std;

// ���庯��func��ͬʱ�õ��������ֲ���
void func(int n);	

int main()
{
	int x;
	while (cin >> x)
		func(x);
	return 0;
}

void func(int n)		// nΪ�β�
{
	int ret = 1;	// retΪ�ֲ�����
	static int cnt = 0;	// cntΪ��̬�ֲ�����

	ret += n;
	++cnt;

	cout << "Result = " << ret << endl
		<< "Function calling count: " << cnt << endl;

	return;
}
