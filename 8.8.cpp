/*修改8.7的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，验证数据是否得以保留*/
#include"Sales_data.h"
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
	Sales_data total;
	ifstream input(argv[1]);
	ofstream output(argv[2], ofstream::app);
	if (read(input, total))
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else
		cerr << "No data?!" << endl;

	return 0;
}