/*���õ�������д3.3.3�ڻ��ַ����εĳ���*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<unsigned> scores(11, 0);	// 11�������Σ�ȫ����ʼ��Ϊ0
	unsigned grade;
	auto begin = scores.begin();
	while (cin>>grade)
	{
		if (grade<=100)
			*(begin + grade / 10) += 1;
	}
	for (auto it = scores.begin(); it != scores.end(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}