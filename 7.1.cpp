/*ʹ��2.6.1����ϰ�����Sales_data��Ϊ1.6�ڵĽ��״�������дһ���°汾*/
#include"Sales_data.h"
#include<iostream>

using namespace std;

int main()
{
	Sales_data total;		// ������һ���׼�¼�ı���
	if (cin >> total.bookNo >> total.revenue >> total.units_sold)
	{
		Sales_data trans;		// ����͵ı���
		// ���벢����ʣ�ཻ�׼�¼
		while (cin >> trans.bookNo >> trans.revenue >> trans.units_sold)
		{
			// ���������ͬ����
			// ʹ��isbn() 7.3
			//if (total.bookNo == trans.bookNo)
			if(total.isbn() == trans.isbn())
			{
				//total.revenue += trans.revenue;
				//total.units_sold += trans.units_sold;
				// ʹ��combine���� 7.3
				total.combine(trans);
			}
			else
			{
				// ��ӡǰһ����Ľ��
				cout << "ISBN: " << total.isbn() << endl << "Revenue: " << total.revenue << endl << "Sold: " << total.units_sold << endl;
				total = trans;
			}
		}
		cout << "ISBN: " << total.isbn() << endl << "Revenue: " << total.revenue << endl << "Sold: " << total.units_sold << endl;	// ��ӡ���һ����Ľ��
	} 
	else
	{
		// û�����룡
		cerr << "No data?!" << endl;
		return -1;
	}

	return 0;
}