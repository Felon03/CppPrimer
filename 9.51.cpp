/*设计一个类，他又三个unsigned成员，分别表示年、月和日。
为其编写构造函数，接受一个表示日期的string参数。
你的构造函数应该能处理不同数据格式，如January 1, 1900、1/1/1900、Jan 1 1900等*/
#include<iostream>
#include<string>
using namespace std;

unsigned get_month(const string &s)
{
	unsigned month;
	if (s.find("Jan") < s.size()) month = 1;
	if (s.find("Feb") < s.size()) month = 2;
	if (s.find("Mar") < s.size()) month = 3;
	if (s.find("Apr") < s.size()) month = 4;
	if (s.find("May") < s.size()) month = 5;
	if (s.find("Jun") < s.size()) month = 6;
	if (s.find("Jul") < s.size()) month = 7;
	if (s.find("Aug") < s.size()) month = 8;
	if (s.find("Sep") < s.size()) month = 9;
	if (s.find("Oct") < s.size()) month = 10;
	if (s.find("Nov") < s.size()) month = 11;
	if (s.find("Dec") < s.size()) month = 12;

	return month;
}

class Date
{
public:
	unsigned year = 0;
	unsigned month = 0;
	unsigned day = 0;

public:
	Date(const string &s);
};

Date::Date(const string & s)
{
	unsigned format = 0;

	//! 1/1/1900
	if (s.find_first_of("/") != string::npos) format = 0x1;

	//! Jan 1, 1900, January 1, 1900
	if (s.find_first_of(",") >= 4 && s.find_first_of(",") != string::npos) format = 0x2;

	//! Jan 1 1900
	if (s.find_first_of(",") == string::npos && s.find_last_of(" ") != string::npos) format = 0x3;

	switch (format)
	{
		// format = 1/1/1900
	case 0x1:
		day = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/") - 1));
		month = stoi(s.substr(0, s.find_first_of("/")));
		year = stoi(s.substr(s.find_last_of("/") + 1, 4));
		break;
		// format = Jan 1, 1900 or January 1, 1900
	case 0x2:
		// split day from entered string
		day = stoi(s.substr(s.find_first_of("0123456789"), s.find_first_of(",") - s.find_first_of("0123456789")));
		// split month from entered string
		month = get_month(s);
		//if (s.find("Jan") < s.size()) month = 1;
		//if (s.find("Feb") < s.size()) month = 2;
		//if (s.find("Mar") < s.size()) month = 3;
		//if (s.find("Apr") < s.size()) month = 4;
		//if (s.find("May") < s.size()) month = 5;
		//if (s.find("Jun") < s.size()) month = 6;
		//if (s.find("Jul") < s.size()) month = 7;
		//if (s.find("Aug") < s.size()) month = 8;
		//if (s.find("Sep") < s.size()) month = 9;
		//if (s.find("Oct") < s.size()) month = 10;
		//if (s.find("Nov") < s.size()) month = 11;
		//if (s.find("Dec") < s.size()) month = 12;
		// split year from entered string
		year = stoi(s.substr(s.find_first_of(",") + 2, 4));
		break;
		// format = Jan 1 1900
	case 0x3:
		// split day from entered string
		day = stoi(s.substr(s.find_first_of(" ") + 1, s.find_last_of(" ") - 1));
		// split month from entered string
		month = get_month(s);
		//if (s.find("Jan") < s.size()) month = 1;
		//if (s.find("Feb") < s.size()) month = 2;
		//if (s.find("Mar") < s.size()) month = 3;
		//if (s.find("Apr") < s.size()) month = 4;
		//if (s.find("May") < s.size()) month = 5;
		//if (s.find("Jun") < s.size()) month = 6;
		//if (s.find("Jul") < s.size()) month = 7;
		//if (s.find("Aug") < s.size()) month = 8;
		//if (s.find("Sep") < s.size()) month = 9;
		//if (s.find("Oct") < s.size()) month = 10;
		//if (s.find("Nov") < s.size()) month = 11;
		//if (s.find("Dec") < s.size()) month = 12;
		// split year from entered string
		year = stoi(s.substr(s.find_last_of(" ") + 1, 4));
		break;
	default:
		break;
	}
}

int main()
{
	Date d[] = { "10/03/1993", "October 03, 1993", "Oct 03 1993" };
	for (size_t i = 0; i < size(d); ++i)
	{
		cout << d[i].day << " " << d[i].month << " " << d[i].year << endl;
	}

	return 0;
}
