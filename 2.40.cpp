#include<iostream>
#include<string>

struct Sales_data
{
	std::string bookNo;		// ���ı��
	unsigned int units_sold = 0;		// �۳�������
	double revenue = 0.0;		// ���۶�
};
int main()
{
	Sales_data data1, data2;
	double price = 0.0;		//��ĵ��ۣ����ڼ�����������
	// �����һ�ʽ���: ISBN�������������ۼ�
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	// ������������
	data1.revenue = data1.units_sold*price;
	// ����ڶ��ʽ���
	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	// �������Sales_data����ĺ�
	// ���ISBN��ͬ
	if (data1.bookNo == data2.bookNo)
	{
		unsigned total_cnt = data1.units_sold + data2.units_sold;
		double total_revenue = data1.revenue + data2.revenue;
		// ���: ISBN���������������۶ƽ���۸�
		std::cout << data1.bookNo << " " << total_cnt << " "
			<< total_revenue << " ";
		if (total_cnt != 0)
			std::cout << total_revenue / total_cnt << std::endl;
		else
			std::cout << "(no sales)" << std::endl;
		return 0;		// ��ʾ�ɹ�
	}
	else
	{
		std::cerr << "Data must refer to the same ISBN" << std::endl;
		return -1;
	}
}