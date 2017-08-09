/*执行代码验证Screen类是否正确*/
#include"7.27.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	//const Screen blank(5, 4);
	//blank.display(cout);
	//cout << "1" << endl;
	Screen myScreen(5, 5, 'X');
	myScreen.display(cout);
	cout << endl;
	myScreen.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen.display(cout);
	cout << endl;

	return 0;
}