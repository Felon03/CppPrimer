/*扩展11.2.1节练习中编写孩子姓到名的map，添加一个pair的vector，保存孩子的名和生日*/
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

// pezy@github的方法
// reference: https://github.com/pezy/CppPrimer/blob/master/ch11/ex11_14.cpp
class Families
{
public:
	using Child = pair<string, string>;
	using Children = vector<Child>;
	using Data = map<string, Children>;

	void add(string const &last_name, string const &first_name, string const &birthday)
	{
		_data[last_name].push_back(make_pair(first_name, birthday));
	}

	ostream &print(ostream &os) const
	{
		if (_data.empty()) return os << "No data right now." << endl;

		for (const auto &pair : _data)
		{
			os << pair.first << ":\n";
			for (const auto &child : pair.second)
				os << child.first << " " << child.second << endl;
			os << endl;
		}
		return os;
	}

private:
	Data _data;
};

int main()
{
	map<string, vector<pair<string, string>>> family;
	string lastname, firstname, birth;
	while (cin>>lastname>>firstname>>birth)
	{
		family[lastname].push_back({ firstname, birth });
	}
	for (const auto &pair : family)
	{
		cout << pair.first << ":\n";
		for (const auto &child : pair.second)
			cout << child.first << " " << child.second << endl;
	}

	// pezy@github的方法
	//Families families;
	//string message = "Please enter last name, first name and birthday";
	//cout << message << endl;
	//for (string l, f, b; cin >> l >> f >> b;
	//	families.add(l, f, b));
	//families.print(cout << "Current data: " << endl);


	return 0;
}

