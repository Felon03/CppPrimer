/*使用这些新函数重写7.1.2节联系中的交易处理程序*/
#include"7.6.h"
#include<iostream>

using namespace std;

int main()
{
	Sales_data total;		//保存下一交易记录的变量
	if (read(cin, total))
	{
		Sales_data trans;		// 保存和的变量
		while (read(cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total = add(total, trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}