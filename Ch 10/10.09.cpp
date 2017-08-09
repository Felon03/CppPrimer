/*ʵ�����Լ���elimDups��������ĳ��򣬷ֱ��ڶ�ȡ����󡢵���unique���Լ�erase���ӡvector������*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//template <typename Sequence> auto println(Sequence const &seq) ->ostream &
//{
//	for (auto const &elem : seq)
//		cout << elem << " ";
//	return cout << endl;
//}

void elimDup(vector<string> &words)
{
	// ���ֵ�����words���Ա�����ظ�����
	sort(words.begin(), words.end());
	for (auto const &x : words)
		cout << x << " ";
	cout << endl;
	// unique�������뷶Χ���ǵ�ÿ������ֻ����һ��
	// �����ڷ�Χ��ǰ��������ָ���ظ�����֮��һ��λ�õĵ�����
	auto end_unique = unique(words.begin(), words.end());
	for(auto const &x : words)
		cout << x << " ";
	cout << endl;
	// ʹ����������eraseɾ���ظ�����
	words.erase(end_unique, words.end());
	for (auto const &x : words)
		cout << x << " ";
	cout << endl;
}

int main()
{
	vector<string> vec{ "a","v","a","s","v","a","a","q","w","e" };
	for (auto const &x : vec)
		cout << x << " ";
	cout << endl;
	elimDup(vec);

	return 0;
}