/*重写8.4，将每个单词作为一个独立的元素进行存储*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void readFromFile(const string &fileName, vector<string> &vec)
{
	ifstream read(fileName);
	if (read)
	{
		string buf;
		while (read >> buf) vec.push_back(buf);
	}
}

int main()
{
	vector<string> strVec;
	readFromFile("C:/Users/Freed/Desktop/test.txt", strVec);

	for (const auto &str : strVec)
		cout << str << endl;

	return 0;
}