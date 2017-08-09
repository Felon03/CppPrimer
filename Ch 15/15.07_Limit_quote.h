#pragma once
/* ����һ���࣬ʹ��ʵ��һ���������޵��ۿ۲��ԣ�������ǣ��������鼮������
	������һ������������ʱ�����ۿۣ����������һ���������������򳬳����ֽ�
	��ԭ������
*/
#include"15.3_Quote.h"

class Limit_quote : public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double p, std::size_t qty, double disc)
		: Quote(book, p), limit_qty(qty), discount(disc)
	{
	}

	virtual double net_price(std::size_t cnt) const override
	{
		if (cnt > limit_qty)
			return (cnt - limit_qty) * price + limit_qty * (1 - discount) * price;
		else
			return cnt * (1 - discount)*price;
	}


private:
	std::size_t limit_qty = 0;    // ��������
	double discount = 0.0;    // �ۿ�
};