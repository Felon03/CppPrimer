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
	p = &d2;   // Error ���ɷ���
	p = &d3;   // Error ���ɷ���
	p = &dd1;
	p = &dd2;  // Error ���ɷ���
	p = &dd3;  // Error ���ɷ���
}