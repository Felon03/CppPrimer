/*��д7.1.1�ڵ������򣬴�һ���ļ��ж�ȡ���׼�¼�����ļ�����Ϊһ���������ݸ�main*/
#include"Sales_data.h"
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	ifstream input(argv[1]);		// �����ۼ�¼�ļ�
	Sales_data total;
	if (read(input, total))			// ��ȡ��һ�����ۼ�¼
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);			// ��������isbn��֮ǰ��ͬ�����������ܶ�
			else
			{
				print(cout, total) << endl;		// ��ӡ���
				total = trans;				// ������һ����
			}
		}
		print(cout, total) << endl;		// ��ӡ���һ��������۶�
	}
	else
		cerr << "No data?!" << endl;

	return 0;
}