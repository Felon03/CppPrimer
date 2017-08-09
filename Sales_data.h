#pragma once
/*头文件不应该包含using声明*/
#include<string>

class Sales_data;
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

class Sales_data
{
	friend std::istream &read(std::istream &, Sales_data &);
	friend std::ostream &print(std::ostream &, const Sales_data &);
public:
	// 构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data(std::istream &is) { read(is, *this); }
	//Sales_data() : units_sold(0), revenue(0){}
	// 7.2
	// 添加新成员combine和isbn
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// combine具体函数
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;			// 返回调用改函数的对象
}

// 7.6 定义add、read和print函数
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

//Sales_data::Sales_data(std::istream & is)
//{
//	read(is, *this);		// read函数的作用是从is中读取一条交易信息然后存入this中
//}
