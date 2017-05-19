/*������decltype���¶���bookstore*/
#include<iostream>
#include<set>
#include"Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	// ʹ��decltype
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	// class std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>

	// ����1: ʹ��typedef
	typedef bool(*compareType)(const Sales_data &, const Sales_data &);
	multiset<Sales_data, compareType> bookstore(compareIsbn);
	// class std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>

	// ����2: ʹ��using
	using cmp_t = bool (*)(const Sales_data &, const Sales_data &);
	multiset<Sales_data, cmp_t>bookstore(compareIsbn);
	// class std::multiseet<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>

	return 0;
}