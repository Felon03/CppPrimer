/*为Person类添加正确的构造函数*/
#pragma once
#include<string>

class Person;
std::istream &read(std::istream &is, Person &person);
std::ostream &print(std::ostream &os, const Person &person);

class Person
{
	// 为Person的非成员函数作友元声明
	friend std::istream &read(std::istream &is, Person &person);
	friend std::ostream &print(std::ostream &os, const Person &person);
private:
	std::string name;			// 姓名
	std::string address;		// 地址

public:
	const std::string &getName() const { return name; }
	const std::string &getAddress() const { return address; }

	//构造函数
	Person() = default;
	Person(const std::string &sname, const std::string &saddress) : name(sname), address(saddress){}
	Person(std::istream &is) { read(is, *this); }
};

std::istream &read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
	if (!is) person = Person();
	return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.name << " " << person.address;
	return os;
}
