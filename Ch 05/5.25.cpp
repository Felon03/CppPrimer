/*修改程序，使用try语句块去捕获异常。catch子句应该为用户输出一条提示信息，询问其是否输入新数并重新执行try语句块的内容*/
#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
	int a, b;
	cout << "Enter two integers: " << endl;
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0) throw runtime_error("Divisor is 0.");
			cout << static_cast<double>(a) / b << endl;
			cout << "Enter two integers: ";
		}
		catch (runtime_error err)
		{
			cout << err.what();
			cerr << "\nTry Again? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
			cout << "Enter tow integers: " << endl;
		}
	}

	return 0;
}