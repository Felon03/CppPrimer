/*如果一个字母延伸到中线之上，如d或f，则称其有上出头部分(ascender)。
如果一个字符延伸到中线之下，如p或g，则称其有下出头部分(descender)。
编写程序，读入一个dancing文件，输入最长的记不包含上出头部分，也不包含下出头部分的单词。
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
			// 妙！word.find_first_not_of("aceimnorsuvwxz") == string::npos表示找不到包含出头的单词！！！
		{
			longest_word = word;
			cout << word << " ";
		}
			
	cout << endl;

	cout << longest_word << endl;
	return 0;
}