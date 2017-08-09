/*��дһ���ݹ麯�������vector���������*/
#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>::iterator beg, vector<int>::iterator end)
{
	if (beg != end)
	{
		cout << *beg << " ";
		print(next(beg), end);
	}
}

// �ڵ���factorial����ʱ��Ϊʲô���Ǵ����ֵ��val-1����val--
// �������val--���������õĲ�����Զ����val����һ����ѭ��
int factorial(int val)
{
	if (val > 1)
		return factorial(val-1)*val;
	return 1;
}

int main()
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	print(vec.begin(), vec.end());
	cout << endl;
	cout << factorial(10) << endl;

	return 0;
}