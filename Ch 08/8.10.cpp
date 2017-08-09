/*��д���򣬽�����һ���ļ��е��б�����һ��vector<string>�С�
Ȼ��ʹ��һ��istringstream��vector��ȡ����Ԫ�أ�ÿ�ζ�ȡһ�����ʡ�
*/
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
	string line, word;
	vector<string> words;
	ifstream input(argv[1]);
	if (!input)
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	while (getline(input, line))
	{
		istringstream read(line);
		while (read >> word)
			words.push_back(word);
	}

	for (const auto &x : words)
		cout << x << endl;

	return 0;
}