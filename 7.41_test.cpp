/*使用委托构造函数重新编写Sales_data类*/
#include"7.41.h"

using namespace std;

int main()
{
	cout << "1. default way: " << endl;
	cout << "-----------------" << endl;
	Sales_data s1;

	cout << "\n2. use std::string as parameter: " << endl;
	cout << "-----------------" << endl;
	Sales_data s2("Hello world!");

	cout << "\n3. complete parameters: " << endl;
	cout << "-----------------" << endl;
	Sales_data s3("Hello C++", 3, 30);

	cout << "\n4. use istream as parameter: " << endl;
	cout << "-----------------" << endl;
	Sales_data s4(cin);

	return 0;
}

/*
输出结果：

1. default way:
-----------------
Sales_data(const std::string &, unsigned, double)
Sales_data()

2. use std::string as parameter:
-----------------
Sales_data(const std::string &, unsigned, double)
Sales_data(std::string &)

3. complete parameters:
-----------------
Sales_data(const std::string &, unsigned, double)

4. use istream as parameter:
-----------------
Sales_data(const std::string &, unsigned, double)
Sales_data()
Sales_data(std::istream &)

*/