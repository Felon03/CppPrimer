#include"12.27.h"
#include<iostream>

void runQueries(std::ifstream &infile)
{
	// infile��һ��ifstream��ָ��Ҫ������ļ�
	TextQuery tq(infile);		// �����ļ���������ѯmap
	while (true)
	{
		std::cout << "Enter word to look for, or q to quit: ";
		string s;
		// �������ļ�β�����û�������q��ѭ����ֹ
		if (!(std::cin >> s) || s == "q") break;
		// ָ���ѯ����ӡ���
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	std::ifstream file("data/story.txt");
	runQueries(file);

	return 0;
}