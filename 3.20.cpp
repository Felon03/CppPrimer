/*
����һ�������������Ǵ���һ��vector���󣬽�ÿ�����������ĺ����������
��д����Ҫ���������һ�������һ��Ԫ�صĺͣ���������ڶ����͵����ڶ���Ԫ�صĺͣ��Դ����ơ�
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> num_array;
	int num;

	while (cin >> num)
		num_array.push_back(num);

	// ��ÿ�����������ĺ����
	for (decltype(num_array.size()) i = 0; i < num_array.size() - 1; i++)
		cout << num_array[i] + num_array[i + 1] << endl;

	// �������һ�������һ��Ԫ�صĺͣ���������ڶ����͵����ڶ���Ԫ�صĺͣ��Դ�����
	decltype(num_array.size()) k = num_array.size() - 1;
	for (decltype(num_array.size()) i = 0; i < num_array.size(); i++)
	{
		if (i <= k)
		{
			cout << num_array[i] + num_array[k] << endl;
			k--;
		}
	}

	return 0;
}