/*使用2.6.1节练习定义的Sales_data类为1.6节的交易处理程序编写一个新版本*/
#include"Sales_data.h"
#include<iostream>

using namespace std;

int main()
{
	Sales_data total;		// 保存下一交易记录的变量
	if (cin >> total.bookNo >> total.revenue >> total.units_sold)
	{
		Sales_data trans;		// 保存和的变量
		// 读入并处理剩余交易记录
		while (cin >> trans.bookNo >> trans.revenue >> trans.units_sold)
		{
			// 如果处理相同的书
			// 使用isbn() 7.3
			//if (total.bookNo == trans.bookNo)
			if(total.isbn() == trans.isbn())
			{
				//total.revenue += trans.revenue;
				//total.units_sold += trans.units_sold;
				// 使用combine函数 7.3
				total.combine(trans);
			}
			else
			{
				// 打印前一本书的结果
				cout << "ISBN: " << total.isbn() << endl << "Revenue: " << total.revenue << endl << "Sold: " << total.units_sold << endl;
				total = trans;
			}
		}
		cout << "ISBN: " << total.isbn() << endl << "Revenue: " << total.revenue << endl << "Sold: " << total.units_sold << endl;	// 打印最后一本书的结果
	} 
	else
	{
		// 没有输入！
		cerr << "No data?!" << endl;
		return -1;
	}

	return 0;
}