#include"13.42_Query.h"

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "Enter word to look for or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream file("data/story.txt");
	runQueries(file);
}