#pragma once
/* ����Bulk_quote��*/
#include"15.3_Quote.h"


class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
		: Quote(book, p), min_qty(qty), discount(disc)
	{
	}
	
	// ���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
	virtual double net_price(std::size_t cnt) const override
	{
		if (cnt >= min_qty) return cnt*(1 - discount)*price;
		else return cnt*price;
	}
private:
	std::size_t min_qty = 0;    // �����ۿ����ߵ���͹�����
	double discount = 0.0;    // ��С����ʾ���ۿ۶�
};