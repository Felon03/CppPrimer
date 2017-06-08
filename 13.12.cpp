#include"13.11.h"
#include<iostream>

using namespace std;

bool fcn(const HasPtr *trans, HasPtr accum)
{
	HasPtr item1(*trans), item2(accum);
	return true;
}

int main()
{
	const HasPtr *trans = new HasPtr();
	HasPtr accum;
	fcn(trans, accum);
	return 0;
}