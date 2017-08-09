#include<iostream>
using namespace std;

int main3()
{
	cout << "/*" << endl;
	cout << "*/" << endl;
	//cout <</*"*/"*/<<endl;				// 错误
	// 修改为
	cout << "/**/" << endl;
	cout <</*"*/" /*"/*"*/ << endl;
	return 0;
}