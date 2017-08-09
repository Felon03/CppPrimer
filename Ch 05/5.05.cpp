/*写一段自己的程序，使用if else语句实现吧数字成绩转换成字母成绩的要求*/
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

	/*另一种写法*/
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