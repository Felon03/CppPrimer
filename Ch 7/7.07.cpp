/*ʹ����Щ�º�����д7.1.2����ϵ�еĽ��״������*/
#include"7.6.h"
#include<iostream>

using namespace std;

int main()
{
	Sales_data total;		//������һ���׼�¼�ı���
	if (read(cin, total))
	{
		Sales_data trans;		// ����͵ı���
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