#include"13.31.h"
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	HasPtr hp1("Hello World!"), hp2("Hello C++");
	HasPtr hp3("123");
	//hp1.show();
	//hp2.show();
	//hp3.show();

	vector<HasPtr> hpvec{ hp1, hp2, hp3 };
	for (const auto &x : hpvec)
		x.show();
	sort(hpvec.begin(), hpvec.end());
	cout << "after sort operator" << endl;
	for (const auto &x : hpvec)
		x.show();

	return 0;
}