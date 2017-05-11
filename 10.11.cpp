/*��д����ʹ��stable_sort��isShorter�����ݸ����elimDups�汾��vector����
��ӡvector�����ݣ���֤�������ȷ��
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	// ���ֵ�������words��һ�߲����ظ�����
	sort(words.begin(), words.end());
	// unique�������뷶Χ
	auto end_unique = unique(words.begin(), words.end());
	// ʹ����������eraseɾ���ظ�����
	words.erase(end_unique, words.end());
}

int main()
{
	vector<string> svec{ "the", "quick", "red", "fox", "jumps","over","the","slow","red","turtle" };
	elimDups(svec);
	for (const auto &s : svec)
		cout << s << " ";
	cout << endl;
	/*stable_sort �� sort����������� ǰ�����������ʹԭ������ͬ����ֵ�������е����λ�ò���*/
	stable_sort(svec.begin(), svec.end(), isShorter);
	for (const auto &x : svec)
		cout << x << " ";
	cout << endl;

	//sort(svec.begin(), svec.end(), isShorter);
	//for (const auto &x : svec)
	//	cout << x << " ";
	//cout << endl;

	return 0;
}