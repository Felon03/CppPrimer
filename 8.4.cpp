/*��д�������Զ�ģʽ��һ���ļ����������ݶ��뵽һ��string��vector�У�
��ÿ����Ϊһ��������Ԫ�ش���vector��*/
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