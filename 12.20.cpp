/*��д�������ж���һ�������ļ��������ݴ���һ��StrBlob�У�
	��һ��StrBlobPtr��ӡ���StrBlob�е�ÿ��Ԫ��	
*/
#include"12.19.h"
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
	ifstream ifs("data/test_str.txt");
	StrBlob blob;
	string word;
	while (getline(ifs, word))
		blob.push_back(word);
	//for(string str; getline(ifs, str);) 
	//	blob.push_back(str)
	for (StrBlobPtr p_beg(blob.begin()), p_end(blob.end()); p_beg != p_end; p_beg.incr())
		cout << p_beg.deref() << endl;

	return 0;
}