/*编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，
将每行作为一个独立的元素存于vector中*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void read(const string &filename, vector<string> &vec)
{
	ifstream in(filename);
	if (in)
	{
		string buf;
		while (getline(in, buf)) vec.push_back(buf);
	}
}

int main()
{
	vector<string> strVec;
	read("C:/Users/Freed/Desktop/test.txt", strVec);
	for (const auto &str : strVec)
		cout << str << endl;

	return 0;
}