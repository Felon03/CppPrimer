#pragma once
/* 定义Basket类*/
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

	// 打印每本书的总价和购物篮中所有书的总价
	double total_receipt(std::ostream&) const;

private:
	// 比较shared_ptr, multiset成员使用它
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	// multiset存在多个报价，按照compare成员排序
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*>
		items{ compare };
};

inline double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	// iter指向ISBN相同的一批元素中的第一个
	// upper_bound返回一个迭代器，改迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;    // 打印最终的总价格
	return sum;
}