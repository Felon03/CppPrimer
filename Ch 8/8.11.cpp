/*���ڳ��������whileѭ���ж�����istringstream�������record��������ѭ��֮�⣬��������޸ģ�*/
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (auto &x : people)
	{
		cout << left << setw(5) << "Name: " << left << setw(10) << x.name << " ";
		cout << "Phones: ";
		for (auto &p : x.phones)
			cout << p << " ";
		cout << endl;
	}

	return 0;
}