/*���һ����ĸ���쵽����֮�ϣ���d��f����������ϳ�ͷ����(ascender)��
���һ���ַ����쵽����֮�£���p��g����������³�ͷ����(descender)��
��д���򣬶���һ��dancing�ļ���������ļǲ������ϳ�ͷ���֣�Ҳ�������³�ͷ���ֵĵ��ʡ�
*/
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	fstream ifs("C:/Users/Freed/Desktop/letter.txt");
	if (!ifs) return -1;
	string longest_word;
	for (string word; ifs >> word;)
		if (word.find_first_not_of("aceimnorsuvwxz") == string::npos && word.size() > longest_word.size())
			// �word.find_first_not_of("aceimnorsuvwxz") == string::npos��ʾ�Ҳ���������ͷ�ĵ��ʣ�����
		{
			longest_word = word;
			cout << word << " ";
		}
			
	cout << endl;

	cout << longest_word << endl;
	return 0;
}