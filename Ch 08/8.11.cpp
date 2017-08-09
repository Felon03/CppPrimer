/*本节程序在外层while循环中定义了istringstream对象，如果record对象定义在循环之外，程序如何修改？*/
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