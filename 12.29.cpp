/*��������do whileѭ������д�û�������ѭ����
	��do while��д�����򣬽��������������һ���汾
*/
// do while ���ã���Ϊ���ϴ����߼�
#include"12.27.h"
#include<iostream>

using namespace std;

void runQuires(ifstream &file)
{
	TextQuery tq(file);
	do
	{
		cout << "Enter word to look for or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	} while (true);
}

int main()
{
	ifstream filename("data/story.txt");
	runQuires(filename);
	return 0;
}
