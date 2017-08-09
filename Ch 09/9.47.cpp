/*编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字符，然后查找其中每个字母字符。
编写两个版本，第一个要使用find_first_of,第二个要使用find_first_not_of
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name("ab2c3d7R4e6");
	string numbers("0123456789");
	string aplhabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

	// version 1 use find_first_of
	string::size_type pos = 0;
	cout << "use find_frist_of() function:" << endl;
	while ((pos = name.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "name[" << pos << "] = " << name[pos] << " ";
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = name.find_first_of(aplhabet, pos)) != string::npos)
	{
		cout << "name[" << pos << "] = " << name[pos] << " ";
		++pos;
	}
	cout << endl;

	// version 2 use find_first_not_of
	cout << "use find_first_not_of() function:" << endl;
	pos = 0;
	while ((pos = name.find_first_not_of(aplhabet, pos)) != string::npos)
	{
		cout << "name[" << pos << "] = " << name[pos] << " ";
		++pos;
	}
	cout << endl;
	pos = 0;
	while ((pos = name.find_first_not_of(numbers, pos)) != string::npos)
	{
		cout << "name[" << pos << "] = " << name[pos] << " ";
		++pos;
	}
	cout << endl;

	return 0;
}