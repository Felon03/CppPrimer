/*重做上一题，这次使用shared_prt而不是内置指针*/
#include<iostream>
#include<vector>
#include<memory>

using namespace std;

shared_ptr<vector<int>> generate_vector()
{
	return make_shared<vector<int>>();
}

void write_to_vector(shared_ptr<vector<int>> v)
{
	int i;
	cout << "please enter Integer:" << endl;
	while (cin >> i && i != -1) v->push_back(i);
}

void print_vector(shared_ptr<vector<int>> v)
{
	for (const auto &x : *v)
		cout << x << " ";
	cout << endl;
}

int main()
{
	//shared_ptr<vector<int>> v = generate_vector();
	auto v = generate_vector();
	write_to_vector(v);
	print_vector(v);

	return 0;
}