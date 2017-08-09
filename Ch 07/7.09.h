#pragma once
/*����Person�࣬Ϊ����Ӷ�ȡ�ʹ�ӡPerson����ĺ���*/
#include<string>

class Person
{
public:
	std::string name;			// ����
	std::string address;		// ��ַ

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