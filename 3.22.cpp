/*�޸�֮ǰ���text��һ�εĳ������Ȱ�text�ĵ�һ��ȫ���ĳɴ�д��ʽ��Ȼ���������*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string text("some string."
		"this is a test string,"
		"if program goes right, "
		"all words will be uppercase.");
	
	for (auto iter = text.begin(); iter != text.end() && *iter != '\n'; ++iter)
	{
		*iter = toupper(*iter);
		cout << *iter;
	}
	cout << endl;

	return 0;
}