#include<iostream>
#include<string>

struct Sales_data
{
	std::string bookNo;		// 数的编号
	unsigned int units_sold = 0;		// 售出的数量
	double revenue = 0.0;		// 销售额
};
int main()
{
	Sales_data data1, data2;
	double price = 0.0;		//书的单价，用于计算销售收入
	// 读入第一笔交易: ISBN、销售数量、售价
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	// 计算销售收入
	data1.revenue = data1.units_sold*price;
	// 读入第二笔交易
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	// 输出两个Sales_data对象的和
	// 如果ISBN相同
	if (data1.bookNo == data2.bookNo)
	{
		unsigned total_cnt = data1.units_sold + data2.units_sold;
		double total_revenue = data1.revenue + data2.revenue;
		// 输出: ISBN、总销售量、销售额、平均价格
		std::cout << data1.bookNo << " " << total_cnt << " "
			<< total_revenue << " ";
		if (total_cnt != 0)
			std::cout << total_revenue / total_cnt << std::endl;
		else
			std::cout << "(no sales)" << std::endl;
		return 0;		// 表示成功
	}
	else
	{
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;
	}
}