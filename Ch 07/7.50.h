/*确定在你的Person类中是否有一些构造函数应该是explicit的*/
#pragma once
#include<string>

class Person
{
	friend std::istream &read(std::istream &is, Person &person);
	friend std::ostream &print(std::ostream &os, const Person &person);

private:
	std::string name;
	std::string address;

public:
	const std::string getName() const { return name;}
	const std::string getAddress() const { return address; }

	// 构造函数
	Person() = default;
	Person(const std::string &sname, const std::string &saddress) : name(sname), address(saddress) {}
	explicit Person(std::istream &is) { read(is, *this); }		// 可以将构造函数定义成explicit的

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