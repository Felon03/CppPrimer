/*��д���򣬴ӱ�׼�����ȡstring���У�����һ��deque�С�
��дһ��ѭ�����õ�������ӡdeque�е�Ԫ��
*/
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
	string word;
	deque<string> deqStr;

	while (cin >> word)
		deqStr.push_back(word);

	for (auto iter = deqStr.cbegin(); iter != deqStr.cend(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}