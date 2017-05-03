/*�޸�8.7�ĳ��򣬽����׷�ӵ��������ļ�ĩβ����ͬһ������ļ������г����������Σ���֤�����Ƿ���Ա���*/
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