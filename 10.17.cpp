/*��д10.12�ĳ����ڶ�sort�ĵ�����ʹ��lambda�����溯��compareIsbn*/
#include"Sales_data.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	Sales_data d1("123"), d2("12"), d3("222"), d4("2134"), d5("12345");
	vector<Sales_data> sd{ d1,d2,d3,d4,d5 };
	sort(sd.begin(), sd.end(),
		[](const Sales_data &sd1, const Sales_data &sd2) {return sd1.isbn().size() < sd2.isbn().size(); });
	for (const auto &s : sd)
		cout << s.isbn() << " ";
	cout << endl;

	return 0;
}