/* ִ��runQueries����*/
#include"12.30.h"

using namespace std;

void runQueries(ifstream &infile)
{
	// infile��һ��ifstream,ָ��Ҫ������ļ�
	TextQuery text_query(infile);									// �����ļ���������ѯmap
	// ���û������� ��ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
	do
	{
		cout << "Enter word to look for or q to quit: ";
		string word;
		// �������ļ�β�����û������ˡ�q��ʱѭ����ֹ
		if (!(cin >> word) || word == "q") break;
		// ָ���ѯ����ӡ���
		print(cout, text_query.query(word)) << endl;
	} while (true);
}

int main()
{
	ifstream ifs("data/story.txt");
	runQueries(ifs);

	return 0;
}