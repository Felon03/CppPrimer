/*��дһ��lambda������һ���ֲ�int���������ݼ�����ֵ��ֱ������Ϊ0
	һ��������Ϊ0���ٵ���lambdaӦ�ò��ٵݼ�������labmdaӦ�÷���һ��boolֵ��
	ָ������ı����Ƿ�Ϊ0
*/
#include<iostream>

using namespace std;

int main()
{
	int v1 = 10;
	auto f = [&v1]()->bool
	{
		if (v1 == 0)
		{
			return true;
		}
		else
		{
			--v1;
			return false;
		}
	};

	while (!f()) cout << v1 << endl;

	return 0;
}