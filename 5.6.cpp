/*��д��һ�����ʹ���������������if else���*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> grade = { "F","D","C","B","A","A++" };
	int score;
	cout << "Please input a score(0-100): " << endl;
	cin >> score;
	score < 60 ? (cout << grade[0]) : (cout << grade[(score - 50) / 10]);

	return 0;
}