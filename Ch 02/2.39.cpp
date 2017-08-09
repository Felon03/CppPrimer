#include<iostream>

using namespace std;

struct Foo {/*此处为空*/ };
/*
如果没有在花括号后面加上';',会出现以下错误:
错误(活动)		应输入“;”
错误	C2628	“Foo”后面接“int”是非法的(是否忘记了“;”?)
错误	C3874	“main”的返回类型应为“int”而非“Foo”	CppPrimer
错误	C2440	“return”: 无法从“int”转换为“Foo”	CppPrimer
*/
int main()
{
	return 0;
}