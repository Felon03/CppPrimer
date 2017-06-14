#include"13.30.h"

using namespace std;

int main()
{
	HasPtr hp1("helloworld"), hp2("helloc++");
	hp1.show();
	hp2.show();
	swap(hp1, hp2);
	hp1.show();
	hp2.show();
	return 0;
}