/*��д���򣬶���string��int���У���ÿ��string��int����һ��pair'�У�pair������һ��vector��*/
#include<utility>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<pair<string, int>> vp;
	string word;
	int num;
	while (cin>>word>>num)
	{
		vp.push_back(make_pair(word, num));
	}

	// 11.13 ���ò�ͬ�ķ�������pair
	vp.push_back(pair<string, int>(word, num));
	vp.push_back(pair<string, int>{word, num});	// �ȼ�����һ��
	vp.push_back({ word, num });

	for (const auto &x : vp)
		cout << x.first << ":" << x.second << endl;

	return 0;
}