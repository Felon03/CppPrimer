/*����8.1���庯�������ò���Ϊcin*/
#include<iostream>
#include<string>	

using namespace std;

istream &read(istream &is)
{
	string buf;
	while (is >> buf)
		cout << buf << endl;
	is.clear();

	return is;
}

int main()
{
	istream &is = read(cin);
	cout << is.rdstate() << endl;
	
	return 0;
}