/*��д��ΪcompareIsbn�ĺ������Ƚ�����Sales_data�����isbn()��Ա��
	ʹ�������������һ������Sales_data�����vector
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
	return sd1.isbn().size() < sd2.isbn().size();
}

int main()
{
	Sales_data d1("123"), d2("12"), d3("1234"), d4("543"), d5("12345");
	vector<Sales_data> sd{ d1,d2,d3,d4,d5 };
	sort(sd.begin(), sd.end(), compareIsbn);
	for (const auto &x : sd)
		cout << x.isbn() << " ";
	cout << endl;

	return 0;
}