/*��дһ�����������Ĳ�����initializer_list<int>���͵Ķ��󣬺����Ĺ����Ǽ����б�������Ԫ�صĺ�*/
#include<iostream>
#include<initializer_list>

using namespace std;

int get_sum(const initializer_list<int> lst)
{
	int ret = 0;
	for (auto x : lst)
		ret += x;

	return ret;
}


int main()
{
	initializer_list<int> li{ 1,2,3,4,5 };

	cout << get_sum(li) << endl;
	cout << get_sum({1,2,3,4,5,6,7,8,9,10}) << endl;

	return 0;
}