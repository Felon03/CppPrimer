/*ȷ�������Person�����Ƿ���һЩ���캯��Ӧ����explicit��*/
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

	// ���캯��
	Person() = default;
	Person(const std::string &sname, const std::string &saddress) : name(sname), address(saddress) {}
	explicit Person(std::istream &is) { read(is, *this); }		// ���Խ����캯�������explicit��

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