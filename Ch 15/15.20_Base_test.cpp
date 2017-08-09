#include"15.20_Base.h"
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;

	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected dd3;

	Base *p = &d1;
	p = &d2;   // Error 不可访问
	p = &d3;   // Error 不可访问
	p = &dd1;
	p = &dd2;  // Error 不可访问
	p = &dd3;  // Error 不可访问
}