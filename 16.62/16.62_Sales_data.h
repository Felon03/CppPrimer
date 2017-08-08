#pragma once
/*
    16.62 �������Լ��汾��hash<Sales_data>��������һ��Sales_data����
	��unordered_multiset�����������׼�¼���浽�����У�����ӡ�����ݡ�
*/

#include<iostream>
#include<string>


class Sales_data {
	friend std::hash<Sales_data>;
	friend std::ostream &operator<<(std::ostream&, const Sales_data&);
	friend std::istream &operator >> (std::istream&, Sales_data&);
	friend bool operator==(const Sales_data&, const Sales_data&);

	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	//friend Sales_data add(const Sales_data&, const Sales_data&);
public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p)
		: bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream&);

	std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data&);

private:
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn()
		&& lhs.units_sold == rhs.units_sold
		&& lhs.revenue == rhs.revenue;
}

inline bool operator !=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

// old versions
Sales_data add(const Sales_data&, const Sales_data&);
//Sales_data &print(std::ostream&, const Sales_data&);
//Sales_data &read(std::istream&, Sales_data&);

// new operator functions
Sales_data operator+(const Sales_data&, const Sales_data&);
std::ostream &operator<<(const std::ostream&, const Sales_data&);
std::istream &operator>>(const std::istream&, Sales_data&);


// �������ܴ���Sales_data��hash�汾
namespace std {
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const;
	};
	inline size_t std::hash<Sales_data>::operator()(const Sales_data & s) const
	{
		return hash<std::string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}