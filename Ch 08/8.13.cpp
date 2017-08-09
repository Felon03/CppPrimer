/*重写本节的电话号码程序，从一个命名文件而非cin读取数据*/
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
struct PersonInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string &str)
{
	for (auto i = 0; i != str.length(); ++i)
	{
		if (isdigit(str[i]))
			continue;
		else
			return false;
	}
	return true;
}

//bool valid(const string &str)
//{
//	return isdigit(str[0]);
//}

string format(const string &str)
{
	//cout << str << endl;
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
	ifstream input("C:/Users/Freed/Desktop/contacts.txt");
	if (!input)
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	while (getline(input, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (const auto & x : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : x.phones)
		{
			if (!valid(nums))
				badNums << " " << nums;
			else
				formatted << " " << format(nums);
		}
		if (badNums.str().empty())
			cout << left << setw(5) << "Name:" <<left << setw(10) << x.name << "Phone: " << formatted.str() << endl;
		else
			cerr << "input error: " << x.name << " invalid number(s)" << badNums.str() << endl;
	}


	return 0;
}