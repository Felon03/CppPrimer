/*修改之前输出text第一段的程序，首先吧text的第一段全都改成大写形式，然后再输出它*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string text("some string."
		"this is a test string,"
		"if program goes right, "
		"all words will be uppercase.");
	
	for (auto iter = text.begin(); iter != text.end() && *iter != '\n'; ++iter)
	{
		*iter = toupper(*iter);
		cout << *iter;
	}
	cout << endl;

	return 0;
}