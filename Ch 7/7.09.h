#pragma once
/*对于Person类，为其添加读取和打印Person对象的函数*/
#include<string>

class Person
{
public:
	std::string name;			// 姓名
	std::string address;		// 地址

public:
	const std::string& getName() const { return name; }
	const std::string& getAddress() const { return address; }
};

std::istream& read(std::istream is, Person& person)
{
	is >> person.name >> person.address;
	if (!is) person = Person();
	return is;
}

std::ostream& print(std::ostream os, const Person& person)
{
	os << person.name << " " << person.address;
	return os;
}