/*дһ���Լ��ĳ���ʹ��if else���ʵ�ְ����ֳɼ�ת������ĸ�ɼ���Ҫ��*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	const vector<string> grade = { "F","D","C","B","A","A++" };
	int score;
	cout << "Please input a score(0-100): " << endl;
	cin >> score;

	if (score<60)
	{
		cout << grade[0];
	}
	else
	{
		cout << grade[(score - 50) / 10];
	}

	/*��һ��д��*/
	if (score == 100)
		cout << grade[5];
	else if (score >= 90)
		cout << grade[4];
	else if (score >= 80)
		cout << grade[3];
	else if (score >= 70)
		cout << grade[2];
	else if (score >= 70)
		cout << grade[1];
	else
		cout << grade[0];

	return 0;
}