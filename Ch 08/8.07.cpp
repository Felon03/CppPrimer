/*�޸�8.6�������򣬽�������浽һ���ļ��С�������ļ�����Ϊ�ڶ����������ݸ�main����*/
#include"Sales_data.h"
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		//ofstream out;
		//out.open(argv[2], ofstream::app);
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