/*ʵ�����Լ��汾�ĵ���ת������*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

using namespace std;
map<string, string> buildMap(ifstream &);
const string &transform(const string &, const map<string, string> &);
void word_transform(ifstream &, ifstream &);

// ͨ��ʹ��ת��������������ת�������ת����Ľ��
void word_transform(ifstream &map_file, ifstream &input)
{
	ofstream output("data/transform_done.txt");
	auto trans_map = buildMap(map_file);			// ����ת������
	string text;																// ���������е�ÿһ��
	while (getline(input, text))								// ��ȡһ������
	{
		istringstream stream(text);							// ��ȡÿ������
		string word;
		bool firtstword = true;
		while (stream>>word)
		{
			if (firtstword)
				firtstword = false;
			else
			{
				cout << " ";													// �ڵ��ʼ��ӡһ���ո�
				output << " ";
			}

			// transform�������ĵ�һ������������ת��֮�����ʽ
			cout << transform(word, trans_map);	// ��ӡ���
			output << transform(word, trans_map);
		}
		cout << endl;
		output << endl;
	}
}

// ����ת������
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;				// ����ת������
	string key, value;											// Ҫת���ĵ��ʺ�ת���������
	// ��ȡ��һ�����ʴ���key�У�����ʣ�����ݴ���value
	while (map_file>>key && getline(map_file, value))
	{
		if (value.size() > 1)		// ����Ƿ���ת������
			trans_map[key] = value.substr(1);		// ����ǰ���ո�
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
	// ʵ�ʵ�ת������
	auto map_it = m.find(s);
	// ���������ת������map��
	if (map_it != m.end())
		return map_it->second;			// ʹ���滻����
	else
		return s;										// ���򷵻�ԭstring
}

int main()
{
	ifstream ifs_map("data/rules.txt"), ifs_content("data/todo.txt");
	if (ifs_map&&ifs_content)
		word_transform(ifs_map, ifs_content);
	else
		cerr << "Can't find the documents." << endl;

	return 0;
}