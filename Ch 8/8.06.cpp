/*重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给main*/
#include"Sales_data.h"
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream input(argv[1]);		// 打开销售记录文件
	Sales_data total;
	if (read(input, total))			// 读取第一条销售记录
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);			// 如果读入的isbn与之前相同，更新销售总额
			else
			{
				print(cout, total) << endl;		// 打印结果
				total = trans;				// 处理下一本书
			}
		}
		print(cout, total) << endl;		// 打印最后一本书的销售额
	}
	else
		cerr << "No data?!" << endl;

	return 0;
}