#include<iostream>
#include"Sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
	Sales_data data1, data2;
	double price = 0;
	// ����data1����Ϣ
	cin >> data1.bookNo >> data1.units_sold >> price;
	// data1�����۶�
	data1.revenue = data1.units_sold*price;
	// ����data2����Ϣ
	cin >> data2.bookNo >> data2.units_sold >> price;
	// data2�����۶�
	data2.revenue = data2.units_sold*price;

	if (data1.bookNo == data2.bookNo)
	{
		unsigned total_cnt = data1.units_sold + data2.units_sold;
		double total_revenue = data1.revenue + data2.revenue;
		std::cout << data1.bookNo << " " << total_cnt << " " << total_revenue << " ";
		if (total_cnt != 0)
			cout << total_revenue / total_cnt << endl;
		else
			cout << "(no sales)" << endl;
		return 0;		// ��ʾ�ɹ�
	}
	else
	{
		cerr << "Data must refer to the same ISBN" << endl;
		return -1;		// ��ʾʧ��
	}
}