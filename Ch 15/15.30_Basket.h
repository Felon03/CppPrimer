#pragma once
/* ����Basket��*/
#include"15.30_Quote_Bulk_quote.h"
#include<memory>
#include<set>

using std::shared_ptr;

class Basket {
public:
	Basket() = default;

	void add_item(const Quote &sale)
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(const Quote &&sale)
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}

	// ��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(std::ostream&) const;

private:
	// �Ƚ�shared_ptr, multiset��Աʹ����
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	// multiset���ڶ�����ۣ�����compare��Ա����
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
		items{ compare };
};

inline double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	// iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
	// upper_bound����һ�����������ĵ�����ָ������Ԫ�ص�β��λ��
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;    // ��ӡ���յ��ܼ۸�
	return sum;
}